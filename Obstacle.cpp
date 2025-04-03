#include "Obstacle.h"
#include "CalmObstacleState.h"
#include "ZigZagObstacleState.h"
#include "AggressiveObstacleState.h"
#include <ctime>
#include <random>

Obstacle::Obstacle(ScoreSystem* sc, sf::Texture im, Vector2 s, float sp, Vector2 cF)
{
	this->speed = sp;
	this->texture = im;
	this->constantForce = cF;

	SetSize(s);
	RandomizeValues();

	SetSpawnPosition();

	this->collider.SetSize(s);
	this->collider.SetPosition(GetPosition());

	this->currentState = &AggressiveObstacleState::GetInstance();
	this->currentState->Enter(this);
}

/// <summary>
/// Sets the next state of the obstacle and call the Exit() and Enter() functions.
/// </summary>
/// <param name="newState" The state that should be enterd.></param>
void Obstacle::SetState(BaseObstacleState& newState)
{
	this->currentState->Exit(this);
	this->currentState = &newState;
	this->currentState->Enter(this);
}

void Obstacle::Display(sf::RenderWindow& window)
{
	this->windowSize = { (float)window.getSize().x, (float)window.getSize().y};

	sf::Sprite sprite(this->texture);
	sprite.setPosition(this->position.x - this->Scale.x / 2, this->position.y - this->Scale.y / 2);

	window.draw(sprite);
}

/// <summary>
/// Runs every cycle and updates every system inside the obstacle.
/// </summary>
void Obstacle::Update()
{
	SetForce(Vector2{ this->constantForce.x, this->constantForce.y } * this->speed);
	
	this->currentState->Update(this);

	UpdatePhysics();
	this->collider.SetPosition(GetPosition());

	if (GetPosition().y > this->windowSize.y + GetSize().y * 2) 
	{

		SetSpawnPosition();
		this->scoreSystem->UpdateScore(100);
	}
}

/// <summary>
/// Detects the edge of the screen and reverses the force of the obstacle.
/// </summary>
/// <returns> Returns if obstacle has reached the edge.</returns>
bool Obstacle::DetectEdge()
{
	if (this->position.x < 175 || this->position.x > this->windowSize.x - 175) 
	{
		this->constantForce.x = -this->constantForce.x;
		return true;
	}

	return false;
}

/// <summary>
/// Sets a new random locations for the obstacle at the top of the screen.
/// </summary>
void Obstacle::SetSpawnPosition()
{
	srand((unsigned int)((int)this->time + rand() % 101));

	float size = GetSize().x;

	int spacingX = (this->windowSize.x - 350) / size;
	float spawnOffset = (rand() % spacingX);
	float spawnOffsetY = (rand() % 500);

	if (spawnOffset == 0)
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50});
	else
		SetPosition({ (spawnOffset * size)+175, -spawnOffsetY + -50 });
}

void Obstacle::SetScoreSystem(ScoreSystem* scoreSystem)
{
	this->scoreSystem = scoreSystem;
}

/// <summary>
/// Randomizes the direction the obstacle is moving in the x direction.
/// </summary>
void Obstacle::RandomizeValues()
{
	int zeroOne = rand() % 1;
	this->constantForce.x = zeroOne == 1 ? -this->constantForce.x : this->constantForce.x;
}

void Obstacle::Destroy()
{
	delete this->scoreSystem;
}

bool Obstacle::operator==(Obstacle obstacle)
{
	return (std::addressof(*this) == std::addressof(obstacle));
}
