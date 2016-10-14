#version 330
layout(location=0)in vec3 vertex_position;
layout(location=1)in vec3 vertex_normal;
layout(location=2) in vec2 vertex_uv;
uniform mat4 model_mat;
uniform mat4 normal_mat;
uniform mat4 view_mat;
uniform mat4 mvp_mat;
out vec2 frag_uv;
out float intensity;
void main()
{
	gl_Position=mvp_mat*vec4(vertex_position,1);
	frag_uv=vertex_uv;
	//even its unlit shader, I decided to add basic lighting effect
	vec3 normal=normalize((inverse(transpose(model_mat))*vec4(vertex_normal.xyz,0)).xyz);
	vec3 lightDirection=normalize(vec3(3,4,-1));
	intensity=min(1,0.3+max(0,dot(normal,lightDirection)));
}