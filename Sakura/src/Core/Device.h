#pragma once

#include <vulkan/vulkan.h>
#include <vector>

namespace Sakura {

    class Device
    {
    public:
        void Init(const VkInstance& instance);

        inline const VkPhysicalDevice& GetPhysicalDevice() { return m_PhysicalDevice; }
    private:
        void PickPhysicalDevice(const std::vector<VkPhysicalDevice>& devices);
        int RateDevice(const VkPhysicalDevice& device);
        bool IsDeviceSuitable(const VkPhysicalDevice& device);
    private:
        VkPhysicalDevice m_PhysicalDevice;
    };
}