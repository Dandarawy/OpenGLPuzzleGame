#include "Geometry.h"


Geometry::Geometry(std::vector<vertex> vertices, std::vector<GLuint> indices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

	//mat->bind();
	//position at layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glEnableVertexAttribArray(0);

	//normal at layout 1
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), ((char *)(sizeof(glm::vec3))));
	glEnableVertexAttribArray(1);

	//uv at layout 2
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), ((char *)(sizeof(glm::vec3) + sizeof(glm::vec3))));
	glEnableVertexAttribArray(2);

	indices_count = indices.size();

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices_count, indices.data(), GL_STATIC_DRAW);

}

Geometry::~Geometry()
{
}
void Geometry::Quad(int a, int b, int c, int d, std::vector<vertex> & vertices, std::vector<GLuint> &indices, int startIndex)
{
	//this cause problem when we define more than one cube
	//static int current_vertex = 0;
	glm::vec3 core_positions[] = {
		glm::vec3(-0.5, 0.5, 0.5),
		glm::vec3(-0.5, -0.5, 0.5),
		glm::vec3(0.5, -0.5, 0.5),
		glm::vec3(0.5, 0.5, 0.5),
		glm::vec3(0.5, 0.5, -0.5),
		glm::vec3(0.5, -0.5, -0.5),
		glm::vec3(-0.5, -0.5, -0.5),
		glm::vec3(-0.5, 0.5, -0.5)
	};
	glm::vec3 normal = glm::cross(core_positions[c] - core_positions[b], core_positions[a] - core_positions[b]);
	vertices.push_back(vertex{ core_positions[a] ,normal, glm::vec2(0,0) });
	vertices.push_back(vertex{ core_positions[b] ,normal, glm::vec2(1,0) });
	vertices.push_back(vertex{ core_positions[c] ,normal, glm::vec2(1,1) });
	vertices.push_back(vertex{ core_positions[d] ,normal, glm::vec2(0,1) });

	indices.push_back(startIndex);//a
	indices.push_back(startIndex + 1);//b
	indices.push_back(startIndex + 2);//c
	indices.push_back(startIndex);//a
	indices.push_back(startIndex + 2);//c
	indices.push_back(startIndex + 3);//d
}
void Geometry::CubeGenerator(std::vector<vertex> & vertices, std::vector<GLuint> &indices)
{
	//Front
	Quad(0, 1, 2, 3, vertices, indices, 0);
	//Right			 
	Quad(3, 2, 5, 4, vertices, indices, 4);
	//Back			
	Quad(4, 5, 6, 7, vertices, indices, 8);
	//Left			 
	Quad(0, 1, 6, 7, vertices, indices, 12);
	//Top			
	Quad(0, 3, 4, 7, vertices, indices, 16);
	//Bottom		
	Quad(1, 6, 5, 2, vertices, indices, 20);

}
std::shared_ptr<Geometry> Geometry::Create_cube()
{
	std::vector<vertex> vertices;
	std::vector<GLuint> indices;
	CubeGenerator(vertices, indices);
	std::shared_ptr<Geometry> cubeGeometry = std::make_shared<Geometry>(vertices, indices);
	return cubeGeometry;
}
//
//Geometry Geometry::Create_sphere(int iterations)
//{
//	return Geometry();
//}
