#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GLRenderer.h"
#include "shader/ShaderManager.h"
#include "texture/TextureManager.h"

void GLRenderer::initialize(const glm::vec2 &viewportSize, const ProjectionType &projectionType) {
    m_projectionType = projectionType;
    m_viewportSize = viewportSize;
    setupProjectionMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    glClearColor(0.3, 0.3, 0.3, 1.0);

    ShaderManager::getInstance().loadShaderProgram("simple", "../resources/shaders/simple-vertex.glsl",
                                                   "../resources/shaders/simple-fragment.glsl");
    TextureManager::getInstance().loadTexture("wall", "../resources/textures/wall.jpg");

    m_objects.push_back(DemoObject::createCube());
    m_camera.setPosition({ 0, 2, -5 });
}

void GLRenderer::update(double deltaTime) {
}

void GLRenderer::render(double deltaTime) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    auto &shader = ShaderManager::getInstance().getShaderProgram("simple");
    shader.bind();
    shader.setMat4("projection", m_projection);
    shader.setMat4("view", m_camera.getViewMatrix());

    for (auto &object: m_objects) {
        auto& texture = TextureManager::getInstance().getTexture("wall");
        texture.bind(0);
        shader.setMat4("model", object->getModelMatrix());
        shader.setMat4("normalMatrix", object->getNormalMatrix());
        object->render();
        texture.unbind();
    }

    shader.unbind();
}

void GLRenderer::cleanup() {
    ShaderManager::getInstance().cleanup();
    TextureManager::getInstance().cleanup();
}

void GLRenderer::setViewportSize(const glm::vec2 &viewportSize) {
    m_viewportSize = viewportSize;
    glViewport(0, 0, static_cast<int>(viewportSize.x), static_cast<int>(viewportSize.y));
    setupProjectionMatrix();
}

void GLRenderer::setupProjectionMatrix() {
    if (m_projectionType == ProjectionType::ORTHOGRAPHIC) {
        m_projection = glm::ortho(0.0f, 0.0f, m_viewportSize.x, m_viewportSize.y);
    } else {
        m_projection = glm::perspective(45.0f, m_viewportSize.x / m_viewportSize.y, 0.1f, 100.0f);
    }
}
