#pragma once

extern Lazel::Application* Lazel::CreateApplication();

int main()
{
    Lazel::Log::Init();

    LZ_CORE_INFO("Init Logging System!");
    auto app = Lazel::CreateApplication();
    app->Run();
    delete app;
}