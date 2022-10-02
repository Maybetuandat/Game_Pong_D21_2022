#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class MainMenu
{
public:
	MainMenu(float width, float height);
	~MainMenu();
	void Draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();


	int MainMenuPressed()
	{
		return MainMenuSelected;
	}

private:
	int MainMenuSelected;
	Font font;

	Text mainMenu[5];

};
