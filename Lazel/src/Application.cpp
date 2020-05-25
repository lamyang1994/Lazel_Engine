#include "lzpch.hpp"
#include "Lazel/Application.h"
#include <GLFW/glfw3.h>

namespace Lazel{
    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        // std::bind here is used to reduce parameters number of OnEvent into 1
        // from "void(this, Event&) -> "void(Event&)" 
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        LZ_CORE_TRACE("OnEvent {0}", e);
        EventDispatcher dispatcher(e);
        dispatcher.DisPatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
    }

    void Application::Run()
    {
        while(m_Runing)
        {
            glClearColor(1., 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Runing = false;
        return true;
    }

}