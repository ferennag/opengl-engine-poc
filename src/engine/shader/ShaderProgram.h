#ifndef ENGINE_POC_SHADERPROGRAM_H
#define ENGINE_POC_SHADERPROGRAM_H

#include <map>
#include <optional>
#include <glm/glm.hpp>
#include "Shader.h"

class ShaderProgram {
public:
    virtual ~ShaderProgram();
    void attachShader(const ShaderType &type, Shader *shader);
    bool link();

    void bind();
    void unbind();

    void setBool(std::string_view name, bool value) const;
    void setInt(std::string_view name, int value) const;
    void setFloat(std::string_view name, float value) const;
    void setMat4(std::string_view name, const glm::mat4 &value) const;
private:
    std::optional<unsigned int> m_id;
    std::map<ShaderType, Shader *> m_shaders;
};


#endif //ENGINE_POC_SHADERPROGRAM_H
