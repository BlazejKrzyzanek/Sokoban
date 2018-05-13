#include "levelCreator.h"
#include "levels.h"
#include <fstream>
#include <iostream>


LevelCreator::LevelCreator(int width, int height)
{
	// load textures
	pathTexture.loadFromFile("Textures/path.png");
	cargoTexture.loadFromFile("Textures/cargo.png");
	deliveredTexture.loadFromFile("Textures/delivered.png");
	placeTexture.loadFromFile("Textures/place.png");
	brickTexture.loadFromFile("Textures/brick.png");
	playerTexture.loadFromFile("Textures/player.png");
	backgroundTexture.loadFromFile("Textures/background.png");
	keysTexture.loadFromFile("Textures/creator.png");
	selectedTexture.loadFromFile("Textures/selected.png");
	emptyTexture.loadFromFile("Textures/empty.png");

	selected.setTexture(selectedTexture);
	selected.setScale(0.5, 0.5);
	selected.setPosition(width / 2, height / 2);
	position[0] = MATRIX_X / 2;
	position[1] = MATRIX_Y / 2;
}

LevelCreator::~LevelCreator()
{
}

void LevelCreator::moveLeft() {
	if (position[0] > 0) {
		position[0]--;
		selected.setPosition(position[0] * bSize, position[1] * bSize);
	}
}

void LevelCreator::moveRight() {
	if (position[0] + 1 < MATRIX_X) {
		position[0]++;
		selected.setPosition(position[0] * bSize, position[1] * bSize);
	}
}

void LevelCreator::moveUp() {
	if (position[1] > 0) {
		position[1]--;
		selected.setPosition(position[0] * bSize, position[1] * bSize);
	}
}

void LevelCreator::moveDown() {
	if (position[1] +1 < MATRIX_Y) {
		position[1]++;
		selected.setPosition(position[0] * bSize, position[1] * bSize);
	}
}

void LevelCreator::write(int n) {
	levelMatrix[position[0]][position[1]] = n;
	switch (n) {
	case 0:
		gameMatrix[position[0]][position[1]].setTexture(emptyTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		break;
	case 1:
		gameMatrix[position[0]][position[1]].setTexture(pathTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		break;
	case 2:
		gameMatrix[position[0]][position[1]].setTexture(cargoTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		break;
	case 3:
		gameMatrix[position[0]][position[1]].setTexture(placeTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		break;
	case 4:
		gameMatrix[position[0]][position[1]].setTexture(deliveredTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		break;
	case 5:
		for (int i = 0; i < MATRIX_X; i++)
			for (int j = 0; j < MATRIX_Y; j++) {
				if (levelMatrix[i][j] == 5 && (i != position[0] || j != position[1])) {
					levelMatrix[i][j] = 1;
					gameMatrix[i][j].setTexture(pathTexture);
					gameMatrix[i][j].setScale(0.5, 0.5);
					gameMatrix[i][j].setPosition(i * bSize, j * bSize);
				}
			}
		gameMatrix[position[0]][position[1]].setTexture(playerTexture);
		gameMatrix[position[0]][position[1]].setScale(0.5, 0.5);
		gameMatrix[position[0]][position[1]].setPosition(position[0] * bSize, position[1] * bSize);
		
		break;

	}
}

void LevelCreator::createMatrix(std::string filename) {
	background.setTexture(backgroundTexture);
	keys.setTexture(keysTexture);
	std::fstream file;
	file.open(filename, std::ios::in);// plik zawieraj¹cy t¹ macierz
	if (file.good() == false) {
		// handle error
	}
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++){
			file >> levelMatrix[i][j]; // wczytanie wszystkich elementów
			saveMatrix[i][j] = levelMatrix[i][j];
			Vector2f pos = Vector2f(i * bSize, j * bSize);
			switch (levelMatrix[i][j]) {
			case 0:
				gameMatrix[i][j].setTexture(emptyTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 1: {
				gameMatrix[i][j].setTexture(pathTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			}
			case 2: {
				gameMatrix[i][j].setTexture(cargoTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			}
			case 3: {
				gameMatrix[i][j].setTexture(placeTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			}
			case 4: {
				gameMatrix[i][j].setTexture(deliveredTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			}
			case 5: {
				gameMatrix[i][j].setTexture(playerTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
			}
			default:
				break;
		}
	}
	file.close();
}

void LevelCreator::save(Level &customLevel) {
	std::fstream file;
	file.open("Levels/customLevel.txt", std::ios::out);
	for (int i = 0; i < MATRIX_X; i++) {
		for (int j = 0; j < MATRIX_Y; j++)
			file << levelMatrix[i][j] << " ";
		file << "\n";
	}
	file.close();
	std::fstream nullFile;
	nullFile.open("Levels/nullLevel", std::ios::in);// plik zawieraj¹cy t¹ macierz
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			nullFile >> nullMatrix[i][j];
	customLevel.createMatrix(nullMatrix);
	customLevel.createMatrix(levelMatrix);
}

int LevelCreator::run(RenderWindow &window, Level &customLevel) {
	Event event;
	keys.setPosition(Vector2f(0, window.getSize().y - keys.getGlobalBounds().height));
	window.draw(background);
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			window.draw(gameMatrix[i][j]);
	window.draw(keys);
	window.draw(selected);
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed: // exit handling
			window.close();
			break;
		case Event::KeyReleased: // Moving
			switch (event.key.code) {
			case(Keyboard::Left):
				moveLeft();
				break;
			case(Keyboard::Right):
				moveRight();
				break;
			case(Keyboard::Up):
				moveUp();
				break;
			case(Keyboard::Down):
				moveDown();
				break;
			case(Keyboard::A):
				moveLeft();
				break;
			case(Keyboard::D):
				moveRight();
				break;
			case(Keyboard::W):
				moveUp();
				break;
			case(Keyboard::S):
				moveDown();
				break;
			case(Keyboard::C):
				for (int i = 0; i < MATRIX_X; i++)
					for (int j = 0; j < MATRIX_Y; j++)
						levelMatrix[i][j] = saveMatrix[i][j];
				createMatrix("Levels/nullLevel");
				break;
			case(Keyboard::Escape):
				save(customLevel);
				return 0;
				break;
				// Place
			case(Keyboard::E): 
				write(0);
				break;
			case(Keyboard::Num1):
				write(1);
				break;
			case(Keyboard::Num2):
				write(2);
				break;
			case(Keyboard::Num3):
				write(3);
				break;
			case(Keyboard::Num4):
				write(4);
				break;
			case(Keyboard::Num5):
				write(5);
				break;
			default:
				break;
			}
		}
	}
	return 2;
}