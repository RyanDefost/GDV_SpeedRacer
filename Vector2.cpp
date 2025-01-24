#include "Vector2.h"
#include <iostream>

Vector2 Vector2::zero	= { 0,0 };
Vector2 Vector2::left	= { -1,0 };
Vector2 Vector2::right	= { 1,0 };
Vector2 Vector2::up		= { 0,-1 };
Vector2 Vector2::down	= { 0,1 };

Vector2 Vector2::operator*(Vector2 vector)
{
	vector.x = x * vector.x;
	vector.y = y * vector.y;
	return vector;
}

Vector2 Vector2::operator+(Vector2 vector)
{
	vector.x = x + vector.x;
	vector.y = y + vector.y;
	return vector;
}

Vector2 Vector2::operator-(Vector2 vector)
{
	vector.x = x - vector.x;
	vector.y = y - vector.y;
	return vector;
}

Vector2 Vector2::operator*(float f)
{
	return Vector2{ f * x, f * y };
}

Vector2 Vector2::operator+(float f)
{
	return Vector2{ f + x, f + y };
}

Vector2 Vector2::operator/(float f)
{
	if (f == 0 && x == 0 && y == 0)
		return Vector2{ 0,0 };

	return Vector2{x / f, y / f};
}

Vector2 Vector2::operator-()
{
	return {-x, -y};
}

Vector2 Vector2::operator+=(Vector2 vector)
{
	x = x + vector.x;
	y = y + vector.y;
	return *this;
}

float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

Vector2 Vector2::normalized(Vector2 vector)
{
	Vector2 originalVector = vector;
	float magnitude = vector.magnitude();
	
	Vector2 normalizedVector = originalVector / magnitude;
	return normalizedVector;
}
