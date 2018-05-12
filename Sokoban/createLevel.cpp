#include "levels.h"
#include <fstream>
#include <iostream>

void createLevel(std::vector<Level> &levels, std::string filename, RenderWindow &window) { // dodaje level do wektora
	int levelsMatrix[MATRIX_X][MATRIX_Y]; // macierz zawieraj¹ca mapê na danym poziomie
	std::ifstream file(filename);   // plik zawieraj¹cy t¹ macierz
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			file >> levelsMatrix[i][j]; // wczytanie wszystkich elementów
	file.close();
		
	levels.push_back(Level(window.getSize().x, window.getSize().y));
	if (!levels.empty())
		levels.back().read(levelsMatrix);
}