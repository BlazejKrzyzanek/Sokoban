#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define MAX_NUMBER_OF_ITEMS 3
#define NUMBER_OF_LEVELS 12

using namespace sf;


class Menu {
	// Menu with three buttons
public:
	Menu(int width, int height, std::string firstButton, std::string secondButton, std::string thirdButton);
	~Menu();
	int run(RenderWindow &window);
private:
	void draw(RenderWindow &window);
	void moveUp();
	void moveDown();
	int selectedItemIndex;
	Font font;
	Texture buttonTexture;
	Texture buttonSelectedTexture;
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
	int run(RenderWindow &window);
private:
	void draw(RenderWindow &window);
	// Motion in menu
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	int selectedLevel;
	Font font;
	Texture squareTexture;
	Texture squareSelectedTexture;
	Texture backgroundTexture;
	Text levelNumbers[NUMBER_OF_LEVELS];
	Sprite levels[NUMBER_OF_LEVELS];
	Sprite background;
};