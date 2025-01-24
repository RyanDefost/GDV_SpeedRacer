#include "GameOverScreen.h"



void GameOverScreen::Display(sf::RenderWindow& window)
{
    
    if (!font.loadFromFile("Assets/arial.ttf"))
        std::cout << "FAILED TO LOAD FONT";

    text.setFont(font);
    text.setString("You LOST");
    text.setCharacterSize(48);
    text.setPosition(window.getSize().x/2 - 120, window.getSize().y / 2);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    window.draw(text);

	window.display();
}
