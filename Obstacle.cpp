#include "Obstacle.h"
#include <ctime>
#include <iostream>
#include <random>

Obstacle::Obstacle(Vector2 s, float sp, Vector2 cF)
{
	_speed = sp;
	constantForce = cF;

	SetSize(s);

	RandomizeValues();

	collider.SetSize(s);
	collider.SetPosition(GetPosition());
}

void Obstacle::Display(sf::RenderWindow& window, sf::Texture image)
{
	windowSize = { (float)window.getSize().x, (float)window.getSize().y};

	sf::Sprite sprite(image);
	sprite.setPosition(position.x - Scale.x / 2, position.y - Scale.y / 2);

	window.draw(sprite);
}

void Obstacle::Update()
{
	DetectEdge();
	SetForce({ constantForce.x, constantForce.y * _speed });

	UpdatePhysics();
	collider.SetPosition(GetPosition());

	if (GetPosition().y > windowSize.y + GetSize().y * 2) {
		SetSpawnPosition();
		_scoreSystem->UpdateScore(100);
	}
}

bool Obstacle::DetectEdge()
{
	if (position.x < 175 || position.x > windowSize.x - 175) {
		constantForce.x = -constantForce.x;
		std::cout << currentForce.x;
		return true;
	}

	return false;
}

void Obstacle::SetSpawnPosition()
{
	float size = GetSize().x;

	int spacingX = (windowSize.x - 350) / size;
	float spawnOffset = (rand() % spacingX);
	float spawnOffsetY = (rand() % 500);

	if (spawnOffset == 0)
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50});
	else
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50 });
}

void Obstacle::SetScoreSystem(ScoreSystem& scoreSystem)
{
	_scoreSystem = &scoreSystem;
}

void Obstacle::RandomizeValues()
{
	int zeroOne = rand() % 1;
	constantForce.x = zeroOne == 1 ? -constantForce.x : constantForce.x;

	SetSpawnPosition();
}
