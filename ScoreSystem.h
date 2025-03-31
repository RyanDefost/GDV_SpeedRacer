#pragma once
class ScoreSystem
{
public:
	int currentScore = 0;
	void UpdateScore(float addedValue);

	static ScoreSystem& getInstance();

protected:

private:

};

