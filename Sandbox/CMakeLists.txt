add_executable(Sandbox src/SandboxApp.cpp)

target_link_libraries(Sandbox PUBLIC Sakura)

get_target_property(SAKURA_SHADERS_DIR Sakura SAKURA_SHADERS_DIR)

add_custom_command(
    TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${SAKURA_SHADERS_DIR}"
            "$<TARGET_FILE_DIR:Sandbox>/Shaders"
)