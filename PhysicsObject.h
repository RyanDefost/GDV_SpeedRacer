#pragma once
#include "Entity.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class PhysicsObject: public Entity
{
public:
	void UpdatePhysics();
	void AddForce(Vector2);
	void SetForce(Vector2);

	void CalculateAcceleration();

	Vector2 currentForce = Vector2::zero;
protected:
	Vector2 velocity = Vector2::zero;
	float speed = 0.5;
	float maxSpeed = 10;

	float mass = 1;
	float friction = 0.1;

	Vector2 acceleration = Vector2::zero;
	Vector2 grafity = { 0,0 };

	sf::Clock clock;
	float _time = 1;

private:
};

