#pragma once

#include <string>
#include "Vector2.h"
#include <Vector>

using std::string;

class Entity
{
public:
	Entity() = default;
	void Destroy();

	void SetPosition(Vector2 position);
	Vector2 GetPosition();

	void SetSize(Vector2 size);
	Vector2 GetSize();

protected:
	Vector2 position = Vector2::zero;
	Vector2 Scale = {1,1};

private:
};