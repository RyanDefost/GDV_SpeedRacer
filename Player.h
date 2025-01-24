#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Collision.h"

class Player: public PhysicsObject
{
public:
	Player(Vector2 pos, Vector2 s);

	void Display(sf::RenderWindow&, sf::Texture);
	void Update();

	Collision collider;
protected:
	
private:
};

