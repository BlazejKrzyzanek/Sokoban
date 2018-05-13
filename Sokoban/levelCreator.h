#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "levels.h"

#define MATRIX_X 24
#define MATRIX_Y 16
#define bSize 50

using namespace sf;

class LevelCreator
{
public:
	LevelCreator(int width, int height);
	int run(RenderWindow &window, Level &customLevel);
	void createMatrix(std::string filename);
	~LevelCreator();

private:
	Texture pathTexture;
	Texture cargoTexture;
	Texture deliveredTexture;
	Texture playerTexture;
	Texture placeTexture;
	Texture brickTexture;
	Texture backgroundTexture;
	Texture keysTexture;
	Texture selectedTexture;
	Texture emptyTexture;
	int saveMatrix[MATRIX_X][MATRIX_Y];
	int nullMatrix[MATRIX_X][MATRIX_Y];
	int levelMatrix[MATRIX_X][MATRIX_Y];
	int position[2];

	Sprite gameMatrix[MATRIX_X][MATRIX_Y];
	Sprite background;
	Sprite selected;
	Sprite keys;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void write(int n);
	void save(Level &customLevel);
	
};