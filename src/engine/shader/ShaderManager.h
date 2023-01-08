#ifndef ENGINE_POC_SHADERMANAGER_H
#define ENGINE_POC_SHADERMANAGER_H

#include <memory>
#include <map>
#include <string>
#include <string_view>
#include "ShaderProgram.h"

using namespace std;

class ShaderManager {
public:
    ShaderManager(const ShaderManager &other) = delete;
    ShaderManager& operator=(const ShaderManager &other) = delete;

    static ShaderManager &getInstance() { return *s_instance; }

    ShaderProgram& loadShaderProgram(string_view name, string_view vertexPath, string_view fragmentPath);
    ShaderProgram& getShaderProgram(string_view name) const;

    void cleanup();
private:
    static unique_ptr<ShaderManager> s_instance;
    map<string, unique_ptr<ShaderProgram>> m_shaderProgramCache;
    map<string, unique_ptr<Shader>> m_shaderCache;
    multimap<string, string> m_shaderMapping;

    ShaderManager() = default;
    Shader * getShader(const ShaderType &type, string_view path);
};


#endif //ENGINE_POC_SHADERMANAGER_H
