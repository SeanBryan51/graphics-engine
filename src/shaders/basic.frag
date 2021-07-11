#version 330 core

in vec3 position;

out vec4 colour;

uniform vec4 my_colour;
uniform vec2 lightpos;

void main() {
    float len = length(position.xy - lightpos);

    float intensity = 0.1 / len;
    // float intensity = -1 + 2.0 * len * cos(10*pos.y) * sin(10*pos.x);

    colour = my_colour * intensity;
}