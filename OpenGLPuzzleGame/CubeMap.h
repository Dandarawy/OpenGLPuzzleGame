#include <memory>
#include <string>
#include <glew\glew.h>
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <iostream>
class CubeMap
{
	int texture_id;
	CubeMap(int texture_id);
public:
	void Bind();
	static std::shared_ptr<CubeMap> Create(std::string texturesFilesNames[6]);
	~CubeMap();
};

