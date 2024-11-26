#version 330 core
in vec2 vUv0;
uniform sampler2D lightMap;
uniform sampler2D spaceSky;
out vec4 fFragColor; 

void main() {
    vec3 colorL = vec3(texture(spaceSky, vUv0));
    vec3 colorM = vec3(texture(lightMap, vUv0));
    vec3 color = mix(colorL, colorM, 0.7) * 10;
    fFragColor = vec4(color, 1.0);
}