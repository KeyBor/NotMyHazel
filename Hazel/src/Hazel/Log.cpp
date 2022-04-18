#include "Log.h"


namespace Hazel {

	//静态类成员变量必须在类外进行初始化
	//静态变量必须且只能一次被初始化
	//静态变量初始化时必须携带类型
	std::shared_ptr<spdlog::logger> Log::s_Clientlogger;
	std::shared_ptr<spdlog::logger> Log::s_Corelogger;

	Log::Log() {

	}

	Log::~Log() {

	}


	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Corelogger = spdlog::stderr_color_mt("Hazel");
		s_Corelogger->set_level(spdlog::level::trace);

		s_Clientlogger = spdlog::stderr_color_mt("App");
		s_Clientlogger->set_level(spdlog::level::trace);

	}

}
