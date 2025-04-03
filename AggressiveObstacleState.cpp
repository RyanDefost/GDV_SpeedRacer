#include "AggressiveObstacleState.h"
#include "CalmObstacleState.h"
#include <iostream>
#include <cmath>

AggressiveObstacleState::AggressiveObstacleState()
{
    this->player = &Player::GetInstance();
}

void AggressiveObstacleState::Enter(Obstacle* obstacle)
{
    obstacle->SetSpeed(2);
    RandomizeSpeed(obstacle);

    obstacle->SetConstantSpeed({ 0,10 });
}

/// <summary>
/// Runs every cycle and checks if the state should be changed.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void AggressiveObstacleState::Update(Obstacle* obstacle)
{
    //Check if position is at the bottom of the screen.
    if (obstacle->GetPosition().y > 650) 
    {
        obstacle->SetState(CalmObstacleState::GetInstance());
        return;
    }

    Vector2 playerDirection = GetPlayerDiraction(obstacle);
    obstacle->AddForce(Vector2({ playerDirection.x * this->followSpeedMultiplier, 0}));
}

/// <summary>
/// Gets the direction towards the player given the current obstacle.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
/// <returns> The direction towards the player.</returns>
Vector2 AggressiveObstacleState::GetPlayerDiraction(Obstacle* obstacle) 
{
    Vector2 obstaclePosition = obstacle->GetPosition();
    Vector2 playerPosition = this->player->GetPosition();

    Vector2 frontPlayerPosition = Vector2({ playerPosition.x, obstaclePosition.y });

    Vector2 diraction =  obstaclePosition - frontPlayerPosition;
    diraction = -diraction.Normalized(diraction);

    return diraction;
}

BaseObstacleState& AggressiveObstacleState::GetInstance()
{
    static AggressiveObstacleState singelton;
    return singelton;
}

/// <summary>
/// Randomizes the current speed of the obstacle within the given amount.
/// </summary>
/// <param name="obstacle"> The obstacle that currently has this state.</param>
void AggressiveObstacleState::RandomizeSpeed(Obstacle* obstacle)
{
    float addedSpeed = rand() % 2;
    obstacle->SetSpeed(obstacle->GetSpeed() + addedSpeed);
}