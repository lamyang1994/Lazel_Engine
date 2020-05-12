#include "Lazel/Application.h"
#include "Lazel/Log.h"

namespace Lazel{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        Lazel::Log::GetClientLogger()->error("Hazel App is Runing...");
        while(true);
    }

}