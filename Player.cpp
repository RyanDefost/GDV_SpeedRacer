#include "Player.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>


Player::Player(Vector2 pos, Vector2 s)
{
	SetSize(s);
	SetPosition(pos);

	collider.SetSize(s);
}

void Player::Display(sf::RenderWindow& window,sf::Texture image)
{
	sf::Sprite sprite(image);
	sprite.setPosition(position.x - Scale.x / 2, position.y - Scale.y / 2);

	window.draw(sprite);
}

void Player::Update()
{
	UpdatePhysics();
	collider.SetPosition(GetPosition() - GetSize()/2);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		AddForce({ 0,-1 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		AddForce({ 0, 1 });
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		AddForce({ -2,0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		AddForce({ 2,0 });
	}
	else {
		clock.restart().asSeconds();
	}
}
