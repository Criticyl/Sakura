#include "Device.h"
#include <stdexcept>
#include <map>

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

        std::vector<VkPhysicalDevice> devices;
        vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

        PickPhysicalDevice(devices);
        CreateLogicalDevice();
    }

    void Device::Shutdown()
    {
        vkDestroyDevice(m_LogicalDevice, nullptr);
    }

    QueueFamilyIndices Device::FindQueueFamilies(const VkPhysicalDevice& device)
    {
        QueueFamilyIndices indices;

        std::uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        int i = 0;
        for (const VkQueueFamilyProperties& queueFamily : queueFamilies)
        {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
                indices.GraphicsFamily = i;

            if (indices.IsComplete())
                break;

            i++;
        }


        return indices;
    }

    void Device::PickPhysicalDevice(const std::vector<VkPhysicalDevice>& devices)
    {
        std::multimap<int, VkPhysicalDevice> deviceCandidates;

        for (const VkPhysicalDevice& device : devices)
        {
            int score = RateDevice(device);
            deviceCandidates.insert(std::make_pair(score, device));
        }

        if (deviceCandidates.rbegin()->first > 0)
        {
            m_PhysicalDevice = deviceCandidates.rbegin()->second;
        }
        else 
        {
            throw std::runtime_error("Error: Failed to find suitable GPU!");
        }
    }

    void Device::CreateLogicalDevice()
    {
        QueueFamilyIndices indices = FindQueueFamilies(m_PhysicalDevice);

        VkDeviceQueueCreateInfo queueCreateInfo;
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = indices.GraphicsFamily.value();
        queueCreateInfo.queueCount = 1;

        VkPhysicalDeviceFeatures deviceFeatures;
        VkDeviceCreateInfo createInfo;
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        createInfo.pQueueCreateInfos = &queueCreateInfo;
        createInfo.queueCreateInfoCount = 1;
        createInfo.pEnabledFeatures = &deviceFeatures;

        if (vkCreateDevice(m_PhysicalDevice, &createInfo, nullptr, &m_LogicalDevice) != VK_SUCCESS)
        {
            throw std::runtime_error("Error: Failed to create logical device!");
        }

        vkGetDeviceQueue(m_LogicalDevice, indices.GraphicsFamily.value(), 0, &m_GraphicsQueue);

    }

    int Device::RateDevice(const VkPhysicalDevice& device)
    {
        VkPhysicalDeviceProperties deviceProperties;
        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);
        vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

        int score = 0;

        if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
            score += 1000;

        score += deviceProperties.limits.maxImageDimension2D;

        if (!deviceFeatures.geometryShader)
            score = 0;

        return score;
    }

    bool Device::IsDeviceSuitable(const VkPhysicalDevice& device)
    {
        QueueFamilyIndices indices = FindQueueFamilies(device);

        return indices.IsComplete();
    }
}