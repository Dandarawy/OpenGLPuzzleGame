#pragma once
#include <glew\glew.h>
#include <SFML\OpenGL.hpp>
#include <vector>
#include <glm\glm.hpp>
#include <memory>
struct vertex {
	glm::vec3 position, normal;
	glm::vec2 uv;
	vertex() {}
	vertex(glm::vec3 _position, glm::vec3 _normal, glm::vec2 _uv) :
		position{ _position }, normal{ _normal }, uv{ _uv }
	{
	}
	vertex(glm::vec3 _position, glm::vec3 _normal) :
		position{ _position }, normal{ _normal }, uv{ 0,0 }
	{
	}
	vertex(glm::vec3 _position) :position{ _position }, normal{ 0,0,0 }, uv{ 0,0 }
	{

	}
};

class Geometry
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	GLuint indices_count;
	Geometry() {}
	static void CubeGenerator(std::vector<vertex> & vertices, std::vector<GLuint> &indices);
	static void Quad(int a, int b, int c, int d, std::vector<vertex> & vertices, std::vector<GLuint> &indices, int startIndex);
public:
	Geometry(std::vector<vertex> vertices, std::vector<GLuint> indices);
	~Geometry();
	static std::shared_ptr<Geometry> Create_cube();
	GLuint GetIndicesCount() const { return indices_count; }
	GLuint GetVAO() const { return vao; }
	void Bind()const { glBindVertexArray(vao); }
	//static Geometry Create_sphere(int iterations);
};