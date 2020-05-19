#pragma once

#include "Events.h"

namespace Lazel {

    class LAZEL_API KeyEvent : public Event 
    {
    public:
        inline int GetKeyCode() { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        int m_KeyCode;

        KeyEvent(int keycode)
            : m_KeyCode(keycode) { }

    };

    class LAZEL_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeadCount(repeatCount) { }
        
        EVENT_CLASS_TYPE(KeyPressed)

        std::string ToString() const override
        { 
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (RepeatCount: " << m_RepeadCount << ")";
            return ss.str(); 
        }

    private:
        int m_RepeadCount;
    };

    class LAZEL_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) { }
        
        EVENT_CLASS_TYPE(KeyReleased)

        std::string ToString() const override
        { 
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str(); 
        }
    };
}