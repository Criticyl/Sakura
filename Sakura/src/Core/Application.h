#pragma once

#include "Window.h"
#include "Renderer/GraphicsPipeline.h"
#include <vulkan/vulkan.h>

#include <iostream>

namespace Sakura {

    struct ApplicationProperties
    {
        std::string Name = "Example Application";
        std::uint32_t MajorVersion = 1;
        std::uint32_t MinorVersion = 0;
        std::uint32_t BuildVersion = 0;
    };

    class Application
    {
    public:

        Application(const ApplicationProperties& appProperties)
            : m_Properties(appProperties)
        {
            Init();
        }

        virtual ~Application();

        void Run();

    private:

        void Init();
        void Shutdown();

        void CreateVkInstance();

    private:

        ApplicationProperties m_Properties;
        std::unique_ptr<Window> m_Window;
        VkInstance m_Instance;
    };

    Application* CreateApplication();
}