#ifndef ENGINE_POC_GLRENDERER_H
#define ENGINE_POC_GLRENDERER_H

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "demo/DemoObject.h"
#include "camera/Camera.h"

enum class ProjectionType {
    PERSPECTIVE,
    ORTHOGRAPHIC
};

class GLRenderer {
public:
    void initialize(const glm::vec2 &viewportSize, const ProjectionType& type);
    void update(float deltaTime);
    void render(float deltaTime);
    void cleanup();

    void setViewportSize(const glm::vec2 &viewportSize);
private:
    glm::vec2 m_viewportSize;
    glm::mat4 m_projection;
    ProjectionType m_projectionType;
    std::vector<std::unique_ptr<DemoObject>> m_objects;
    Camera m_camera;

    void setupProjectionMatrix();
};


#endif //ENGINE_POC_GLRENDERER_H
