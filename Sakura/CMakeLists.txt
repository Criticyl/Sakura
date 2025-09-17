find_package(Vulkan REQUIRED)

SET(CORE_SOURCE_FILES 
    src/Core/Main.cpp
    src/Core/Application.cpp
    src/Core/Application.h
    src/Core/Window.cpp
    src/Core/Window.h
)

set(RENDERER_SOURCE_FILES
    src/Renderer/GraphicsPipeline.cpp
    src/Renderer/GraphicsPipeline.h
)

SET(SOURCES
    ${CORE_SOURCE_FILES}
    ${RENDERER_SOURCE_FILES}
    src/Sakura.h
)

add_library(Sakura STATIC ${SOURCES})

target_include_directories(Sakura PUBLIC src)

target_link_libraries(Sakura PUBLIC
    glfw
    glm
    Vulkan::Vulkan
)

target_compile_definitions(Sakura PRIVATE GLFW_INCLUDE_VULKAN)

set_target_properties(Sakura PROPERTIES
    SAKURA_SHADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders"
)
