#version 460 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D inTexture;

void main() {
    FragColor = texture(inTexture, TexCoords) * vec4(1.0);
}