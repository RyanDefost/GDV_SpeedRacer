#pragma once
#include "Obstacle.h"
#include "BaseState.h"

class SlowEnemyState : public BaseState
{
public:
	void Enter(Obstacle* obstacle);
	void Toggle(Obstacle* obstacle);
	void Update(Obstacle* obstacle);
	void Exit(Obstacle* obstacle);
	static BaseState& getInstance();

private:
	//SlowEnemyState();
	//SlowEnemyState(const SlowEnemyState& other);
};