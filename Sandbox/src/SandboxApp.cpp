#include "Sakura.h"

class Sandbox : public Sakura::Application
{
public:
    Sandbox(const Sakura::ApplicationProperties& appProperties)
        : Sakura::Application(appProperties)
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
    Sakura::ApplicationProperties props;
    return new Sandbox(props);
}