#include "FastEnemyState.h"

void FastEnemyState::Enter(Obstacle* obstacle)
{
    obstacle->SetSpeed(2.6);
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

FastEnemyState& FastEnemyState::operator=(const FastEnemyState& other)
{
    // TODO: insert return statement here
}
