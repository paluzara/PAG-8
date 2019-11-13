#version 400
in vec3 position;
in vec3 normal;
in vec2 texCoord; 


uniform vec3 Ks;
uniform vec3 Ia;
uniform vec3 Id;
uniform vec3 Is;
uniform float shininess;
uniform vec3 lightPosition;

uniform sampler2D TexSamplerColor;

layout (location = 0) out vec4 fragColor;

vec3 ads(vec4 texColor)
{
 vec3 Kad = texColor.rgb;
 vec3 n;
 if (gl_FrontFacing) {
 n = normalize(normal);
 } else {
 n = normalize(-normal);
 }
 vec3 l = normalize( lightPosition-position );
 vec3 v = normalize( -position );
 vec3 r = reflect( -l, n );
 return
 (Ia * Kad) +
 (Id * Kad * max( dot(l, n), 0.0)) +
 (Is * Ks * pow( max( dot(r,v), 0.0), Shininess ));
} 


void main() {
vec4 texColor = texture(TexSamplerColor, texCoord); 
 fragColor = vec4(ads(), 1.0);
}