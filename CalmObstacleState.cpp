#include "CalmObstacleState.h"
#include "ZigZagObstacleState.h"
#include <iostream>

void CalmObstacleState::Enter(Obstacle* obstacle)
{
	obstacle->SetSpeed(1);
	RandomizeSpeed(obstacle);

	obstacle->SetConstantSpeed({ 0,10 });

	std::cout << "CalmObstacle" << "\n";
}

void CalmObstacleState::Toggle(Obstacle* obstacle)
{
	obstacle->SetState(ZigZagObstacleState::getInstance());
}

void CalmObstacleState::Update(Obstacle* obstacle)
{
	if (obstacle->collider.GetColliding()) {
		obstacle->ToggleState();
	}
}

void CalmObstacleState::Exit(Obstacle* obstacle)
{

}

BaseObstacleState& CalmObstacleState::getInstance()
{
	static CalmObstacleState singelton;
	return singelton;
}

void CalmObstacleState::RandomizeSpeed(Obstacle* obstacle)
{
	float addedSpeed = rand() % 5;
	obstacle->SetSpeed(obstacle->GetSpeed() + addedSpeed);
}