#version 400


in vec2 texCoord; 
uniform vec3 Ks;
uniform vec3 Ia;
uniform vec3 Id;
uniform vec3 Is;
uniform float shininess;
uniform sampler2D TexSamplerColor;


layout (location = 0) out vec4 fragColor;
vec3 ambient(vec4 texColor) {
 vec3 ambient = (Ia * texColor.rgb);
 return ambient;
}
void main() {

 vec4 texColor = texture(TexSamplerColor, texCoord); 
 fragColor = vec4(ambient(texColor), 1.0);

}