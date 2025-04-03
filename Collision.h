#pragma once
#include "Vector2.h"

class Collision
{
public:
	void SetPosition(Vector2);
	void SetSize(Vector2);

	bool CheckCollision(Collision);
	bool CheckBoxCollision(Collision);
	bool GetIsColliding() { return isColliding; }

	Vector2 Position;
	Vector2 size = {1,1};

	bool operator==(Collision*);

protected:
	bool isColliding;

	float radius = size.x / 2;
};

