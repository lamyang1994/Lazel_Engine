#pragma once

extern Lazel::Application* Lazel::CreateApplication();

int main()
{
    Lazel::Log::Init();

    LZ_CORE_WARN("Lazel Logging System!");
    int count = 0;
    LZ_CLIENT_INFO("Lazel Engine's Entry Point {0}!", count);
    auto app = Lazel::CreateApplication();
    app->Run();
    delete app;
}