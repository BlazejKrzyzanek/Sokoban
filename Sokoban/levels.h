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
	
	Level(int width=1200, int height=800);
	~Level();
	int run(RenderWindow &window);
	// Motion
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void CreateMatrix(int matrix[MATRIX_X][MATRIX_Y]);

	int GameState();

private:
	int position[2];
	int levelMatrix[MATRIX_X][MATRIX_Y];
	Texture pathTexture;
	Texture cargoTexture;
	Texture deliveredTexture;
	Texture playerTexture;
	Texture placeTexture;
	Texture backgroundTexture;
	Sprite gameMatrix[MATRIX_X][MATRIX_Y];
	Sprite player;
	Sprite background;
};