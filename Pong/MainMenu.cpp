#include"MainMenu.h"
MainMenu::MainMenu(float width, float height)
{
	font.loadFromFile("../Data/ARCADE.TTF");
	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("PLAY");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	//Option
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("OPTIONS");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	//About
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("ABOUT");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("EXIT");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);


	MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{
}
void MainMenu::Draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(mainMenu[i]);
	}

}
void MainMenu::MoveUp()
{
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	MainMenuSelected = MainMenuSelected - 1;
	if (MainMenuSelected == -1)
	{
		MainMenuSelected = 3;
	}
	mainMenu[MainMenuSelected].setFillColor(Color::Blue);

}

void MainMenu::MoveDown()
{
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	MainMenuSelected++;
	if (MainMenuSelected == 4)
	{
		MainMenuSelected = 0;
	}
	mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}
