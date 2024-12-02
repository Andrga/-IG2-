#version 330 core
in vec2 vUv0;
uniform sampler2D corrosion;
uniform sampler2D BumpyMetal;
uniform sampler2D Material_dirt;
out vec4 fFragColor; 

void main() {
    vec3 colorL = vec3(texture(corrosion, vUv0));
    vec3 colorM = vec3(texture(BumpyMetal, vUv0));
    fFragColor = vec4(color, 1.0);
}