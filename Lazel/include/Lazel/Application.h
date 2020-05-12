#pragma once

#include "Core.h"

namespace Lazel {
    class LAZEL_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();

    };   

    // To be Defined by Clients
    Application* CreateApplication();
}