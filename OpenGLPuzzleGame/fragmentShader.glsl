#version 130
in vec2 frag_uv0;
void main()
{
   gl_FragColor=vec4(frag_uv0,0,1);
}