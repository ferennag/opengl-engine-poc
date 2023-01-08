#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.h"

ShaderProgram::~ShaderProgram() {
    if (m_id.has_value()) {
        glDeleteProgram(m_id.value());
    }
}

void ShaderProgram::attachShader(const ShaderType &type, Shader *shader) {
    m_shaders.insert({ type, shader });
}

bool ShaderProgram::link() {
    if (!m_id.has_value()) {
        m_id = glCreateProgram();
    }

    for (auto &entry: m_shaders) {
        glAttachShader(m_id.value(), entry.second->getId());
    }

    glLinkProgram(m_id.value());

    int success;
    char infoLog[2048];
    glGetProgramiv(m_id.value(), GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_id.value(), 2048, nullptr, infoLog);
        std::cerr << "ERROR::PROGRAM_LINKING_ERROR of: " << infoLog << std::endl;
    }

    return success;
}

void ShaderProgram::bind() {
    glUseProgram(m_id.value());
}

void ShaderProgram::unbind() {
    glUseProgram(0);
}

void ShaderProgram::setBool(std::string_view name, bool value) const {
    glUniform1i(glGetUniformLocation(m_id.value(), name.data()), (int) value);
}

void ShaderProgram::setInt(std::string_view name, int value) const {
    glUniform1i(glGetUniformLocation(m_id.value(), name.data()), value);
}

void ShaderProgram::setFloat(std::string_view name, float value) const {
    glUniform1f(glGetUniformLocation(m_id.value(), name.data()), value);
}

void ShaderProgram::setMat4(std::string_view name, const glm::mat4 &value) const {
    int location = glGetUniformLocation(m_id.value(), name.data());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

