#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

namespace Sakura {

    struct QueueFamilyIndices
    {
        std::optional<std::uint32_t> GraphicsFamily;

        bool IsComplete()
        {
            return GraphicsFamily.has_value();
        }
    };

    class Device
    {
    public:
        void Init(const VkInstance& instance);
        QueueFamilyIndices FindQueueFamilies(const VkPhysicalDevice& device);

        inline const VkPhysicalDevice& GetPhysicalDevice() { return m_PhysicalDevice; }
    private:
        void PickPhysicalDevice(const std::vector<VkPhysicalDevice>& devices);
        int RateDevice(const VkPhysicalDevice& device);
        bool IsDeviceSuitable(const VkPhysicalDevice& device);
    private:
        VkPhysicalDevice m_PhysicalDevice;
    };
}