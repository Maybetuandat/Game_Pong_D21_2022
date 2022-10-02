#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include"GameConfig.h"
class GamePlay
{
public:
	void Run();

private:
	sf::RectangleShape leftPaddle;
	sf::RectangleShape Pbackground;
	sf::Texture  texture;
	
	sf::RectangleShape rightPaddle;
	
	
	int botTarget = screenHeight / 2;
	float botPeriod = 0.2f;
	float botTimer = 0.f;
	
	sf::CircleShape ball;
	
	
	//Define the paddle properties
	float paddleSpeed = 200.f;
	
	
	
	//Define the ball properties
	const float ballSpeed = 200.f;
	float angleBall = -90.f;


	sf::Font font;

	sf::Text pauseMessenger;
};