#pragma once
#include "Obstacle.h"
#include "BaseState.h"

class FastEnemyState : public BaseState
{
public:
	void Enter(Obstacle* obstacle);
	void Toggle(Obstacle* obstacle);
	void Update(Obstacle* obstacle);
	void Exit(Obstacle* obstacle);
	static BaseState& getInstance();

private:
	FastEnemyState();
	FastEnemyState(const FastEnemyState& other);
	FastEnemyState& operator=(const FastEnemyState& other);
};

