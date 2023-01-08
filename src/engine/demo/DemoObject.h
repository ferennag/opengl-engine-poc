#ifndef ENGINE_POC_DEMOOBJECT_H
#define ENGINE_POC_DEMOOBJECT_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>

struct Vertex {
    float vertex[3];
    float texture[2];
    float normal[3];
};

class DemoObject {
public:
    DemoObject(const DemoObject &other) = delete;
    DemoObject &operator=(const DemoObject &other) = delete;
    virtual ~DemoObject();

    static std::unique_ptr<DemoObject> createTriangle();
    static std::unique_ptr<DemoObject> createCube();

    void render();
    glm::mat4 getModelMatrix() const;
    glm::mat4 getNormalMatrix() const;
private:
    unsigned int m_vao, m_vbo;
    std::vector<Vertex> m_vertices;

    DemoObject(const std::vector<Vertex> &vertices);
};

static constexpr Vertex TRIANGLE_VERTICES[] = {
        { .vertex = { -0.5f, -0.5f, 0.0f }},
        { .vertex = { 0.5f, -0.5f, 0.0f }},
        { .vertex = { 0.0f, 0.5f, 0.0f }},
};

static constexpr Vertex CUBE_VERTICES[] = {
        // Vertex position - Texture coordinates - Vertex Normals
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ 0.5f,  -0.5f, -0.5f }, { 1.0f, 0.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ 0.5f,  0.5f,  -0.5f }, { 1.0f, 1.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ 0.5f,  0.5f,  -0.5f }, { 1.0f, 1.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ -0.5f, 0.5f,  -0.5f }, { 0.0f, 1.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }, { 0.0f,  0.0f,  -1.0f }},
        {{ -0.5f, -0.5f, 0.5f },  { 0.0f, 0.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ 0.5f,  -0.5f, 0.5f },  { 1.0f, 0.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 1.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 1.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ -0.5f, 0.5f,  0.5f },  { 0.0f, 1.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ -0.5f, -0.5f, 0.5f },  { 0.0f, 0.0f }, { 0.0f,  0.0f,  1.0f }},
        {{ -0.5f, 0.5f,  0.5f },  { 1.0f, 0.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ -0.5f, 0.5f,  -0.5f }, { 1.0f, 1.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ -0.5f, -0.5f, 0.5f },  { 0.0f, 0.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ -0.5f, 0.5f,  0.5f },  { 1.0f, 0.0f }, { -1.0f, 0.0f,  0.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ 0.5f,  0.5f,  -0.5f }, { 1.0f, 1.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ 0.5f,  -0.5f, -0.5f }, { 0.0f, 1.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ 0.5f,  -0.5f, -0.5f }, { 0.0f, 1.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ 0.5f,  -0.5f, 0.5f },  { 0.0f, 0.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f }, { 1.0f,  0.0f,  0.0f }},
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ 0.5f,  -0.5f, -0.5f }, { 1.0f, 1.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ 0.5f,  -0.5f, 0.5f },  { 1.0f, 0.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ 0.5f,  -0.5f, 0.5f },  { 1.0f, 0.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ -0.5f, -0.5f, 0.5f },  { 0.0f, 0.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f }, { 0.0f,  -1.0f, 0.0f }},
        {{ -0.5f, 0.5f,  -0.5f }, { 0.0f, 1.0f }, { 0.0f,  1.0f,  0.0f }},
        {{ 0.5f,  0.5f,  -0.5f }, { 1.0f, 1.0f }, { 0.0f,  1.0f,  0.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f }, { 0.0f,  1.0f,  0.0f }},
        {{ 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f }, { 0.0f,  1.0f,  0.0f }},
        {{ -0.5f, 0.5f,  0.5f },  { 0.0f, 0.0f }, { 0.0f,  1.0f,  0.0f }},
        {{ -0.5f, 0.5f,  -0.5f }, { 0.0f, 1.0f }, { 0.0f,  1.0f,  0.0f }}
};

#endif //ENGINE_POC_DEMOOBJECT_H
