#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Lazel/LayerStack.h"

namespace Lazel {

    class LAZEL_API Application 
    {
    public:
        Application();
        virtual ~Application();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void OnEvent(Event& e);
        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        bool m_Runing = true;

        bool OnWindowClose(WindowCloseEvent& e);
    };   

    // To be Defined by Clients
    Application* CreateApplication();
}