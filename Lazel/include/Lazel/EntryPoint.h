#pragma once

extern Lazel::Application* Lazel::CreateApplication();

int main()
{
    std::cout << "Lazel Engine's Entry Point!\n" ;
    auto app = Lazel::CreateApplication();
    app->Run();
    delete app;
}