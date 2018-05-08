#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define MAX_NUMBER_OF_ITEMS 3
#define NUMBER_OF_LEVELS 12

using namespace sf;


class Menu {
	// First window - menu with play, create level and exit buttons. 
public:
	Menu(int width, int height);
	~Menu();

	void draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int Press();
	int selectedItemIndex;

private:
	Font font;
	Texture buttonTexture;
	Texture buttonSelectedTexture;
	Texture buttonPressedTexture;
	Texture sokobanLogoTexture;
	Texture backgroundTexture;
	Text menu[MAX_NUMBER_OF_ITEMS];
	Sprite buttons[MAX_NUMBER_OF_ITEMS];
	Sprite logo;
	Sprite background;
};

class LevelMenu {
	// Window with levels to choose, it displays after clicking "Play" button in main menu.
public:
	LevelMenu(int width, int height);
	~LevelMenu();

	void draw(RenderWindow &window);

	// Motion in menu
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	int Press();

	int selectedLevel;

private:
	Font font;
	Texture squareTexture;
	Texture squareSelectedTexture;
	Texture backgroundTexture;
	Text levelNumbers[NUMBER_OF_LEVELS];
	Sprite levels[NUMBER_OF_LEVELS];
	Sprite background;
};