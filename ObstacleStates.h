#pragma once
#include <map>

enum class ObstacleStates
{
	NONE,
	SLOW,
	MEDIUM,
	FAST
};

std::map<ObstacleStates, ObstacleStates> ObstacleTransitions = {
		{ObstacleStates::NONE, ObstacleStates::SLOW},
		{ObstacleStates::NONE, ObstacleStates::MEDIUM},
		{ObstacleStates::NONE, ObstacleStates::FAST},

		{ObstacleStates::FAST, ObstacleStates::NONE},
};

