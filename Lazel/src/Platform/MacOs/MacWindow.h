#pragma once

#include "Lazel/Window.h"
#include "GLFW/glfw3.h"

namespace Lazel {
    class MacWindow : public Window
    {
    public:
        MacWindow(const WindowProps& props);
        virtual ~MacWindow();
                
        void OnUpdate() override;

        unsigned int GetWidth() const override;
        unsigned int GetHeight() const override;

        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };

        void SetVSync(bool enable) override;
        bool IsVSync() const override;
    
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}
