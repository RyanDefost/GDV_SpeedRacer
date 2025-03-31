#include "ScoreSystem.h"
#include <iostream>

void ScoreSystem::UpdateScore(float addedValue)
{
	currentScore = currentScore + addedValue;
}

ScoreSystem& ScoreSystem::getInstance()
{
    static ScoreSystem singelton;
    return singelton;
}
