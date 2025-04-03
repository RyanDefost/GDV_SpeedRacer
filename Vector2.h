#pragma once
#include <array>

class Vector2
{
public:
	float x;
	float y;

	static Vector2 zero;
	static Vector2 left;
	static Vector2 right;
	static Vector2 up;
	static Vector2 down;

	Vector2 operator*(Vector2);
	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);
	Vector2 operator*(float);
	Vector2 operator+(float);
	Vector2 operator/(float);
	Vector2 operator-();

	Vector2 operator+=(Vector2);

	float magnitude();
	Vector2 normalized(Vector2);
};

