#include "ScoreSystem.h"
#include <iostream>

void ScoreSystem::UpdateScore(float addedValue)
{
    this->currentScore = currentScore + addedValue;
}

ScoreSystem& ScoreSystem::GetInstance()
{
    static ScoreSystem singelton;
    return singelton;
}
