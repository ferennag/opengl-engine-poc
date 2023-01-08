#ifndef ENGINE_POC_SHADER_H
#define ENGINE_POC_SHADER_H

#include <memory>
#include <string>
#include <string_view>

enum class ShaderType {
    Vertex,
    Fragment
};

class Shader {
public:
    Shader(const Shader &other) = delete;
    Shader& operator=(const Shader &other) = delete;
    virtual ~Shader();

    unsigned int getId() const { return m_id; };
    std::string getPath() const { return m_path; };
    ShaderType getType() const { return m_type; };

    static std::unique_ptr<Shader> compileFromSourceFile(const ShaderType &type, std::string_view path);
protected:
    unsigned int m_id;
    std::string m_path;
    ShaderType m_type;

    Shader(unsigned int id, const ShaderType &type, const std::string &path);
};


#endif //ENGINE_POC_SHADER_H
