#pragma once
#include "Obstacle.h"
#include "Player.h"
#include "BaseObstacleState.h"

class AggressiveObstacleState : public BaseObstacleState
{
public:
	AggressiveObstacleState();

	void Enter(Obstacle* obstacle);
	void Update(Obstacle* obstacle);
	void Exit(Obstacle* obstacle) {};

	static BaseObstacleState& GetInstance();

private:
	Player* player;
	float followSpeedMultiplier = 10;

	Vector2 GetPlayerDiraction(Obstacle* obstacle);
	void RandomizeSpeed(Obstacle* obstacle);
};

