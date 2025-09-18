#include "Device.h"
#include <stdexcept>

namespace Sakura {

    void Device::Init(const VkInstance& instance)
    {
        m_PhysicalDevice = VK_NULL_HANDLE;
        std::uint32_t deviceCount = 0;

        vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
        if (deviceCount == 0)
        {
            throw std::runtime_error("Error: Failed to find any GPU with Vulkan support!");
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

        for (const auto& device : devices)
        {
            if (isDeviceSuitable(device))
            {
                m_PhysicalDevice = device;
                break;
            }
        }

        if (m_PhysicalDevice == VK_NULL_HANDLE)
        {
            throw std::runtime_error("Error: Failed to find a suitable GPU!");
        }
    }

    bool Device::isDeviceSuitable(const VkPhysicalDevice& device)
    {
        return true;
    }
}