#include "GamePlay.h"
void GamePlay::Run()
{
	srand(time(NULL));
	
	Pbackground.setSize(sf::Vector2f(1000, 700));
	//Create the window of the application
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game Pong", sf::Style::Titlebar | sf::Style::Close);

	//Creat the left paddle
	
	leftPaddle.setSize(paddleSize);
	leftPaddle.setFillColor(sf::Color::Black);
	leftPaddle.setOutlineThickness(3);
	leftPaddle.setOutlineColor(sf::Color(0, 0, 0));
	leftPaddle.setPosition(0, screenHeight / 2);
	leftPaddle.setOrigin(paddleSize / 2.f);
	
	texture.loadFromFile("../Data/background.png");
	Pbackground.setTexture(&texture);

	//Create the right paddle

	rightPaddle.setSize(paddleSize);
	rightPaddle.setFillColor(sf::Color::White);
	rightPaddle.setOutlineThickness(3);
	rightPaddle.setOutlineColor(sf::Color(0, 0, 0));
	rightPaddle.setPosition(screenWidth, screenHeight / 2);
	rightPaddle.setOrigin(paddleSize / 2.f);
	//Create the ball
	
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::Green);
	ball.setOutlineThickness(3);
	ball.setOutlineColor(sf::Color::Black);
	ball.setPosition(screenWidth / 2, screenHeight / 2);

	
	


	

	//Load font
	
	font.loadFromFile("../Data/ARCADE.TTF");

	//Init pause Messenger
	
	pauseMessenger.setFont(font);
	pauseMessenger.setPosition(screenWidth / 2 - 200, screenHeight / 2);
	pauseMessenger.setFillColor(sf::Color::Green);
	pauseMessenger.setCharacterSize(50);
	pauseMessenger.setString("Press enter to play");
	//Timer
	sf::Clock clock;
	float deltaTime = 0.f;
	//Game State
	bool isPlaying = false;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		window.draw(Pbackground);
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (isPlaying == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			ball.setPosition(screenWidth / 2, screenHeight / 2);
			rightPaddle.setPosition(screenWidth, screenHeight / 2);
			leftPaddle.setPosition(0, screenHeight / 2);
			do {
				angleBall = rand() % 360;
			} while (angleBall < 45 || (angleBall > 135 && angleBall < 225) || angleBall>315);
			isPlaying = true;
		}
		if (isPlaying) {

			//the leftPaddle Moving
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sf::Vector2f pos = leftPaddle.getPosition();
				if (pos.y + paddleSize.y / 2 + paddleSpeed * deltaTime > screenHeight) leftPaddle.setPosition(pos.x, screenHeight - paddleSize.y / 2);
				else leftPaddle.move(0, paddleSpeed * deltaTime);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sf::Vector2f pos = leftPaddle.getPosition();
				if (pos.y - paddleSize.y / 2 - paddleSpeed * deltaTime < 0) leftPaddle.setPosition(pos.x, paddleSize.y / 2);
				else leftPaddle.move(0, -paddleSpeed * deltaTime);
			}
			//Update target of bot
			botTimer += deltaTime;
			if (botTimer >= botPeriod) {
				if (sin(angleBall * pi / 180) > 0.f) {
					botTarget = ball.getPosition().y;
					botTimer -= botPeriod;
				}
			}
			if (rightPaddle.getPosition().y + paddleSize.y / 4 < botTarget)//sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sf::Vector2f pos = rightPaddle.getPosition();
				if (pos.y + paddleSize.y / 2 + paddleSpeed * deltaTime > screenHeight) rightPaddle.setPosition(pos.x, screenHeight - paddleSize.y / 2);
				else rightPaddle.move(0, paddleSpeed * deltaTime);
			}
			else if (rightPaddle.getPosition().y - paddleSize.y / 4 > botTarget)//sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sf::Vector2f pos = rightPaddle.getPosition();
				if (pos.y - paddleSize.y / 2 - paddleSpeed * deltaTime < 0) rightPaddle.setPosition(pos.x, paddleSize.y / 2);
				else rightPaddle.move(0, -paddleSpeed * deltaTime);
			}


			//the ball moving
			float factor = ballSpeed * deltaTime;
			//ball.move(cos(angleBall * pi / 180) * factor, sin(angleBall * pi / 180)*factor);
			ball.move(sin(angleBall * pi / 180) * factor, -cos(angleBall * pi / 180) * factor);

			//Check Collision Top_Down Wall
			if (ball.getPosition().y <= 0 || ball.getPosition().y >= screenHeight) {
				angleBall = 180.f - angleBall;
			}
			//Check Collison with the paddle
			//Left Paddle
			if (ball.getPosition().x - ballRadius <= leftPaddle.getPosition().x + paddleSize.x / 2
				&& ball.getPosition().y >= leftPaddle.getPosition().y - paddleSize.y / 2
				&& ball.getPosition().y <= leftPaddle.getPosition().y + paddleSize.y / 2
				&& ball.getPosition().x > leftPaddle.getPosition().x)
			{
				if (ball.getPosition().y > leftPaddle.getPosition().y) {
					angleBall = 360.f - angleBall + rand() % 10;
				}
				else {
					angleBall = 360.f - angleBall - rand() % 10;
				}

			}
			//Right Paddle
			if (ball.getPosition().x + ballRadius >= rightPaddle.getPosition().x - paddleSize.x / 2
				&& ball.getPosition().y >= rightPaddle.getPosition().y - paddleSize.y / 2
				&& ball.getPosition().y <= rightPaddle.getPosition().y + paddleSize.y / 2
				&& ball.getPosition().x < rightPaddle.getPosition().x)
			{
				if (ball.getPosition().y > rightPaddle.getPosition().y) {
					angleBall = 360.f - angleBall - rand() % 10;
				}
				else {
					angleBall = 360.f - angleBall + rand() % 10;
				}
			}
			if (ball.getPosition().x <= 0) {
				pauseMessenger.setString("Red is Winner\n Press enter to play");
				isPlaying = false;
			}
			else if (ball.getPosition().x >= screenWidth) {
				pauseMessenger.setString("Blue is Winner\n Press enter to play");
				isPlaying = false;
			}
		}
		if (isPlaying) {
			window.draw(leftPaddle);
			window.draw(rightPaddle);
			window.draw(ball);
		}
		else {
			window.draw(pauseMessenger);
		}
		window.display();
	}

}
