#pragma once
#include "Events.h"

namespace Lazel {
    class LAZEL_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float posx, float posy)
            :m_PosX(posx), m_PosY(posy) { }

        inline float GetX() const { return m_PosX; }
        inline float GetY() const { return m_PosY; }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: (x, y) = (" << m_PosX << ", " << m_PosY << ")";
            return ss.str(); 
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        EVENT_CLASS_TYPE(MouseMoved)

    private:
        float m_PosX, m_PosY;
    };

    class LAZEL_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            :m_XOffset(xOffset), m_YOffset(yOffset) { }

        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: (x, y) = (" << m_XOffset << ", " << m_YOffset << ")";
            return ss.str(); 
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        EVENT_CLASS_TYPE(MouseScrolled)
    
    private:
        float m_XOffset, m_YOffset;
    };

    class LAZEL_API MouseButtonEvent : public Event 
    {
    public:
        inline int GetButton() { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        int m_Button;

        MouseButtonEvent(int button)
            : m_Button(button) { }
    };

    class LAZEL_API MouseButtonPressedEvent : public MouseButtonEvent 
    {
    public:
        MouseButtonPressedEvent(int button, int repeatCount)
            : MouseButtonEvent(button), m_RepeatCount(repeatCount) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button << " (repeat: " << m_RepeatCount << ")";
            return ss.str(); 
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)

    private:
        int m_RepeatCount;

    };
    
    class LAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent 
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str(); 
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)

    };

}