#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "PhysicsObject.h"
#include "Collision.h"
#include "ScoreSystem.h"
#include <vector>
#include "BaseObstacleState.h"
#include <iostream>

using std::vector;

class BaseObstacleState;

class Obstacle : public PhysicsObject
{
public:
	Obstacle(ScoreSystem* sc, sf::Texture image, Vector2 s = Vector2{ 10,10 }, float sp = 1, Vector2 cF = { 0,1 });

	inline BaseObstacleState* GetCurrentState() const { return currentState; }
	void SetState(BaseObstacleState& newState);

	void Display(sf::RenderWindow& window);
	void Update();

	bool DetectEdge();
	void SetSpawnPosition();
	void SetScoreSystem(ScoreSystem*);

	void RandomizeValues();

	void SetConstantSpeed(Vector2 constantSpeed) { constantForce = constantSpeed; }
	void SetSpeed(float value) { speed = value; }
	float GetSpeed() { return speed; }
	
	void Destroy();

	bool operator==(Obstacle);

	Collision collider;

private:
	ScoreSystem* scoreSystem = &ScoreSystem::GetInstance();
	BaseObstacleState* currentState;

	float speed;
	sf::Texture texture;
	Vector2 constantForce;

	Vector2 windowSize = {840, 650};
};

