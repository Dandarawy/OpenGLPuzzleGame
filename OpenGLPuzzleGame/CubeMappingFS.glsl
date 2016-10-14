in vec3 frag_uv0;
uniform samplerCube cubemap;  

void main()
{             
    gl_FragColor = texture(cubemap, frag_uv0);
}