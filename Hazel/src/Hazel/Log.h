#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
namespace Hazel{
	class HAZEL_API Log
	{
	public:
		Log();
		~Log();
		int a;
		static void Init();
		friend inline static std::shared_ptr<spdlog::logger>& GetClientlogger() { return s_Clientlogger; };
		inline static std::shared_ptr<spdlog::logger>& GetCorelogger() {return s_Corelogger;}
		
	private:
		//私有变量不可类外访问
		//可以由定义友元函数访问，但是友元函数不属于成员函数
		static std::shared_ptr<spdlog::logger> s_Clientlogger;
		static std::shared_ptr<spdlog::logger> s_Corelogger;
		

	};

}

//Core log macros
#define HZ_CORE_ERROR(...)		Hazel::Log::GetCorelogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)		Hazel::Log::GetCorelogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)		Hazel::Log::GetCorelogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...)		Hazel::Log::GetCorelogger()->trace(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		Hazel::Log::GetCorelogger()->fatal(__VA_ARGS__)


//Client log macros
#define HZ_ERROR(...)		Hazel::Log::GetClientlogger()->error(__VA_ARGS__)
#define HZ_WARN(...)		Hazel::Log::GetClientlogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)		Hazel::Log::GetClientlogger()->info(__VA_ARGS__)
#define HZ_TRACE(...)		Hazel::Log::GetClientlogger()->trace(__VA_ARGS__)
#define HZ_FATAL(...)		Hazel::Log::GetClientlogger()->fatal(__VA_ARGS__)

