#include "Wall.h"
#include <iostream>

Wall::Wall(Vector2 Pos, Vector2 clSize)
{
	SetSize(clSize);
	//Pos.x = Pos.x - (GetSize().x / 2);
	SetPosition(Pos);

	collider.SetSize(clSize);
	collider.SetPosition(GetPosition());
}

void Wall::Display(sf::RenderWindow& window, sf::Color color = sf::Color::White)
{
	sf::RectangleShape shape({ collider.size.x, collider.size.y });
	shape.setPosition({ collider.Position.x, collider.Position.y });
	shape.setFillColor(sf::Color::White);

	window.draw(shape);
}