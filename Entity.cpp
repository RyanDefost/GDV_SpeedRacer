#include "Entity.h"

void Entity::Destroy()
{

}

void Entity::SetPosition(Vector2 pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

Vector2 Entity::GetPosition()
{
	return position;
}

void Entity::SetSize(Vector2 size)
{
	Scale.x = size.x;
	Scale.y = size.y;
}

Vector2 Entity::GetSize()
{
	return Scale;
}
