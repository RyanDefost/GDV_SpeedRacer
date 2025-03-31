#pragma once
#include "Obstacle.h"

class Obstacle;

class BaseObstacleState
{
public:
	virtual void Enter(Obstacle* obstacle) {};
	virtual void Toggle(Obstacle* obstacle) {};
	virtual void Update(Obstacle* obstacle) {};
	virtual void Exit(Obstacle* obstacle) {};

	virtual ~BaseObstacleState() {}
};