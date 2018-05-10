#include "levels.h"
#include <fstream>

void createLevel(std::vector<Level> &levels, std::string filename, RenderWindow &window) {
	int levelsMatrix[MATRIX_X][MATRIX_Y];
	std::ifstream file(filename);
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			file >> levelsMatrix[i][j];
	Level lvl(window.getSize().x, window.getSize().y);
	lvl.CreateMatrix(levelsMatrix);
	levels.push_back(lvl);
}