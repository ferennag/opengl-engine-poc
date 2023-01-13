cmake_minimum_required(VERSION 3.25)
project(engine_poc)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.8
)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glfw glm)
find_package(OpenGL REQUIRED)

include_directories(lib/glad/include lib/stbi)

add_executable(engine_poc lib/glad/src/glad.c src/main.cpp src/engine/GLRenderer.cpp src/engine/GLRenderer.h src/engine/input/MouseInput.cpp src/engine/input/MouseInput.h src/engine/shader/ShaderManager.cpp src/engine/shader/ShaderManager.h src/engine/shader/ShaderProgram.cpp src/engine/shader/ShaderProgram.h src/engine/shader/Shader.cpp src/engine/shader/Shader.h src/engine/logging/Logger.cpp src/engine/logging/Logger.h src/engine/shader/ShaderCompilationException.h src/engine/demo/DemoObject.cpp src/engine/demo/DemoObject.h src/engine/camera/Camera.cpp src/engine/camera/Camera.h src/engine/texture/Texture.cpp src/engine/texture/Texture.h src/engine/texture/TextureManager.cpp src/engine/texture/TextureManager.h lib/stbi/stb_image.h src/engine/texture/stb_image_init.cpp src/engine/texture/TextureLoadException.h src/engine/input/KeyboardInput.cpp src/engine/input/KeyboardInput.h src/engine/input/MouseMotionObserver.h src/engine/input/MouseMotionObserver.h src/engine/input/MouseMotionObserver.h)
target_link_libraries(engine_poc glfw glm)

if(UNIX)
    add_definitions(-g -O2 -std=c++20 -Wall -Wextra)
endif()
