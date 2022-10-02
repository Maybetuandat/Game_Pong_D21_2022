#pragma once
#include<SFML/Graphics.hpp>
#include"GameConfig.h"
class About
{
public:
	About();
	~About();
	void run();
private:
	sf::Text m_About;
	sf::Font m_Font;
	sf::Text m_about;
	sf::Text m_about1;
	sf::RenderWindow m_window;
};