#include "FastEnemyState.h"
#include "SlowEnemyState.h"

void FastEnemyState::Enter(Obstacle* obstacle)
{
    obstacle->SetSpeed(10);
}

void FastEnemyState::Toggle(Obstacle* obstacle)
{
    obstacle->SetState(SlowEnemyState::getInstance());
}

void FastEnemyState::Update(Obstacle* obstacle)
{
}

void FastEnemyState::Exit(Obstacle* obstacle)
{
}


BaseState& FastEnemyState::getInstance()
{
    static FastEnemyState singelton;
    return singelton;
}