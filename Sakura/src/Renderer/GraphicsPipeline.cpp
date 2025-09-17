#include "GraphicsPipeline.h"
#include <iostream>

namespace Sakura {

    GraphicsPipeline::GraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath)
    {
        CreateGraphicsPipeline(vertexPath, fragmentPath);
    }

    std::vector<char> GraphicsPipeline::ReadFile(const std::string& filePath)
    {
        std::ifstream file(filePath, std::ios::ate | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return {};
        }
    }

    void  GraphicsPipeline::CreateGraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath)
    {

    }
}