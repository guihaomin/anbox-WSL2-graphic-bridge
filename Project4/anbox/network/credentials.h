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

#ifndef ANBOX_NETWORK_CREDENTIALS_H_
#define ANBOX_NETWORK_CREDENTIALS_H_

#include <sys/types.h>
typedef unsigned long    pid_t;
namespace anbox {
namespace network {
class Credentials {
 public:
  Credentials(pid_t pid);

  pid_t pid() const;

 private:
  Credentials() = delete;

  pid_t pid_;
};
}  // namespace network
}  // namespace anbox

#endif
