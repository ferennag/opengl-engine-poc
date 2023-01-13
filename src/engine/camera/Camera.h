#ifndef ENGINE_POC_CAMERA_H
#define ENGINE_POC_CAMERA_H

#include <glm/glm.hpp>
#include "../input/MouseMotionObserver.h"

class Camera: public MouseMotionObserver {
public:
    Camera();
    virtual ~Camera();
    glm::mat4 getViewMatrix() const;

    void setPosition(const glm::vec3 &pos) { m_position = pos; }
    void update(float deltaTime);
private:
    const float speed { 5.0f };
    const float sensitivity { 0.05f };
    float m_yaw { -90.0f };
    float m_pitch { 0.0f };

    glm::vec3 m_position { 0, 0, 0 };
    glm::vec3 m_up { 0, 1, 0 };
    glm::vec3 m_front { 0, 0, 1 };
    glm::vec3 m_right { 1, 0, 0 };

    MouseMotionObserverId m_motionObserverId;

    void updateCameraVectors();
    void processMouseMotion(double deltaX, double deltaY) override;
};


#endif //ENGINE_POC_CAMERA_H
