#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace Hazel {
	class HAZEL_API Application{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//应该在客户端内定义
	Application* CreateApplication();
}

