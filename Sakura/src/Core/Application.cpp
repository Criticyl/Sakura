#include "Application.h"

namespace Sakura {

    Application::~Application()
    {
        Shutdown();
    }

    void Application::Init()
    {
        Sakura::WindowProperties windowProps;
        m_Window = std::make_unique<Window>(windowProps);
        CreateVkInstance();
    }

    void Application::CreateVkInstance()
    {
        if (!m_Properties.ValidationLayers.empty() && !CheckValidationLayerSupport(m_Properties.ValidationLayers))
        {
            throw std::runtime_error("Error: Validation layers request but were not available!");
        }

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
        createInfo.enabledLayerCount = static_cast<uint32_t>(m_Properties.ValidationLayers.size());
        if (!m_Properties.ValidationLayers.empty())
        {
            createInfo.ppEnabledLayerNames = m_Properties.ValidationLayers.data();
        }

        VkResult result = vkCreateInstance(&createInfo, nullptr, &m_Instance);

        if (result != VK_SUCCESS)
        {
            throw std::runtime_error("Failed to create Vulkan Instance!");
        }
    }

    bool Application::CheckValidationLayerSupport(const std::vector<const char*>& validationLayers)
    {
        std::uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for (const char* layerName : validationLayers)
        {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers)
            {
                if (strcmp(layerName, layerProperties.layerName) == 0)
                {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound)
            {
                return false;
            }
        }

        return true;
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
        vkDestroyInstance(m_Instance, nullptr);
    }

}