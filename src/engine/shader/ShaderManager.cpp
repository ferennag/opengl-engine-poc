#include "ShaderManager.h"
#include "ShaderCompilationException.h"

std::unique_ptr<ShaderManager> ShaderManager::s_instance = std::unique_ptr<ShaderManager>(new ShaderManager());

Shader *ShaderManager::getShader(const ShaderType &type, string_view path) {
    if (m_shaderCache.contains(path.data())) {
        return m_shaderCache[path.data()].get();
    }

    unique_ptr<Shader> shader = Shader::compileFromSourceFile(type, path);

    if (shader == nullptr) {
        return nullptr;
    }

    m_shaderCache.insert({ path.data(), std::move(shader) });
    return m_shaderCache[path.data()].get();
}

ShaderProgram &ShaderManager::loadShaderProgram(string_view name, string_view vertexPath, string_view fragmentPath) {
    if (m_shaderProgramCache.contains(name.data())) {
        return *m_shaderProgramCache[name.data()];
    }

    Shader *vertex = getShader(ShaderType::Vertex, vertexPath);
    Shader *fragment = getShader(ShaderType::Fragment, fragmentPath);

    if (vertex == nullptr || fragment == nullptr) {
        throw ShaderCompilationException();
    }

    auto program = make_unique<ShaderProgram>();
    program->attachShader(ShaderType::Vertex, vertex);
    program->attachShader(ShaderType::Fragment, fragment);
    if (!program->link()) {
        throw ShaderCompilationException();
    }
    m_shaderProgramCache.insert({ name.data(), std::move(program) });

    m_shaderMapping.insert({ vertexPath.data(), name.data() });
    m_shaderMapping.insert({ fragmentPath.data(), name.data() });

    return *m_shaderProgramCache[name.data()];
}

ShaderProgram &ShaderManager::getShaderProgram(string_view name) const {
    return *m_shaderProgramCache.find(name.data())->second;
}

void ShaderManager::cleanup() {
    m_shaderProgramCache.clear();
    m_shaderCache.clear();
}
