#include "GameOverScreen.h"



void GameOverScreen::Display(sf::RenderWindow& window)
{
    
    if (!this->font.loadFromFile("Assets/arial.ttf"))
        std::cout << "FAILED TO LOAD FONT";

    this->text.setFont(this->font);
    this->text.setString("You LOST");
    this->text.setCharacterSize(48);
    this->text.setPosition(window.getSize().x/2 - 120, window.getSize().y / 2);
    this->text.setFillColor(sf::Color::Red);
    this->text.setStyle(sf::Text::Bold);
    window.draw(this->text);

	window.display();
}
