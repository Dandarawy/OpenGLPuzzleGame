#include "CubeMappingMaterial.h"



CubeMappingMaterial::CubeMappingMaterial(std::shared_ptr<sf::Shader> shader, std::shared_ptr<CubeMap> cubeMap) :
	Material(shader),
	cubeMap(cubeMap)
{
}

void CubeMappingMaterial::Bind()
{
	Material::Bind();
	cubeMap->Bind();
}

CubeMappingMaterial::~CubeMappingMaterial()
{
}
