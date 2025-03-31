#include "ObstacleSpawner.h"
#include "ZigZagObstacleState.h"
#include <iostream>

ObstacleSpawner::ObstacleSpawner()
{
}

void ObstacleSpawner::Spawn(int amount)
{
	ScoreSystem* scoresystem = &ScoreSystem::getInstance();

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

void ObstacleSpawner::UpdateObstacles(sf::RenderWindow& window)
{
	int listSize = currentObstacles.size();
	for (int i = 0; i < listSize; i++)
	{
		CheckCollisions(&currentObstacles[i].collider);

		currentObstacles[i].Update();
		currentObstacles[i].Display(window);
	}
}

bool ObstacleSpawner::CheckCollisions(Collision* collider)
{
	int listSize = currentObstacles.size();
	for (int i = 0; i < listSize; i++)
	{
		if (collider == &currentObstacles[i].collider)
			continue;

		bool isColliding = collider->CheckCollision(currentObstacles[i].collider);
		if (isColliding) {
			return true;
		}
	}

	return false;
}

void ObstacleSpawner::AddObstacle(Obstacle obstacle)
{
	currentObstacles.push_back(obstacle);
}

void ObstacleSpawner::RemoveObstacle(Obstacle obstacle)
{
	int listSize = currentObstacles.size();

	for (int i = 0; i < listSize; i++)
	{
		if (currentObstacles[i] == obstacle) {
			currentObstacles.erase(currentObstacles.begin() + i);
			return;
		}
	}
}

