#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Collision.h"

class Wall : public PhysicsObject
{
public:
	Wall(Vector2 Pos = Vector2::zero, Vector2 clSize = {1,1});
	void Display(sf::RenderWindow&, sf::Color);

	Collision collider;
};

