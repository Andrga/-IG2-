#version 330 core
in vec2 vUv0;
uniform sampler2D corrosion;
uniform sampler2D BumpyMetal;
uniform sampler2D Material_dirt;
uniform float flipping;

out vec4 fFragColor; 

void main() {
    vec4 corrColor = texture(corrosion, vUv0);

    if (corrColor.r > 0.6) {
        discard; // Descarta el fragmento
    } 

    bool frontFacing = (flipping > -1) ? gl_FrontFacing : !gl_FrontFacing;

    vec4 color;
    if(frontFacing)
        color = texture(BumpyMetal, vUv0);
    else
        color = texture(Material_dirt, vUv0);

    fFragColor = color;

}