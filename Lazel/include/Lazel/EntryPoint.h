#pragma once

extern Lazel::Application* Lazel::CreateApplication();

int main()
{
    Lazel::Log::Init();
    Lazel::Log::GetCoreLogger()->warn("Lazel Logging System!");
    Lazel::Log::GetClientLogger()->info("Lazel Engine's Entry Point!");
    auto app = Lazel::CreateApplication();
    app->Run();
    delete app;
}