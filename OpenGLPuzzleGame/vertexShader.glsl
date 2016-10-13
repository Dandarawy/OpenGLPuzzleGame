#version 130
in vec3 vertex_position;
out vec2 frag_uv0;
void main()
{
	gl_Position=vec4(vertex_position,1);
	frag_uv0=((vertex_position+vec3(1,1,0))/2).xy;
}
