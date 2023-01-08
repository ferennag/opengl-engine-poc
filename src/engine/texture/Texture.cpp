#include <iostream>
#include <glad/glad.h>
#include <stb_image.h>
#include "Texture.h"
#include "TextureLoadException.h"

std::unique_ptr<Texture> Texture::loadTexture(std::string_view path) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.data(), &width, &height, &nrChannels, 4);

    if (!data) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        throw TextureLoadException();
    }

    unsigned int id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    return std::unique_ptr<Texture>(new Texture(id));
}

Texture::Texture(unsigned int id) : m_id(id) {
}

Texture::~Texture() {
    glDeleteTextures(1, &m_id);
}

void Texture::bind(int textureId) {
    glActiveTexture(GL_TEXTURE0 + textureId);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
