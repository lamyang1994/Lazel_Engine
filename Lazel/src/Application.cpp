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
        LZ_CLIENT_INFO("Lazel App is Runing...");
        while(true);
    }

}