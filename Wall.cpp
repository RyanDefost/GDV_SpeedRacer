#include "Wall.h"
#include <iostream>

Wall::Wall(Vector2 Pos, Vector2 clSize)
{
	SetSize(clSize);
	SetPosition(Pos);

	this->collider.SetSize(clSize);
	this->collider.SetPosition(GetPosition());
}

void Wall::Display(sf::RenderWindow& window, sf::Color color = sf::Color::White)
{
	sf::RectangleShape shape({ this->collider.size.x, this->collider.size.y });
	shape.setPosition({ this->collider.Position.x, this->collider.Position.y });
	shape.setFillColor(sf::Color::White);

	window.draw(shape);
}