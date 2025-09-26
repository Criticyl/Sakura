#pragma once

#include <vulkan/vulkan.h>
#include <iostream>

namespace Sakura {

    class DebugMessenger {
    public:

        DebugMessenger(const VkInstance& instance, const VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        ~DebugMessenger();

        static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData)
            {
                std::cerr << "[Validation Layer]: " << pCallbackData->pMessage << std::endl;
                return VK_FALSE;
            }

    private:

        VkInstance m_Instance = nullptr;
        VkDebugUtilsMessengerEXT m_Handle = nullptr;

    };

}