#version 330
layout(location=0)in vec3 vertex_position;
layout(location=1)in vec3 vertex_normal;
layout(location=2) in vec2 vertex_uv;
uniform mat4 model_mat;
uniform mat4 normal_mat;
uniform mat4 view_mat;
uniform mat4 mvp_mat;
out vec2 frag_uv;
out vec3 frag_color;
void main()
{
	gl_Position=mvp_mat*vec4(vertex_position,1);
	frag_uv=vertex_uv;
	frag_color=vertex_normal;
}