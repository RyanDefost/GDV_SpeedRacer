#include "CalmObstacleState.h"
#include "ZigZagObstacleState.h"
#include "AggressiveObstacleState.h"
#include <iostream>

void CalmObstacleState::Enter(Obstacle* obstacle)
{
	obstacle->SetSpeed(1);
	RandomizeSpeed(obstacle);

	obstacle->SetConstantSpeed({ 0,10 });
}

/// <summary>
/// Runs every cycle and checks if the state should be changed.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void CalmObstacleState::Update(Obstacle* obstacle)
{
	//Checks if obstacle is colliding with another obstacle.
	if (obstacle->collider.GetIsColliding()) {
		obstacle->SetState(ZigZagObstacleState::GetInstance());
	}

	//Check if position is at the bottom of the screen.
	if (obstacle->GetPosition().y > 650) 
	{

		if (GetRandomizedBool(1, 10)) 
		{
			obstacle->SetState(AggressiveObstacleState::GetInstance());
			return;
		}
	}
}

BaseObstacleState& CalmObstacleState::GetInstance()
{
	static CalmObstacleState singelton;
	return singelton;
}

/// <summary>
/// Randomizes the current speed of the obstacle within the given amount.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void CalmObstacleState::RandomizeSpeed(Obstacle* obstacle)
{
	float addedSpeed = rand() % 5;
	obstacle->SetSpeed(obstacle->GetSpeed() + addedSpeed);
}

bool CalmObstacleState::GetRandomizedBool(int chance, int totalAmount) 
{
	int randomNumber = rand() % (totalAmount+1);

	if (randomNumber <= chance) 
	{
		return true;
	}

	return false;
}