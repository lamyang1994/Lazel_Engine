#pragma once

#include "lzpch.hpp"

#include "Events/Events.h"
#include "Core.h"
#include "GLFW/glfw3.h"

namespace Lazel {
    
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Lazel Window", 
            unsigned int width = 1280, 
            unsigned int height = 720)
            : Title(title), Width(width), Height(height)
            {}

    };
    
    // Interfaces representing a destop system based Window
    class LAZEL_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual GLFWwindow* GetInstance() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        // Vertical synchronization
        virtual void SetVSync(bool enable) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());

    };


}