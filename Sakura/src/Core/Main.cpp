#include "Application.h"

#include <stdexcept>
#include <cstdlib>

int main() {

    try 
    {
        Sakura::Application* app = Sakura::CreateApplication();
        app->Run();

        delete app;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}