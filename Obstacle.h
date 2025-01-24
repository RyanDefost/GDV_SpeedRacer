#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Collision.h"
#include "ScoreSystem.h"

class Obstacle : public PhysicsObject
{
public:
	Obstacle(Vector2 s = Vector2{ 10,10 }, float sp = 1, Vector2 cF = {0,1});

	void Display(sf::RenderWindow&, sf::Texture);
	void Update();

	bool DetectEdge();
	void SetSpawnPosition();
	void SetScoreSystem(ScoreSystem&);

	void RandomizeValues();

	Collision collider;

private:
	float _speed;
	Vector2 constantForce;

	Vector2 windowSize = {840, 650};
	ScoreSystem* _scoreSystem;
};

