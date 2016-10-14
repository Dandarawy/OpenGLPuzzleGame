#pragma once
#include "Material.h"
class UnlitTextureMaterial :
	public Material
{
	glm::vec2 offset;
	glm::vec2 tilling;
	glm::vec3 tint;
public:
	UnlitTextureMaterial(std::shared_ptr<sf::Shader> shader);
	void Bind() override;
	~UnlitTextureMaterial();
	void setOffset(glm::vec2 offset) { this->offset = offset; }
	void setTilling(glm::vec2 tilling) { this->tilling = tilling; }
	void setTint(glm::vec3 tint) { this->tint = tint; }

	glm::vec2 getOffset() const { return offset; }
	glm::vec2 getTilling() const { return tilling; }
	glm::vec3 getTint() const { return tint; }
};