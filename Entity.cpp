#include "Entity.h"

void Entity::Destroy()
{

}

void Entity::SetPosition(Vector2 pos)
{
	this->position.x = pos.x;
	this->position.y = pos.y;
}

Vector2 Entity::GetPosition()
{
	return this->position;
}

void Entity::SetSize(Vector2 size)
{
	this->Scale.x = size.x;
	this->Scale.y = size.y;
}

Vector2 Entity::GetSize()
{
	return this->Scale;
}
