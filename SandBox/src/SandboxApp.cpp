#include "Lazel.h"

class ExampleLayer : public Lazel::Layer
{
public:
    ExampleLayer() 
        : Layer("ExampleLayer")
    {  };

    void OnUpdate() override {
        LZ_INFO("ExampleLayer Update!");
    }

    void OnEvent(Lazel::Event& e) override {
        LZ_INFO("ExampleLayer Event {0}!", e);
    }

};


class Sandbox : public Lazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }

};

Lazel::Application* Lazel::CreateApplication()
{
    return new Sandbox();
}