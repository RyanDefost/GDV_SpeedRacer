#include "ZigZagObstacleState.h"
#include "CalmObstacleState.h"
#include <iostream>

void ZigZagObstacleState::Enter(Obstacle* obstacle)
{
    obstacle->SetSpeed(2);
    RandomizeSpeed(obstacle);

    obstacle->SetConstantSpeed({ 5,10 });
    obstacle->RandomizeValues();
}

/// <summary>
/// Runs every cycle and checks if the state should be changed.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void ZigZagObstacleState::Update(Obstacle* obstacle)
{
    //Check if position is at the bottom of the screen.
    if (obstacle->GetPosition().y > 650) 
    {
        obstacle->SetState(CalmObstacleState::GetInstance());
        return;
    }

    //If colliding with edge boost to other direction.
    if (obstacle->DetectEdge()) 
    {
        obstacle->AddForce({ -obstacle->currentForce.y * 2 , 0});
    }
}

BaseObstacleState& ZigZagObstacleState::GetInstance()
{
    static ZigZagObstacleState singelton;
    return singelton;
}

/// <summary>
/// Randomizes the current speed of the obstacle within the given amount.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void ZigZagObstacleState::RandomizeSpeed(Obstacle* obstacle)
{
    float addedSpeed = rand() % 2;
    obstacle->SetSpeed(obstacle->GetSpeed() + addedSpeed);
}
