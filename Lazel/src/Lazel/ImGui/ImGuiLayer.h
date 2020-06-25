#pragma once

#include "Lazel/Layer.h"
#include "Lazel/Events/ApplicationEvent.h"
#include "Lazel/Events/KeyEvent.h"
#include "Lazel/Events/MouseEvent.h"

namespace Lazel {
    class LAZEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;
        void Begin();
        void End();
        
    private:
        float m_Time;
    };
}
