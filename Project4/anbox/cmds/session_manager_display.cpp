#include "session_manager_display.h"
#include "anbox/application/launcher_storage.h"
#include "anbox/application/database.h"
//#include "anbox/audio/server.h"
//#include "anbox/bridge/android_api_stub.h"/*
//#include "anbox/bridge/platform_api_skeleton.h"
//#include "anbox/bridge/platform_message_processor.h"
#include "anbox/graphics/gl_renderer_server.h"
#include <sstream>
//#include "anbox/cmds/session_manager.h"
#include "anbox/common/dispatcher.h"
#include "anbox/system_configuration.h"
//#include "anbox/container/client.h"
//#include "anbox/dbus/bus.h"
//#include "anbox/dbus/skeleton/service.h"
#include "anbox/input/manager.h"
#include "anbox/logger.h"
//#include "anbox/network/published_socket_connector.h"
#include "anbox/network/tcp_socket_connector.h"
#include "anbox/qemu/pipe_connection_creator.h"
//#include "anbox/rpc/channel.h"
//#include "anbox/rpc/connection_creator.h"
#include "anbox/runtime.h"
#include "anbox/platform/base_platform.h"
#include "anbox/wm/multi_window_manager.h"
#include "anbox/wm/single_window_manager.h"
#include "windows.h"
//#include "external/xdg/xdg.h"
#include <boost/asio.hpp>
#include <SDL2\SDL.h>
//anbox::cmds::SessionManagerDisplay() {
//
//}
namespace {
	const anbox::graphics::Rect default_single_window_size{ 0, 0, 1024, 768 };
}

anbox::cmds::SessionManagerDisplay::SessionManagerDisplay()
{
}

void anbox::cmds::SessionManagerDisplay::launch_display() {
	auto rt = Runtime::create();
	auto dispatcher = anbox::common::create_dispatcher_for_runtime(rt);
	auto display_frame = default_single_window_size;
	platform::Configuration platform_config;
	platform_config.single_window = true;
	platform_config.no_touch_emulation = true;
	platform_config.display_frame = display_frame;
	auto input_manager = std::make_shared<input::Manager>(rt);
	auto platform = platform::create(utils::get_env_value("ANBOX_PLATFORM", "sdl"),
		input_manager,
		platform_config);
	if (!platform) {
		WARNING("%s", "Error: No platform");
		return;
	}

	auto app_db = std::make_shared<application::Database>();
	std::shared_ptr<wm::Manager> window_manager; 
	window_manager = std::make_shared<wm::SingleWindowManager>(platform, display_frame, app_db);
	bool using_single_window = true;
	//auto gl_driver = graphics::GLRendererServer::Config::Driver::Host;
	auto gl_driver = graphics::GLRendererServer::Config::Driver::Software;
	graphics::GLRendererServer::Config renderer_config{
	  gl_driver,
	  true // single_window
	};
	auto gl_server = std::make_shared<graphics::GLRendererServer>(renderer_config, window_manager);
	platform->set_window_manager(window_manager);
	platform->set_renderer(gl_server->renderer());
	window_manager->setup();
	const auto qemu_port = SystemConfiguration::instance().qemu_port();
	const auto anbox_bridge_port = SystemConfiguration::instance().anbox_bridge_port();
	const auto session_manager_ip_address = boost::asio::ip::address_v4::from_string(
		SystemConfiguration::instance().session_manager_ip_address());
	auto qemu_pipe_connector = std::make_shared<network::TcpSocketConnector>(session_manager_ip_address, qemu_port, rt,
		std::make_shared<qemu::PipeConnectionCreator>(gl_server->renderer(), rt));
	rt->start();
	bool quit = true;
	SDL_Event event;
	while (quit) {
		SDL_WaitEvent(&event);
		switch (event.type) {

		case SDL_MOUSEBUTTONUP:
			/*SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 100, 0xFF));
			SDL_UpdateWindowSurface(window);*/
			break;
		case SDL_QUIT:
			//SDL_Log("quit");
			quit = 0;
			break;
		default:
			quit = 1;
			//SDL_Log("event type:%d", event.type);
		}
	}
}
