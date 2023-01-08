#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "Shader.h"

static std::string loadSource(std::string_view path) {
    std::ifstream input(path.data(), std::ios::in | std::ios::binary);
    std::string contents(std::istreambuf_iterator<char> { input }, {});
    input.close();
    return contents;
}

static GLenum getGLShaderType(const ShaderType &type) {
    switch (type) {
        case ShaderType::Vertex:
            return GL_VERTEX_SHADER;
        case ShaderType::Fragment:
            return GL_FRAGMENT_SHADER;
    }
}


Shader::Shader(unsigned int id, const ShaderType &type, const std::string &path) {
    m_id = id;
    m_type = type;
    m_path = path;
}

std::unique_ptr<Shader> Shader::compileFromSourceFile(const ShaderType &type, std::string_view path) {
    const std::string source = loadSource(path);
    const char *c_source = source.c_str();
    unsigned int id = glCreateShader(getGLShaderType(type));
    glShaderSource(id, 1, &c_source, nullptr);
    glCompileShader(id);

    int success;
    char infoLog[2048];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 2048, nullptr, infoLog);
        std::cerr << "ERROR::SHADER_COMPILATION_ERROR of: " << path << std::endl << infoLog << std::endl;
        return nullptr;
    }

    return std::unique_ptr<Shader>(new Shader(id, type, path.data()));
}

Shader::~Shader() {
    glDeleteShader(m_id);
}
