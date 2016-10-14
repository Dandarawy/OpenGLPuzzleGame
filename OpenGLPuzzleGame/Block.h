////////////////////////////////////////////
//The minimum unit in the game
//everyting is made out of block, the player and map are blocks
////////////////////////////////////////////
#pragma once
#include "Mesh.h"
#include "Material.h"
#include <memory>
#include "Camera.h"
enum BlockState
{
	Sationary,
	Moving
};
class Block
{
private:
	Mesh mesh;
	float elapsedTime = 0;
	glm::vec3 startPosition;
	glm::vec3 targetPosition;
	float duration;
	BlockState state;
	glm::vec3 Tween();
public:
	Block(std::shared_ptr<Geometry> geom, std::shared_ptr<Material> mat);
	Block(std::shared_ptr<Geometry> geom, std::shared_ptr<Material> mat, glm::vec3 position);
	void Render(Camera cam);
	glm::vec3 GetPosition()const { return mesh.transform.GetPosition(); }
	void SetPosition(glm::vec3 position) { mesh.transform.SetPosition(position); }
	~Block();
	void MoveTo(glm::vec3 Pos, float duration);
	void Update(sf::Time dt);
	BlockState GetState()const { return state; }
};

