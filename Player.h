#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Collision.h"

class Player: public PhysicsObject
{
public:
	Player(Vector2 pos = Vector2{ 0,0 }, Vector2 s = Vector2{ 0,0 });

	void Display(sf::RenderWindow&, sf::Texture);
	void Update();

	static Player& GetInstance();

	Collision collider;
};

