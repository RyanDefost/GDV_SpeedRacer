#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class GameOverScreen
{
public:
	void Display(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Font font;
};

