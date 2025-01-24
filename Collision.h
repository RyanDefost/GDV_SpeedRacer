#pragma once
#include "Vector2.h"

class Collision
{
public:
	void SetPosition(Vector2);
	void SetSize(Vector2);

	bool CheckCollision(Collision);
	bool CheckBoxCollision(Collision);
	Vector2 Position;

	Vector2 size = {1,1};
protected:
	float radius = size.x / 2;

private:

};

