#pragma once

#include <string>
#include <fstream>
#include <vector>

namespace Sakura {

    class GraphicsPipeline
    {
    public:
        GraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath);
    private:
        static std::vector<char> ReadFile(const std::string& filePath);
        void CreateGraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath);
    };

}