#pragma once

#include <vulkan/vulkan.h>

#include <iostream>

namespace Sakura {
    class HelloTriangleApplication
    {
    public:
        void Run()
        {
            Init();
            Render();
            Cleanup();
        }
    private:
        void Init();
        void Render();
        void Cleanup();
    };
}