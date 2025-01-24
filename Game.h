#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "Wall.h"
#include "GameOverScreen.h"
#include "ScoreSystem.h"

class Game
{
public:
	Game();

	void Start();
	void Update();

	void CheckCollisions();
	void DrawText(sf::RenderWindow&, sf::Font, int, sf::Color);
	void DrawBackground(sf::RenderWindow&, sf::Texture);

private:
	sf::RenderWindow window;

	Player player = Player({ 420,550 }, { 50,70 });

	ScoreSystem scoreSystem;
	Obstacle Ground;


	Obstacle Car1 = Obstacle({ 50,80 }, 2.6, {1,10});
	Obstacle Car2 = Obstacle({ 50,80 }, 2.8, {1,10});
	Obstacle Car3 = Obstacle({ 50,80 }, 2.8, {1.1,10});
	Obstacle Car4 = Obstacle({ 50,80 }, 3.1, {1.2,10});
	Obstacle Car5 = Obstacle({ 50,80 }, 2.6, {1.5,10});
	Obstacle Car6 = Obstacle({ 50,80 }, 2.6, {1.5,10});

	Wall wallLeft = Wall({ 80, player.GetPosition().y }, {200,300});
	Wall wallRight = Wall({860, player.GetPosition().y}, {200,300});

	sf::Text text;
	sf::Font font;
	sf::Texture background;
	sf::Texture car;
	sf::Texture playerCar;

	float backgroundPosition = -650;
	float backgroundSpeed = 8;

	GameOverScreen gameOverScreen;
	bool gameOver = false;
};

