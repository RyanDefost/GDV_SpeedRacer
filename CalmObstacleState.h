#pragma once
#include "Obstacle.h"
#include "BaseObstacleState.h"

class CalmObstacleState : public BaseObstacleState
{
public:
	void Enter(Obstacle* obstacle);
	void Toggle(Obstacle* obstacle);
	void Update(Obstacle* obstacle);
	void Exit(Obstacle* obstacle);
	static BaseObstacleState& getInstance();

private:
	void RandomizeSpeed(Obstacle* obstacle);
};