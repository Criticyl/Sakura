#pragma once

#include <GLFW/glfw3.h>

#include <string>

namespace Sakura {

    struct WindowProperties
    {
        int Width = 1280;
        int Height = 720;
        std::string Title = "Sakura | Voxel Engine";
    };

    class Window
    {
    public:
        Window(const WindowProperties& properties)
            : m_Width(properties.Width),
              m_Height(properties.Height),
              m_Title(properties.Title)
        { 
            Init();
        }

        inline GLFWwindow* GetWindow() const { return m_Window; }

        ~Window();
    private:

        void Init();

        int m_Width;
        int m_Height;
        std::string m_Title;
        GLFWwindow* m_Window;
    };

}
