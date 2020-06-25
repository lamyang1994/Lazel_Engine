#pragma once

#include "Events.h"

namespace Lazel {
    /*--------------------------------*/
    class LAZEL_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)  { }

        inline float GetWidth() const { return m_Width; }
        inline float GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << m_Width << " x " << m_Height << ")"; 
            return ss.str();
        }        
        
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        
    private:
        unsigned int m_Width, m_Height;
    };

    /*--------------------------------*/
    class LAZEL_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() { } 
        
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    /*--------------------------------*/
    class LAZEL_API AppTickEvent : public Event
    {
    public:
    	AppTickEvent() {}

    	EVENT_CLASS_TYPE(AppTick)
    	EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    /*--------------------------------*/
    class LAZEL_API AppUpdateEvent : public Event
    {
    public:
    	AppUpdateEvent() {}

    	EVENT_CLASS_TYPE(AppUpdate)
    	EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    /*--------------------------------*/
    class LAZEL_API AppRenderEvent : public Event
    {
    public:
    	AppRenderEvent() {}

    	EVENT_CLASS_TYPE(AppRender)
    	EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
}