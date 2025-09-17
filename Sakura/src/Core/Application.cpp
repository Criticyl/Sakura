#include "Application.h"

namespace Sakura {

    Application::~Application()
    {
        Shutdown();
    }

    void Application::Init()
    {
        CreateVkInstance();
        Sakura::WindowProperties props;
        m_Window = std::make_unique<Window>(props);
    }

    void Application::CreateVkInstance()
    {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = m_Properties.Name.c_str();
        appInfo.applicationVersion = VK_MAKE_VERSION(m_Properties.MajorVersion, m_Properties.MinorVersion, m_Properties.BuildVersion);
        appInfo.pEngineName = "Sakura";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        std::uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        
        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        VkResult result = vkCreateInstance(&createInfo, nullptr, &m_Instance);

        if (result != VK_SUCCESS)
        {
            throw std::runtime_error("Failed to create Vulkan Instance!");
        }
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