#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Lazel/LayerStack.h"
#include "Lazel/ImGui/ImGuiLayer.h"

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

        inline Window& GetWindow() { return *m_Window; };
        inline static Application& Get() { return *s_instance; };

    private:
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        LayerStack m_LayerStack;
        bool m_Runing = true;
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        static Application* s_instance;
    };   

    // To be Defined by Clients
    Application* CreateApplication();
}