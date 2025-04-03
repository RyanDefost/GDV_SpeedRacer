#include "Game.h"
#include "Vector2.h"
#include <iostream>
#include <String>

Game::Game()
{
    Vector2 windowSize = { (float)this->window.getSize().x, (float)this->window.getSize().y };
    this->window.create(sf::VideoMode(840, 650), "SpeedMathRacer");
    this->window.setFramerateLimit(60);

    Start();
}

void Game::Start()
{
    if (!this->font.loadFromFile("Assets/arial.ttf"))
        std::cout << "FAILED TO LOAD FONT";

    if (!this->background.loadFromFile("Assets/Road.png"))
        std::cout << "FAILED TO LOAD IMAGE";

    if (!this->car.loadFromFile("Assets/YellowBuggy.png"))
        std::cout << "FAILED TO LOAD IMAGE";
    if (!this->playerCar.loadFromFile("Assets/RedCar.png"))
        std::cout << "FAILED TO LOAD IMAGE";

    this->player->SetPosition({ 420,550 });
    this->player->SetSize({ 50,70 });

    this->spawner.Spawn(7);

    Run();
}

void Game::Run()
{
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }
        this->window.clear();

        DrawBackground(this->window, this->background);
        DrawText(this->window, this->font, 32 , sf::Color::White);
       
        if (this->gameOver == true) 
        {
            this->gameOverScreen.Display(this->window);
            continue;
        }

        this->player->Update();
        CheckCollisions();

        this->spawner.UpdateObstacles(this->window);


        this->player->Display(this->window, this->playerCar);
        this->window.display();
    }   
}

void Game::CheckCollisions()
{
    //Checks collision with Cars
    if (this->spawner.CheckCollisions(&this->player->collider))
        this->gameOver = true;

    //Collision to keep player inside the screen
    if (this->player->collider.CheckBoxCollision(this->wallLeft.collider))
        this->player->AddForce(-this->player->currentForce + Vector2::right);

    if (this->player->collider.CheckBoxCollision(this->wallRight.collider))
        this->player->AddForce(-this->player->currentForce + Vector2::left);

    if (this->player->GetPosition().y < 530)
        this->player->AddForce(-this->player->currentForce + Vector2::down);
    if (this->player->GetPosition().y > 590)
        this->player->AddForce(-this->player->currentForce + Vector2::up);
}

void Game::DrawBackground(sf::RenderWindow& window ,sf::Texture background)
{
    sf::Sprite sprite(background);
    this->backgroundPosition += this->backgroundSpeed;
    sprite.setPosition(0, this->backgroundPosition);

    if (this->backgroundPosition > 0) 
    {
        this->backgroundPosition = -650;
    }

    window.draw(sprite);
}

void Game::DrawText(sf::RenderWindow& window, sf::Font font, int size, sf::Color color) {
    this->text.setFont(font);

    this->text.setCharacterSize(size);
    this->text.setFillColor(color);
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
   
    this->text.setString("Score: " + std::to_string(this->scoreSystem->currentScore));
    window.draw(text);
}