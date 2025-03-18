#include "SlowEnemyState.h"

void SlowEnemyState::Enter(Obstacle* obstacle)
{
	obstacle->SetSpeed(1);
}

void SlowEnemyState::Toggle(Obstacle* obstacle)
{
	obstacle->SetState(FastEnemyState::getInstance());
}

void SlowEnemyState::Update(Obstacle* obstacle)
{

}

void SlowEnemyState::Exit(Obstacle* obstacle)
{
}

BaseState& SlowEnemyState::getInstance()
{
	static SlowEnemyState singelton;
	return singelton;
}

SlowEnemyState& SlowEnemyState::operator=(const SlowEnemyState& other)
{
	// TODO: insert return statement here
}