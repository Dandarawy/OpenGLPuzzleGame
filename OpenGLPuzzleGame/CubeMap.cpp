#include "CubeMap.h"

CubeMap::CubeMap(int _texture_id)
{
	texture_id = _texture_id;
}


void CubeMap::Bind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id);
}

std::shared_ptr<CubeMap> CubeMap::Create(std::string imagesFileNames[6])
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < 6; i++)
	{
		sf::Image image;
		if (!image.loadFromFile(imagesFileNames[i]))
		{
			std::cout << "cannot load image " << imagesFileNames[i];
		}
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGB, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	return std::shared_ptr<CubeMap>(new CubeMap(textureID));
}

CubeMap::~CubeMap()
{
}
