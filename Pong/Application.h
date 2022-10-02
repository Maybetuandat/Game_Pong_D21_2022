#pragma once
#include"MainMenu.h"
#include"GameConfig.h"
#include"GamePlay.h"
#include"Option.h"
#include"About.h"
class Application
{
public:
	Application();
	~Application();
	void DrawBg();
	void Run();
	void Update(float deltatime);

private:
	//in the main menu
	sf::RectangleShape m_background;
	sf::Texture m_Maintexture;

	float m_currentime;


	//in the  options
	sf::RectangleShape Obackground;
	sf::Texture Op_texture;

	//in the abouts
	sf::RectangleShape Abackground;
	sf::Texture About_texture;
};