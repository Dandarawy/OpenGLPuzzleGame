#version 330
in vec2 frag_uv;
in vec3 frag_color;
uniform sampler2D color_map;
uniform vec2 offset;
uniform vec2 tilling;
uniform vec3 tint;
void main()
{
	gl_FragColor=vec4(frag_color,1);
}