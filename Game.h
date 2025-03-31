#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "Wall.h"
#include "GameOverScreen.h"
#include "ObstacleSpawner.h"
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

	ScoreSystem* scoreSystem = &ScoreSystem::getInstance();
	ObstacleSpawner spawner;
	//Obstacle Ground;

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

