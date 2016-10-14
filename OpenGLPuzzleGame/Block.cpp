#include "Block.h"
#include <iostream>

glm::vec3 Block::Tween()
{
	if (elapsedTime >= duration)
		return targetPosition;
	//linear
	//return from + (to - from)*(t/duration);
	//Quad Out
	return (elapsedTime / duration) * (elapsedTime / duration - 2) * -(targetPosition - startPosition) + startPosition;
}


Block::Block(std::shared_ptr<Geometry> geom, std::shared_ptr<Material> mat) :
	mesh(geom, mat),
	state(BlockState::Sationary)
{

}
Block::Block(std::shared_ptr<Geometry> geom, std::shared_ptr<Material> mat, glm::vec3 position) :
	mesh(geom, mat)
{
	mesh.transform.SetPosition(position);
}
void Block::Render(Camera cam)
{
	mesh.Render(cam.GetView(), cam.GetProj());
}

void Block::MoveTo(glm::vec3 Pos, float duration)
{
	if (state == BlockState::Sationary)
	{
		state = BlockState::Moving;
		startPosition = mesh.transform.GetPosition();
		targetPosition = Pos;
		this->duration = duration;
		elapsedTime = 0;
	}
}

void Block::Update(sf::Time dt)
{
	if (state == BlockState::Moving)
	{
		elapsedTime += dt.asSeconds();
		SetPosition(Tween());
		if (elapsedTime >= duration)
		{
			state = BlockState::Sationary;
		}
	}
}

Block::~Block()
{

}
