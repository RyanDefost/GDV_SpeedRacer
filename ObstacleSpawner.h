#pragma once
#include "Obstacle.h"
#include <vector>

using std::vector;

class ObstacleSpawner
{
public:
	ObstacleSpawner();

	void Spawn(int amount);
	void Despawn();

	void UpdateObstacles(sf::RenderWindow& window);
	bool CheckCollisions(Collision* collider);

protected:
	void AddObstacle(Obstacle obstacle);
	void RemoveObstacle(Obstacle obstacle);


	vector<Obstacle> currentObstacles = {};
};

