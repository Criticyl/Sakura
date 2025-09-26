#pragma once

#include <vulkan/vulkan.h>

#include "Window.h"
#include "Device.h"
#include "Debug.h"

#include <iostream>

namespace Sakura {

    struct ApplicationProperties
    {
        std::string Name = "Example Application";
        std::uint32_t MajorVersion = 1;
        std::uint32_t MinorVersion = 0;
        std::uint32_t BuildVersion = 0;
        std::vector<const char*> ValidationLayers;
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

        void Init();
        void Run();

    private:

        void Shutdown();

        void CreateVkInstance();
        bool CheckValidationLayerSupport(const std::vector<const char*>& validationLayers);

    private:

        bool m_ValidationLayerEnabled;
        ApplicationProperties m_Properties;
        std::unique_ptr<DebugMessenger> m_DebugMessenger;
        VkInstance m_Instance = nullptr;
        Device m_Device;
        std::unique_ptr<Window> m_Window;
        
    };

    Application* CreateApplication();
}