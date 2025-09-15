#include "Window.h"

#include <iostream>

namespace Sakura {

    void Window::Init()
    {
        if (!glfwInit())
        {
            std::cerr << "ERROR: Failed to initialise GLFW!" << std::endl;
            return;
        }
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
        if (!m_Window)
        {
            std::cerr << "ERROR: Failed to create GLFW window!" << std::endl;
            glfwTerminate();
            return;
        }


    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
}