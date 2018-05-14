#include "levels.h"
#include <fstream>
#include <iostream>

void createLevel(std::vector<Level> &levels, std::string filename, RenderWindow &window) {		// Adds level to vector
	int levelsMatrix[MATRIX_X][MATRIX_Y];														// Matrix with level map
	std::ifstream file(filename);																// File with matrix
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			file >> levelsMatrix[i][j];															// Read all data 
	file.close();
		
	levels.push_back(Level(window.getSize().x, window.getSize().y));							// Add level to end of vector
	if (!levels.empty())
		levels.back().read(levelsMatrix);														// Read matrix into level
}