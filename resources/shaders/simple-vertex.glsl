#version 460 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 normalMatrix;

out vec2 TexCoords;

void main() {
    gl_Position = projection * view * model * vec4(vertex, 1.0);
    TexCoords = tex;
}