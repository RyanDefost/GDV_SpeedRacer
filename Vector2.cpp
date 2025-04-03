#include "Vector2.h"
#include <iostream>

Vector2 Vector2::zero	= { 0,0 };
Vector2 Vector2::left	= { -1,0 };
Vector2 Vector2::right	= { 1,0 };
Vector2 Vector2::up		= { 0,-1 };
Vector2 Vector2::down	= { 0,1 };

Vector2 Vector2::operator*(Vector2 vector)
{
	vector.x = this->x * vector.x;
	vector.y = this->y * vector.y;
	return vector;
}

Vector2 Vector2::operator+(Vector2 vector)
{
	vector.x = this->x + vector.x;
	vector.y = this->y + vector.y;
	return vector;
}

Vector2 Vector2::operator-(Vector2 vector)
{
	vector.x = this->x - vector.x;
	vector.y = this->y - vector.y;
	return vector;
}

Vector2 Vector2::operator*(float f)
{
	return Vector2{ f * this->x, f * this->y };
}

Vector2 Vector2::operator+(float f)
{
	return Vector2{ f + this->x, f + this->y };
}

Vector2 Vector2::operator/(float f)
{
	if (f == 0 && this->x == 0 && this->y == 0)
		return Vector2{ 0,0 };

	return Vector2{ this->x / f, this->y / f};
}

Vector2 Vector2::operator-()
{
	return {-this->x, -this->y};
}

Vector2 Vector2::operator+=(Vector2 vector)
{
	this->x = this->x + vector.x;
	this->y = this->y + vector.y;
	return *this;
}

float Vector2::magnitude()
{
	return sqrt((this->x * this->x) + (this->y * this->y));
}

Vector2 Vector2::normalized(Vector2 vector)
{
	Vector2 originalVector = vector;
	float magnitude = vector.magnitude();
	
	Vector2 normalizedVector = originalVector / magnitude;
	return normalizedVector;
}
