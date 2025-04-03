#include "Collision.h"
#include <iostream>

void Collision::SetPosition(Vector2 vector)
{
    this->Position = vector;
}

void Collision::SetSize(Vector2 vector)
{
    this->size = vector;
}

bool Collision::CheckCollision(Collision collider)
{
    Vector2 pos1 = collider.Position;
    Vector2 pos2 = this->Position;


    Vector2 distance = pos1 - pos2;
    if (distance.magnitude() <= (this->size.x/2 + collider.size.x/2)) 
    {
        this->isColliding = true;
        return true;
    }
    else 
    {
        this->isColliding = false;
        return false;
    }
    
}

bool Collision::CheckBoxCollision(Collision collider)
{
    Vector2 pos1 = collider.Position;
    Vector2 pos2 = this->Position;

    //AABB-collision
    if (pos1.x < pos2.x + collider.size.x &&
        pos1.x + this->size.x > pos2.x &&
        pos1.y < pos2.y + collider.size.y &&
        pos1.y + this->size.y > pos2.y)
    {
        this->isColliding = true;
        return true;
    }

    this->isColliding = false;
    return false;
}

bool Collision::operator==(Collision* collider)
{
    return (std::addressof(*this) == collider);
}
