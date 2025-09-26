#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

namespace Sakura {

    struct QueueFamilyIndices
    {
        std::optional<std::uint32_t> GraphicsFamily;
        std::optional<std::uint32_t> PresentFamily;

        bool IsComplete()
        {
            return GraphicsFamily.has_value() && PresentFamily.has_value();
        }
    };

    class Device
    {
    public:
        void Init(const VkInstance& instance, const VkSurfaceKHR& surface);
        QueueFamilyIndices FindQueueFamilies(const VkPhysicalDevice& device);

        void Shutdown();

        inline const VkPhysicalDevice& GetPhysicalDevice() { return m_PhysicalDevice; }
    private:
        void PickPhysicalDevice(const std::vector<VkPhysicalDevice>& devices);
        void CreateLogicalDevice();
        int RateDevice(const VkPhysicalDevice& device);
        bool IsDeviceSuitable(const VkPhysicalDevice& device);
    private:

        VkSurfaceKHR m_Surface;

    private:
        VkPhysicalDevice m_PhysicalDevice;
        VkDevice m_LogicalDevice;
        VkQueue m_GraphicsQueue;
        VkQueue m_PresentQueue;
    };
}