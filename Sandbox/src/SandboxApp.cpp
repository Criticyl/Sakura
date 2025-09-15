#include "Sakura.h"

class Sandbox : public Sakura::Application
{
public:
    Sandbox()
    {
        std::cout << "Sandbox Application created!" << std::endl;
    }

    ~Sandbox()
    {
        std::cout << "Sandbox Application destroyed!" << std::endl;
    }
};

Sakura::Application* Sakura::CreateApplication()
{
    return new Sandbox();
}