#pragma once

extern Lazel::Application* Lazel::CreateApplication();

int main()
{
    Lazel::Log::Init();

    LZ_CORE_DEBUG("Init Logging System!");
    int count = 0;
    LZ_INFO("Lazel Engine's Entry Point {0}!", count);
    auto app = Lazel::CreateApplication();
    app->Run();
    delete app;
}