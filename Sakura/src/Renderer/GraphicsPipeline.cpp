#include "GraphicsPipeline.h"
#include <iostream>
#include <filesystem>

namespace Sakura {

    #ifdef _WIN32
    #include <windows.h>

    std::filesystem::path getExecutableDirectory() {
        wchar_t path[MAX_PATH];
        GetModuleFileNameW(NULL, path, MAX_PATH);
        return std::filesystem::path(path).parent_path();
    }
    #endif

    GraphicsPipeline::GraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath)
    {
        CreateGraphicsPipeline(vertexPath, fragmentPath);
    }

    std::vector<char> GraphicsPipeline::ReadFile(const std::string& filePath)
    {

        std::filesystem::path execDirectory = getExecutableDirectory();
        std::filesystem::path fullPath = execDirectory / filePath;

        std::ifstream file(fullPath, std::ios::ate | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return {};
        }

        size_t fileSize = static_cast<size_t>(file.tellg()); 
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void GraphicsPipeline::CreateGraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath)
    {
        auto vertCode = ReadFile(vertexPath);
        auto fragCode = ReadFile(fragmentPath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
    }
}