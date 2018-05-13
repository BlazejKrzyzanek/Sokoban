#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define MATRIX_X 24
#define MATRIX_Y 16
#define bSize 50 // size of one block of game

using namespace sf;

class Level
{
public:
	
	Level(int width, int height);
	~Level();
	int run(RenderWindow &window); // runing level
	int saveMatrix[MATRIX_X][MATRIX_Y]; // level matrix save for reset
	void createMatrix(int matrix[MATRIX_X][MATRIX_Y]); // create sprites
	void read(int matrix[MATRIX_X][MATRIX_Y]); // read level
private:
	int gameState(RenderWindow &window);
	// Motion
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	int position[2];
	int levelMatrix[MATRIX_X][MATRIX_Y];

	Texture pathTexture;
	Texture cargoTexture;
	Texture deliveredTexture;
	Texture playerTexture;
	Texture placeTexture;
	Texture brickTexture;
	Texture backgroundTexture;
	Texture congratsTexture;
	Texture keysTexture;
	Texture emptyTexture;
	Sprite gameMatrix[MATRIX_X][MATRIX_Y];
	Sprite player;
	Sprite background;
	Sprite congrats;
	Sprite keys;
};

void createLevel(std::vector<Level> &levels, std::string filename, RenderWindow &window);