#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "PhysicsObject.h"
#include "Collision.h"
#include "ScoreSystem.h"
#include "BaseState.h"
#include "SlowEnemyState.h"
#include "FastEnemyState.h"

class BaseState;

class Obstacle : public PhysicsObject
{
public:
	Obstacle(ScoreSystem sc, sf::Texture image, Vector2 s = Vector2{ 10,10 }, float sp = 1, Vector2 cF = {0,1});

	inline BaseState* GetCurrentState() const { return currentState; }
	void ToggleState();
	void SetState(BaseState& newState);

	void Display(sf::RenderWindow& window);
	void Update();

	bool DetectEdge();
	void SetSpawnPosition();
	void SetScoreSystem(ScoreSystem&);

	void RandomizeValues();
	void SetSpeed(float value) { _speed = value; }

	void Destroy();

	bool operator==(Obstacle);

	Collision collider;
private:
	BaseState* currentState;

	float _speed;
	sf::Texture _texture;
	Vector2 constantForce;

	Vector2 windowSize = {840, 650};
	ScoreSystem* _scoreSystem;
};

