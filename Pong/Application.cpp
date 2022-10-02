#include "Application.h"
Application::Application()
{
}

Application::~Application()
{
}


void Application::DrawBg()
{
	//set background 
	m_background.setSize(Vector2f(screenWidth, screenHeight));
	m_Maintexture.loadFromFile("../Data/background.png");
	m_background.setTexture(&m_Maintexture);



	//photo in options
	Obackground.setSize(Vector2f(screenWidth, screenHeight));
	Op_texture.loadFromFile("../Data/background.png");
	Obackground.setTexture(&Op_texture);


	//pho to in the Abouts
	Abackground.setSize(Vector2f(screenWidth, screenHeight));
	About_texture.loadFromFile("../Data/background.png");
	Abackground.setTexture(&About_texture);
};
void Application::Update(float deltatime)
{
	m_currentime += deltatime;
}

void Application::Run()
{
	sf::  RenderWindow   MENU(VideoMode(screenWidth, screenHeight), "Game Pong ", sf::Style::Default);
	MainMenu mainMenu(screenWidth, screenHeight);
	DrawBg();
	sf::Clock clock;

	float deltatime = 0.f;

	while (MENU.isOpen())
	{
		sf::Event event;
		deltatime = clock.restart().asSeconds();
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MENU.close();

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
				}
				if (event.key.code == Keyboard::Return)
				{
					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						GamePlay game;
						game.Run();
					}
					if (x == 1)
					{
						Option option;

					}
				
				    if (x == 2)
				     {
				    	About about;
					    about.run();

				     }
				    if (x == 3)
					  MENU.close();
				     break;
				}
			}
			MENU.draw(m_background);
			mainMenu.Draw(MENU);
			MENU.display();
		}

	}
    
	
}

