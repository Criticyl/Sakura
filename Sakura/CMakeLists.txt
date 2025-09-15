find_package(Vulkan REQUIRED)

SET(SOURCE_DIR "src")
SET(SOURCES
    src/Main.cpp
    src/Application.cpp
    src/Application.h
    src/Window.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glm
    Vulkan::Vulkan
)

target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_VULKAN)