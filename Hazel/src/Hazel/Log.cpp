#include "Log.h"


namespace Hazel {

	//��̬���Ա����������������г�ʼ��
	//��̬����������ֻ��һ�α���ʼ��
	//��̬������ʼ��ʱ����Я������
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
