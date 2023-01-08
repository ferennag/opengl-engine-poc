#ifndef ENGINE_POC_CAMERA_H
#define ENGINE_POC_CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    glm::mat4 getViewMatrix() const;

    void setPosition(const glm::vec3 &pos) { m_position = pos; }

private:
    glm::vec3 m_position { 0, 0, 0 };
    glm::vec3 m_up { 0, 1, 0 };
};


#endif //ENGINE_POC_CAMERA_H
