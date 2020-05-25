#include "lzpch.hpp"
#include "MacWindow.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Lazel {
    static bool s_GLFWInitialized = false;
    static void GLFWErrorCallback(int error, const char* description)
    {
        LZ_CORE_ERROR("GLFW ERROR ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new MacWindow(props);
    }

    MacWindow::MacWindow(const WindowProps& props)
    {
        Init(props);
    }

    MacWindow::~MacWindow()
    {
        Shutdown();
    }

    void MacWindow::OnUpdate() {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

    unsigned int MacWindow::GetWidth() const
    {
        return m_Data.Width;
    }

    unsigned int MacWindow::GetHeight() const
    {
        return m_Data.Height;
    }

    void MacWindow::SetVSync(bool enable) {
        if (enable)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        m_Data.VSync = enable;
    }

    bool MacWindow::IsVSync() const {
        return m_Data.VSync;
    }
    
    void MacWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        LZ_CORE_INFO("Creating Window: {0} {1} {2}", m_Data.Title, m_Data.Width, m_Data.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            LZ_CORE_ASSERT(success, "Failed to Initialize GLFW!")
            s_GLFWInitialized = true;
            glfwSetErrorCallback(GLFWErrorCallback);
        }
        
        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW Callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });
        
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case (GLFW_PRESS):
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case (GLFW_RELEASE):
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case (GLFW_REPEAT):
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case (GLFW_PRESS):
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case (GLFW_RELEASE):
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double x_offset, double y_offset){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)x_offset, (float)y_offset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x_pos, double y_pos){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)x_pos, (float)y_pos);
            data.EventCallback(event);
        });
    }

    void MacWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
}