#version 330 core

in vec2 vUv0; // Out del vertex shader.
out vec4 fFragColor; // Out (del fragment shader)

uniform sampler2D texSky;
uniform sampler2D texLight;

uniform float time;
uniform float lightMin; // 0.3
uniform float lightMax; // 1

void main() {
    vec3 col1 = vec3(texture(texSky, vUv0));
    vec3 col2 = vec3(texture(texLight, vUv0));

    vec3 mezcla = mix(col1, col2, 0.5);

    float lightDiff = lightMax - lightMin;
    float lightFactor = lightMin + (lightDiff * ((time + 1) / 2));

    fFragColor = vec4(mezcla.x * lightFactor, mezcla.y * lightFactor, mezcla.z * lightFactor, 1.0);

    vec3 color = col1 * col2 * lightFactor;

    fFragColor = vec4(color, 1.0);
}