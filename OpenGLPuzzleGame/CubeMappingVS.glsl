#version 330
layout(location=0)in vec3 vertex_position;
uniform mat4 model_mat;
uniform mat4 view_mat;
uniform mat4 proj_mat;
uniform mat4 mvp_mat;

out vec3 frag_uv0;
void main()
{
	gl_Position=mvp_mat*vec4(vertex_position,1);
	frag_uv0=vertex_position;
}

