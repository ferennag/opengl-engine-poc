#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "../input/KeyboardInput.h"
#include "../input/MouseInput.h"

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::update(float deltaTime) {
    auto pressedKeys = KeyboardInput::getInstance().getPressedKeys();

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_FORWARD)) {
        m_position += m_front * deltaTime * speed;
    }

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_BACKWARD)) {
        m_position += -m_front * deltaTime * speed;
    }

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_LEFT)) {
        m_position += -m_right * deltaTime * speed;
    }

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_RIGHT)) {
        m_position += m_right * deltaTime * speed;
    }

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_JUMP)) {
        m_position += m_up * deltaTime * speed;
    }

    if (pressedKeys.contains(KeyboardInputType::MOVEMENT_CROUCH)) {
        m_position += -m_up * deltaTime * speed;
    }

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    const glm::vec3 worldUp { 0, 1, 0 };
    m_right = glm::normalize(glm::cross(m_front, worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}

void Camera::processMouseMotion(double deltaX, double deltaY) {
    deltaX *= sensitivity;
    deltaY *= sensitivity;

    m_yaw += deltaX;
    m_pitch += deltaY;

    if (m_pitch > 89.0f) {
        m_pitch = 89.0f;
    }

    if (m_pitch < -89.0f) {
        m_pitch = -89.0f;
    }

    updateCameraVectors();
}

Camera::Camera() {
    m_motionObserverId = MouseInput::getInstance().subscribeToMouseMotion(this);
}

Camera::~Camera() = default;
