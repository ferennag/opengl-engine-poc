#ifndef ENGINE_POC_TEXTUREMANAGER_H
#define ENGINE_POC_TEXTUREMANAGER_H

#include <map>
#include <string>
#include <string_view>
#include <memory>
#include "Texture.h"

using namespace std;

class TextureManager {
public:
    TextureManager(const TextureManager &other) = delete;
    TextureManager &operator=(const TextureManager &other) = delete;
    virtual ~TextureManager() = default;
    static TextureManager &getInstance();

    Texture& loadTexture(string_view name, string_view path);
    Texture& getTexture(string_view name) const;
    void cleanup();
private:
    static unique_ptr<TextureManager> s_instance;
    map<string, unique_ptr<Texture>> m_cache;

    TextureManager() = default;
};


#endif //ENGINE_POC_TEXTUREMANAGER_H
