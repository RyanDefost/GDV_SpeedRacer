#include "ZigZagObstacleState.h"
#include "CalmObstacleState.h"
#include <iostream>

void ZigZagObstacleState::Enter(Obstacle* obstacle)
{
    obstacle->SetSpeed(2);
    RandomizeSpeed(obstacle);

    obstacle->SetConstantSpeed({ 5,10 });
    std::cout << "ZigZagObstacle" << "\n";
}

void ZigZagObstacleState::Toggle(Obstacle* obstacle)
{
    obstacle->SetState(CalmObstacleState::getInstance());
}

void ZigZagObstacleState::Update(Obstacle* obstacle)
{
    obstacle->DetectEdge();
}

void ZigZagObstacleState::Exit(Obstacle* obstacle)
{
}


BaseObstacleState& ZigZagObstacleState::getInstance()
{
    static ZigZagObstacleState singelton;
    return singelton;
}

void ZigZagObstacleState::RandomizeSpeed(Obstacle* obstacle)
{
    float addedSpeed = rand() % 2;
    obstacle->SetSpeed(obstacle->GetSpeed() + addedSpeed);
}
