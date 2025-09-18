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
        bool isDeviceSuitable();
    private:
        VkPhysicalDevice m_PhysicalDevice;


    };
}