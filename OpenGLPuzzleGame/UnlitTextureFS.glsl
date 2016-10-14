#version 330
in vec2 frag_uv;
uniform sampler2D color_map;
uniform vec2 offset;
uniform vec2 tilling;
uniform vec3 tint;
in float intensity;
void main()
{
	vec2 uv=vec2(offset.x+tilling.x*frag_uv.x,offset.y+tilling.y*(1-frag_uv.y));
	gl_FragColor=texture2D(color_map, uv)*vec4(tint,1)*intensity;
}