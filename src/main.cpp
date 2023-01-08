#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "engine/GLRenderer.h"
#include "engine/input/MouseInput.h"

using namespace std;

GLRenderer renderer;

void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, true);
    }
}

void mousePositionCallback(GLFWwindow *window, double xpos, double ypos) {
    MouseInput::getInstance().setPosition({ xpos, ypos });
}

void windowSizeCallback(GLFWwindow *window, int w, int h) {
    renderer.setViewportSize({ w, h });
}

void errorCallback(int error_code, const char *description) {
    cerr << "ERROR " << error_code << ": " << description << endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
}

int main() {
    if (!glfwInit()) {
        cerr << "ERROR: Unable to initialize GLFW" << endl;
        exit(EXIT_FAILURE);
    }

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Graphics Engine PoC", nullptr, nullptr);
    if (!window) {
        cerr << "ERROR: Unable to create GLFW window" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        cerr << "ERROR: " << "Unable to initialize GLAD" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 12);
    glfwSetKeyCallback(window, keyboardCallback);
    glfwSetCursorPosCallback(window, mousePositionCallback);
    glfwSetWindowSizeCallback(window, windowSizeCallback);
    glfwSetErrorCallback(errorCallback);

    renderer.initialize({ 1920, 1080 }, ProjectionType::PERSPECTIVE);

    double lastFrame = 0;
    while (!glfwWindowShouldClose(window)) {
        double now = glfwGetTime();
        double deltaTime = now - lastFrame;
        lastFrame = now;

        renderer.update(deltaTime);
        renderer.render(deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    renderer.cleanup();
    glfwTerminate();
    return 0;
}
