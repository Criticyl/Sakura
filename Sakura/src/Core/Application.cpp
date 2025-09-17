#include "Application.h"

namespace Sakura {

    Application::Application()
    {
        Init();
    }

    Application::~Application()
    {
        Shutdown();
    }

    void Application::Init()
    {
        Sakura::WindowProperties props;
        m_Window = std::make_unique<Window>(props);
    }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(m_Window->GetWindow()))
        {
            glfwPollEvents();
        }
    }

    void Application::Shutdown()
    {

    }

}