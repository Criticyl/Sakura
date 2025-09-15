#pragma once

#include "Window.h"
#include <vulkan/vulkan.h>

#include <iostream>

namespace Sakura {

    class Application
    {
    public:

        Application();
        virtual ~Application();

        void Run();

    private:

        void Init();
        void Shutdown();

    private:

        bool m_IsRunning = true;
        std::unique_ptr<Window> m_Window;
    };

    Application* CreateApplication();
}