#pragma once
#include "Obstacle.h"

class Obstacle;

class BaseState
{
public:
	virtual void Enter(Obstacle* obstacle) = 0;
	virtual void Toggle(Obstacle* obstacle) = 0;
	virtual void Update(Obstacle* obstacle) = 0;
	virtual void Exit(Obstacle* obstacle) = 0;

	virtual ~BaseState() {}
};

