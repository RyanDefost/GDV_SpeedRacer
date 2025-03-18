#include "ObstacleSpawner.h"

ObstacleSpawner::ObstacleSpawner()
{
}

void ObstacleSpawner::Spawn(int amount, Obstacle obstacleType)
{
	for (size_t i = 0; i < amount; i++)
	{
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
		currentObstacles[i].Update();
		currentObstacles[i].Display(window);
	}
}

bool ObstacleSpawner::CheckCollisions(Collision collider)
{
	int listSize = currentObstacles.size();
	for (int i = 0; i < listSize; i++)
	{
		bool isColliding = collider.CheckCollision(currentObstacles[i].collider);
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

