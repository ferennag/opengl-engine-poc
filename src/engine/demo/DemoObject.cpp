#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "DemoObject.h"

DemoObject::~DemoObject() {
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

std::unique_ptr<DemoObject> DemoObject::createTriangle() {
    std::vector<Vertex> vertices(std::begin(TRIANGLE_VERTICES), std::end(TRIANGLE_VERTICES));
    return std::unique_ptr<DemoObject>(new DemoObject(vertices));
}

std::unique_ptr<DemoObject> DemoObject::createCube() {
    std::vector<Vertex> vertices(std::begin(CUBE_VERTICES), std::end(CUBE_VERTICES));
    return std::unique_ptr<DemoObject>(new DemoObject(vertices));
}

DemoObject::DemoObject(const std::vector<Vertex> &vertices) {
    m_vertices = vertices;
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, texture));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, normal));

    glBindVertexArray(0);
}

glm::mat4 DemoObject::getModelMatrix() const {
    return glm::mat4(1.0f);
}

glm::mat4 DemoObject::getNormalMatrix() const {
    return glm::mat4(1.0f);
}

void DemoObject::render() {
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    glBindVertexArray(0);
}

