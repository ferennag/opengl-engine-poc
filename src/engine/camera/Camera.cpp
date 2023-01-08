#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, { 0, 0, 0 }, m_up);
}
