#pragma once
#include "Material.h"
#include "CubeMap.h"
#include <memory>
class CubeMappingMaterial :
	public Material
{
private:
	std::shared_ptr<CubeMap> cubeMap;
public:
	CubeMappingMaterial(std::shared_ptr<sf::Shader> shader, std::shared_ptr<CubeMap> cubeMap);
	void Bind();
	~CubeMappingMaterial();
};

