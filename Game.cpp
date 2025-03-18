#include "Game.h"
#include "Vector2.h"
#include <iostream>
#include <String>

Game::Game()
{
    Vector2 windowSize = { (float)window.getSize().x, (float)window.getSize().y };
    window.create(sf::VideoMode(840, 650), "SpeedMathRacer");
    window.setFramerateLimit(60);

    Start();
}

void Game::Start()
{
    if (!font.loadFromFile("Assets/arial.ttf"))
        std::cout << "FAILED TO LOAD FONT";

    if (!background.loadFromFile("Assets/Road.png"))
        std::cout << "FAILED TO LOAD IMAGE";

    if (!car.loadFromFile("Assets/YellowBuggy.png"))
        std::cout << "FAILED TO LOAD IMAGE";
    if (!playerCar.loadFromFile("Assets/RedCar.png"))
        std::cout << "FAILED TO LOAD IMAGE";

    spawner.Spawn(5, Obstacle(scoreSystem, car, { 40,60 }, 2.6, { 5,10 }));

    Update();
}

void Game::Update()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        DrawBackground(window, background);
        DrawText(window, font, 32 , sf::Color::White);
       
        if (gameOver == true) {
            gameOverScreen.Display(window);
            continue;
        }

        player.Update();
        CheckCollisions();

        spawner.UpdateObstacles(window);


	    player.Display(window, playerCar);
        window.display();
    }   
}

void Game::CheckCollisions()
{
    //Checks collision with Cars
    if (spawner.CheckCollisions(player.collider))
        gameOver = true;

    //Collision to keep player inside the screen
    if (player.collider.CheckBoxCollision(wallLeft.collider))
        player.AddForce(-player.currentForce + Vector2::right);

    if (player.collider.CheckBoxCollision(wallRight.collider))
        player.AddForce(-player.currentForce + Vector2::left);

    if (player.GetPosition().y < 530)
        player.AddForce(-player.currentForce + Vector2::down);
    if (player.GetPosition().y > 590)
        player.AddForce(-player.currentForce + Vector2::up);
}

void Game::DrawBackground(sf::RenderWindow& window ,sf::Texture background)
{
    sf::Sprite sprite(background);
    backgroundPosition += backgroundSpeed;
    sprite.setPosition(0, backgroundPosition);

    if (backgroundPosition > 0) {
        backgroundPosition = -650;
    }

    window.draw(sprite);
}

void Game::DrawText(sf::RenderWindow& window, sf::Font font, int size, sf::Color color) {
    text.setFont(font);

    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
   
    text.setString("Score: " + std::to_string(scoreSystem.currentScore));
    window.draw(text);
}