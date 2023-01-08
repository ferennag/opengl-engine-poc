#ifndef ENGINE_POC_TEXTURE_H
#define ENGINE_POC_TEXTURE_H

#include <memory>
#include <string_view>

class Texture {
public:
    Texture(const Texture &other) = delete;
    Texture &operator=(const Texture &other) = delete;
    virtual ~Texture();

    static std::unique_ptr<Texture> loadTexture(std::string_view path);

    void bind(int textureId);
    void unbind();
private:
    unsigned int m_id;

    Texture(unsigned int id);
};


#endif //ENGINE_POC_TEXTURE_H
