#pragma once 

#include "Core.h"
#include "Events/Events.h"

namespace Lazel {
    class LAZEL_API Layer
    {
    public:
        Layer(std::string name);
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) {}
        
        inline const std::string& GetName() const { return m_DebugName; }
    
    protected:
        std::string m_DebugName;

    };
}