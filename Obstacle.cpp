#include "Obstacle.h"
#include "CalmObstacleState.h"
#include "ZigZagObstacleState.h"
#include <ctime>
#include <random>

Obstacle::Obstacle(ScoreSystem* sc, sf::Texture im, Vector2 s, float sp, Vector2 cF)
{
	_speed = sp;
	_texture = im;
	constantForce = cF;

	SetSize(s);
	RandomizeValues();
	SetScoreSystem(sc);

	SetSpawnPosition();

	collider.SetSize(s);
	collider.SetPosition(GetPosition());

	currentState = &CalmObstacleState::getInstance();
	currentState->Enter(this);
}

void Obstacle::ToggleState()
{
	currentState->Toggle(this);
}

void Obstacle::SetState(BaseObstacleState& newState)
{
	currentState->Exit(this);
	currentState = &newState;
	currentState->Enter(this);
}

void Obstacle::Display(sf::RenderWindow& window)
{
	windowSize = { (float)window.getSize().x, (float)window.getSize().y};

	sf::Sprite sprite(_texture);
	sprite.setPosition(position.x - Scale.x / 2, position.y - Scale.y / 2);

	window.draw(sprite);
}

void Obstacle::Update()
{
	currentState->Update(this);

	SetForce(Vector2{ constantForce.x, constantForce.y } * _speed);

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
		return true;
	}

	return false;
}

void Obstacle::SetSpawnPosition()
{
	srand((unsigned int)((int)time + rand() % 100));

	float size = GetSize().x;

	int spacingX = (windowSize.x - 350) / size;
	float spawnOffset = (rand() % spacingX);
	float spawnOffsetY = (rand() % 500);

	if (spawnOffset == 0)
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50});
	else
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50 });
}

void Obstacle::SetScoreSystem(ScoreSystem* scoreSystem)
{
	_scoreSystem = scoreSystem;
}

void Obstacle::RandomizeValues()
{
	int zeroOne = rand() % 1;
	constantForce.x = zeroOne == 1 ? -constantForce.x : constantForce.x;

	SetSpawnPosition();
}

void Obstacle::Destroy()
{
	delete _scoreSystem;
}

bool Obstacle::operator==(Obstacle obstacle)
{
	return (std::addressof(*this) == std::addressof(obstacle));
}
