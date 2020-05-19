#include "Lazel/Application.h"
#include "Lazel/Log.h"
#include "Events/KeyEvent.h"

namespace Lazel{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        KeyPressedEvent e(0, 1);
        LZ_TRACE(e);
        while(true);
    }

}