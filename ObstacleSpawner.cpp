#include "ObstacleSpawner.h"
#include "ZigZagObstacleState.h"
#include <iostream>

ObstacleSpawner::ObstacleSpawner()
{
}

/// <summary>
/// Creates the given amount of instances of the obstacle to spawn inside the game.
/// </summary>
/// <param name="amount"> The amount of obstacles that should be spawned.</param>
void ObstacleSpawner::Spawn(int amount)
{
	ScoreSystem* scoresystem = &ScoreSystem::GetInstance();

	sf::Texture car;
	if (!car.loadFromFile("Assets/YellowBuggy.png"))
		std::cout << "FAILED TO LOAD IMAGE";


	for (size_t i = 0; i < amount; i++)
	{
		Obstacle obstacleType = Obstacle(scoresystem, car, { 40,60 }, 2.6, { 0,10 });
		AddObstacle(obstacleType);
	}
}

void ObstacleSpawner::Despawn()
{

}

/// <summary>
/// Runs every cycle and loops over every obstacle to call their Update() and Display() functions.
/// </summary>
/// <param name="window"> The screen space that objects are drawn on to.</param>
void ObstacleSpawner::UpdateObstacles(sf::RenderWindow& window)
{
	int listSize = this->currentObstacles.size();
	for (int i = 0; i < listSize; i++)
	{
		CheckCollisions(&this->currentObstacles[i].collider);

		this->currentObstacles[i].Update();
		this->currentObstacles[i].Display(window);
	}
}

/// <summary>
/// Loops over every obstacle and checks if there are any collisions between them.
/// </summary>
/// <param name="collider"> The collider of the current obstacle that is checked.</param>
/// <returns> Returns true if there is a collision.</returns>
bool ObstacleSpawner::CheckCollisions(Collision* collider)
{
	int listSize = this->currentObstacles.size();
	for (int i = 0; i < listSize; i++)
	{
		if (collider == &this->currentObstacles[i].collider)
			continue;

		bool isColliding = collider->CheckCollision(this->currentObstacles[i].collider);
		if (isColliding) {
			return true;
		}
	}

	return false;
}

/// <summary>
/// Adds the obstacle to the list of current obstacles.
/// </summary>
/// <param name="obstacle">The added obstacle.</param>
void ObstacleSpawner::AddObstacle(Obstacle obstacle)
{
	this->currentObstacles.push_back(obstacle);
}

/// <summary>
/// Removes the obstacle from the list of current obstacles.
/// </summary>
/// <param name="obstacle">The removed obstacle.</param>
void ObstacleSpawner::RemoveObstacle(Obstacle obstacle)
{
	int listSize = this->currentObstacles.size();

	for (int i = 0; i < listSize; i++)
	{
		if (this->currentObstacles[i] == obstacle) 
		{
			this->currentObstacles.erase(this->currentObstacles.begin() + i);
			return;
		}
	}
}

