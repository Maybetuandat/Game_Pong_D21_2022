#include "About.h"

About::About()
{
}

About::~About()
{
}

void About::run()
{
    sf::RenderWindow  window(sf::VideoMode(screenWidth, screenHeight), "About game", sf::Style::Default);
	sf::RectangleShape shape(sf::Vector2f(1000.f, 700.f));




	// about game load font 
	m_Font.loadFromFile("../Data/ARCADE.TTF");
	m_About.setFont(m_Font);
	m_About.setFillColor(sf::Color::Blue);
	m_About.setString("Use the W key and the S key to use ");
	m_About.setCharacterSize(40);
	m_About.setPosition(100, 100);




	//about 2
	m_about.setFont(m_Font);
	m_about.setFillColor(sf::Color::Blue);
	m_about.setString(" the stand to catch the ball");
	m_about.setCharacterSize(40);
	m_about.setPosition(150, 200);



	// about 3
	m_about1.setFont(m_Font);
	m_about1.setFillColor(sf::Color::Green);
	m_about1.setString("GoodLuck");
	m_about1.setCharacterSize(40);
	m_about1.setPosition(350, 350);




	//background 
	sf::Texture texture;
	texture.loadFromFile("../Data/background.png");
	shape.setTexture(&texture);
	



	// draw
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			window.draw(shape);
			window.draw(m_About);
			window.draw(m_about);
			window.draw(m_about1);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.display();

		}
	}
	

	
}
