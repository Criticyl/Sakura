#include "Debug.h"
#include <stdexcept>

namespace Sakura {

    DebugMessenger::DebugMessenger(const VkInstance& instance, const VkDebugUtilsMessengerCreateInfoEXT& createInfo)
    {

        m_Instance = instance;

        auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_Instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr)
        {
            if (func(m_Instance, &createInfo, nullptr, &m_Handle) != VK_SUCCESS)
            {
                throw std::runtime_error("Error: Failed to set up debug messenger!");
            }
        }
        else {
            throw std::runtime_error("Error: Extension not found!");
        }
        
    }

    DebugMessenger::~DebugMessenger()
    {
        if (m_Instance != nullptr)
        {
            auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(m_Instance, "vkDestroyDebugUtilsMessengerEXT");
            if (func != nullptr)
            {
                func(m_Instance, m_Handle, nullptr);
            }
        }
    }

}