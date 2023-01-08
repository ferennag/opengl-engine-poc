#include "TextureManager.h"

unique_ptr<TextureManager> TextureManager::s_instance = unique_ptr<TextureManager>(new TextureManager());

TextureManager &TextureManager::getInstance() {
    return *s_instance;
}

void TextureManager::cleanup() {
    m_cache.clear();
}

Texture &TextureManager::loadTexture(string_view name, string_view path) {
    if (m_cache.contains(name.data())) {
        return *m_cache.find(name.data())->second;
    }

    auto texture = Texture::loadTexture(path);
    m_cache[name.data()] = std::move(texture);
    return getTexture(name);
}

Texture &TextureManager::getTexture(string_view name) const {
    return *m_cache.find(name.data())->second;
}
