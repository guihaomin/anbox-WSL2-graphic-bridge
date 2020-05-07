/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "anbox/input/device.h"
#include "anbox/logger.h"
#include "anbox/network/delegate_connection_creator.h"
#include "anbox/network/delegate_message_processor.h"
#include "anbox/network/tcp_socket_messenger.h"
#include "anbox/network/tcp_socket_connector.h"
#include "anbox/qemu/null_message_processor.h"

#include <time.h>

namespace anbox {
namespace input {
std::shared_ptr<Device> Device::create(
    const std::string &path, const std::shared_ptr<Runtime> &runtime) {
  auto sp = std::make_shared<Device>();

  auto delegate_connector = std::make_shared<
      network::DelegateConnectionCreator<boost::asio::ip::tcp>>(
      [sp](std::shared_ptr<boost::asio::ip::tcp::socket> const
               &socket) { sp->new_client(socket); });
  unsigned short port = 1234; //this will not be ran, for later construction
  sp->connector_ = std::make_shared<network::TcpSocketConnector>(
      boost::asio::ip::address_v4::from_string(path), port, runtime, delegate_connector);

  return sp;
}

Device::Device()
    : next_connection_id_(0),
      connections_(
          std::make_shared<network::Connections<network::SocketConnection>>()) {
  ::memset(&info_, 0, sizeof(info_));
}

Device::~Device() {}
LARGE_INTEGER
getFILETIMEoffset()
{
    SYSTEMTIME s;
    FILETIME f;
    LARGE_INTEGER t;

    s.wYear = 1970;
    s.wMonth = 1;
    s.wDay = 1;
    s.wHour = 0;
    s.wMinute = 0;
    s.wSecond = 0;
    s.wMilliseconds = 0;
    SystemTimeToFileTime(&s, &f);
    t.QuadPart = f.dwHighDateTime;
    t.QuadPart <<= 32;
    t.QuadPart |= f.dwLowDateTime;
    return (t);
}

int
clock_gettime(int X, struct timespec* tv)
{
    LARGE_INTEGER           t;
    FILETIME            f;
    double                  microseconds;
    static LARGE_INTEGER    offset;
    static double           frequencyToMicroseconds;
    static int              initialized = 0;
    static BOOL             usePerformanceCounter = 0;

    if (!initialized) {
        LARGE_INTEGER performanceFrequency;
        initialized = 1;
        usePerformanceCounter = QueryPerformanceFrequency(&performanceFrequency);
        if (usePerformanceCounter) {
            QueryPerformanceCounter(&offset);
            frequencyToMicroseconds = (double)performanceFrequency.QuadPart / 1000000.;
        }
        else {
            offset = getFILETIMEoffset();
            frequencyToMicroseconds = 10.;
        }
    }
    if (usePerformanceCounter) QueryPerformanceCounter(&t);
    else {
        GetSystemTimeAsFileTime(&f);
        t.QuadPart = f.dwHighDateTime;
        t.QuadPart <<= 32;
        t.QuadPart |= f.dwLowDateTime;
    }

    t.QuadPart -= offset.QuadPart;
    microseconds = (double)t.QuadPart / frequencyToMicroseconds;
    t.QuadPart = microseconds;
    tv->tv_sec = t.QuadPart / 1000000;
    tv->tv_nsec = t.QuadPart % 1000000;
    return (0);
}
void Device::send_events(const std::vector<Event> &events) {
  struct CompatEvent {
    // NOTE: A bit dirty but as we're running currently a 64 bit container
    // struct input_event has a different size. We rebuild the struct here
    // to reach the correct size.
    std::uint64_t sec;
    std::uint64_t usec;
    std::uint16_t type;
    std::uint16_t code;
    std::uint32_t value;
  };

  struct timespec spec;
  clock_gettime(1, &spec);

  auto data = new CompatEvent[events.size()];
  int n = 0;
  for (const auto &event : events) {
    data[n].sec = spec.tv_sec;
    data[n].usec = spec.tv_nsec / 1000;
    data[n].type = event.type;
    data[n].code = event.code;
    data[n].value = event.value;
    n++;
  }

  for (unsigned n = 0; n < connections_->size(); n++) {
    connections_->at(n)->send(reinterpret_cast<const char *>(data),
                              events.size() * sizeof(struct CompatEvent));
  }
}

void Device::set_name(const std::string &name) {
  snprintf(info_.name, 80, "%s", name.c_str());
}

void Device::set_driver_version(const int &version) {
  info_.driver_version = version;
}

void Device::set_input_id(const struct input_id &id) {
  info_.id.bustype = id.bustype;
  info_.id.product = id.product;
  info_.id.vendor = id.vendor;
  info_.id.version = id.version;
}

void Device::set_physical_location(const std::string &physical_location) {
  snprintf(info_.physical_location, 80, "%s", physical_location.c_str());
}

void Device::set_key_bit(const std::uint64_t &bit) {
  set_bit(info_.key_bitmask, bit);
}

void Device::set_abs_bit(const std::uint64_t &bit) {
  set_bit(info_.abs_bitmask, bit);
}

void Device::set_rel_bit(const std::uint64_t &bit) {
  set_bit(info_.rel_bitmask, bit);
}

void Device::set_sw_bit(const std::uint64_t &bit) {
  set_bit(info_.sw_bitmask, bit);
}

void Device::set_led_bit(const std::uint64_t &bit) {
  set_bit(info_.led_bitmask, bit);
}

void Device::set_ff_bit(const std::uint64_t &bit) {
  set_bit(info_.ff_bitmask, bit);
}

void Device::set_prop_bit(const std::uint64_t &bit) {
  set_bit(info_.prop_bitmask, bit);
}

void Device::set_abs_min(const std::uint64_t &bit, const std::uint32_t &value) {
  info_.abs_min[bit] = value;
}

void Device::set_abs_max(const std::uint64_t &bit, const std::uint32_t &value) {
  info_.abs_max[bit] = value;
}

void Device::set_bit(std::uint8_t *array, const std::uint64_t &bit) {
  array[bit / 8] |= (1 << (bit % 8));
}

void Device::set_unique_id(const std::string &unique_id) {
  snprintf(info_.unique_id, 80, "%s", unique_id.c_str());
}

//std::string Device::socket_path() const { return connector_->socket_file(); }
std::string Device::socket_path() const { return ""; }
int Device::next_id() { return next_connection_id_++; }

void Device::new_client(
    std::shared_ptr<boost::asio::ip::tcp::socket> const
        &socket) {
  auto const messenger =
      std::make_shared<network::TcpSocketMessenger>(socket);
  auto const &connection = std::make_shared<network::SocketConnection>(
      messenger, messenger, next_id(), connections_,
      std::make_shared<qemu::NullMessageProcessor>());
  connection->set_name("input-device");
  connections_->add(connection);

  // Send all necessary information about our device so that the remote
  // side can properly configure itself for this input device
  connection->send(reinterpret_cast<char const *>(&info_), sizeof(info_));
}
}  // namespace input
}  // namespace anbox
