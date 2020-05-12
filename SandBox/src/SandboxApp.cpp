#include "Lazel.h"

class Sandbox : public Lazel::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }

};

Lazel::Application* Lazel::CreateApplication()
{
    return new Sandbox();
}