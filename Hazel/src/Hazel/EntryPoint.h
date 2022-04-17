#pragma once

#ifdef HZ_PALTFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc,char **argv) {
	printf("Welcome to Hazel Engine!");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif
