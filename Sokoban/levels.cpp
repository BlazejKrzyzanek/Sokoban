#include "levels.h"

Level::Level(int width, int height) {
	// load textures
	if (!pathTexture.loadFromFile("Textures/path.png")) {
		// handle error
	}
	if (!cargoTexture.loadFromFile("Textures/cargo.png")) {
		// handle error
	}
	if (!deliveredTexture.loadFromFile("Textures/delivered.png")) {
		// handle error
	}
	if (!placeTexture.loadFromFile("Textures/place.png")) {
		// handle error
	}
	if (!playerTexture.loadFromFile("Textures/player.png")) {
		// handle error
	}
	if (!backgroundTexture.loadFromFile("Textures/background.png")) {
		// handle error
	}

	background.setTexture(backgroundTexture);
}


Level::~Level() {

}


void Level::MoveLeft() {
	// Normal path or place
	int x = position[0];
	int y = position[1];
	if ((levelMatrix[x - 1][y] == 1) || (levelMatrix[x - 1][y] == 3)) {
		player.setPosition(Vector2f(player.getPosition().x - bSize, player.getPosition().y));
		position[0]--;
	}
	// Cargo to path
	else if ((levelMatrix[x-1][y] == 2) && (levelMatrix[x - 2][y] == 1)) {
		levelMatrix[x-1][y] = 1;
		levelMatrix[x-2][y] = 2;
		gameMatrix[x-1][y].setTexture(pathTexture);
		gameMatrix[x-2][y].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x - bSize, player.getPosition().y));
		position[0]--;
	}
	// Cargo to place
	else if ((levelMatrix[x - 1][y] == 2) && (levelMatrix[x - 2][y] == 3)) {
		levelMatrix[x - 1][y] = 1;
		levelMatrix[x - 2][y] = 4;
		gameMatrix[x - 1][y].setTexture(pathTexture);
		gameMatrix[x - 2][y].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x - bSize, player.getPosition().y));
		position[0]--;
	}
	// Delivered to path
	else if ((levelMatrix[x - 1][y] == 4) && (levelMatrix[x - 2][y] == 1)) {
		levelMatrix[x - 1][y] = 3;
		levelMatrix[x - 2][y] = 2;
		gameMatrix[x - 1][y].setTexture(placeTexture);
		gameMatrix[x - 2][y].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x - bSize, player.getPosition().y));
		position[0]--;
	}
	// Delivered to place
	else if ((levelMatrix[x - 1][y] == 4) && (levelMatrix[x - 2][y] == 3)) {
		levelMatrix[x - 1][y] = 3;
		levelMatrix[x - 2][y] = 4;
		gameMatrix[x - 1][y].setTexture(placeTexture);
		gameMatrix[x - 2][y].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x - bSize, player.getPosition().y));
		position[0]--;
	}
	
}


void Level::MoveRight() {
	// Normal path or place
	int x = position[0];
	int y = position[1];
	if ((levelMatrix[x + 1][y] == 1) || (levelMatrix[x + 1][y] == 3)) {
		player.setPosition(Vector2f(player.getPosition().x + bSize, player.getPosition().y));
		position[0]++;
	}
	// Cargo to path
	else if ((levelMatrix[x + 1][y] == 2) && (levelMatrix[x + 2][y] == 1)) {
		levelMatrix[x + 1][y] = 1;
		levelMatrix[x + 2][y] = 2;
		gameMatrix[x + 1][y].setTexture(pathTexture);
		gameMatrix[x + 2][y].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x + bSize, player.getPosition().y));
		position[0]++;
	}
	// Cargo to place
	else if ((levelMatrix[x + 1][y] == 2) && (levelMatrix[x + 2][y] == 3)) {
		levelMatrix[x + 1][y] = 1;
		levelMatrix[x + 2][y] = 4;
		gameMatrix[x + 1][y].setTexture(pathTexture);
		gameMatrix[x + 2][y].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x + bSize, player.getPosition().y));
		position[0]++;
	}
	// Delivered to path
	else if ((levelMatrix[x + 1][y] == 4) && (levelMatrix[x + 2][y] == 1)) {
		levelMatrix[x + 1][y] = 3;
		levelMatrix[x + 2][y] = 2;
		gameMatrix[x + 1][y].setTexture(placeTexture);
		gameMatrix[x + 2][y].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x + bSize, player.getPosition().y));
		position[0]++;
	}
	// Delivered to place
	else if ((levelMatrix[x + 1][y] == 4) && (levelMatrix[x + 2][y] == 3)) {
		levelMatrix[x + 1][y] = 3;
		levelMatrix[x + 2][y] = 4;
		gameMatrix[x + 1][y].setTexture(placeTexture);
		gameMatrix[x + 2][y].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x + bSize, player.getPosition().y));
		position[0]++;
	}
}


void Level::MoveUp() {
	// Normal path or place
	int x = position[0];
	int y = position[1];
	if ((levelMatrix[x][y - 1] == 1) || (levelMatrix[x][y - 1] == 3)) {
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - bSize));
		position[1]--;
	}
	// Cargo to path
	else if ((levelMatrix[x][y - 1] == 2) && (levelMatrix[x][y - 2] == 1)) {
		levelMatrix[x][y-1] = 1;
		levelMatrix[x][y-2] = 2;
		gameMatrix[x][y - 1].setTexture(pathTexture);
		gameMatrix[x][y - 2].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - bSize));
		position[1]--;
	}
	// Cargo to place
	else if ((levelMatrix[x][y - 1] == 2) && (levelMatrix[x][y - 2] == 3)) {
		levelMatrix[x][y - 1] = 1;
		levelMatrix[x][y - 2] = 4;
		gameMatrix[x][y - 1].setTexture(pathTexture);
		gameMatrix[x][y - 2].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - bSize));
		position[1]--;
	}
	// Delivered to path
	else if ((levelMatrix[x][y - 1] == 4) && (levelMatrix[x][y - 2] == 1)) {
		levelMatrix[x][y - 1] = 3;
		levelMatrix[x][y - 2] = 2;
		gameMatrix[x][y - 1].setTexture(placeTexture);
		gameMatrix[x][y - 2].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - bSize));
		position[1]--;
	}
	// Delivered to place
	else if ((levelMatrix[x][y - 1] == 4) && (levelMatrix[x][y -2] == 3)) {
		levelMatrix[x][y - 1] = 3;
		levelMatrix[x][y - 2] = 4;
		gameMatrix[x][y - 1].setTexture(placeTexture);
		gameMatrix[x][y - 2].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - bSize));
		position[1]--;
	}
}


void Level::MoveDown() {
	// Normal path or place
	int x = position[0];
	int y = position[1];
	if ((levelMatrix[x][y + 1] == 1) || (levelMatrix[x][y + 1] == 3)) {
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + bSize));
		position[1]++;
	}
	// Cargo to path
	else if ((levelMatrix[x][y + 1] == 2) && (levelMatrix[x][y + 2] == 1)) {
		levelMatrix[x][y + 1] = 1;
		levelMatrix[x][y + 2] = 2;
		gameMatrix[x][y + 1].setTexture(pathTexture);
		gameMatrix[x][y + 2].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + bSize));
		position[1]++;
	}
	// Cargo to place
	else if ((levelMatrix[x][y + 1] == 2) && (levelMatrix[x][y + 2] == 3)) {
		levelMatrix[x][y + 1] = 1;
		levelMatrix[x][y + 2] = 4;
		gameMatrix[x][y + 1].setTexture(pathTexture);
		gameMatrix[x][y + 2].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + bSize));
		position[1]++;
	}
	// Delivered to path
	else if ((levelMatrix[x][y + 1] == 4) && (levelMatrix[x][y + 2] == 1)) {
		levelMatrix[x][y + 1] = 3;
		levelMatrix[x][y + 2] = 2;
		gameMatrix[x][y + 1].setTexture(placeTexture);
		gameMatrix[x][y + 2].setTexture(cargoTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + bSize));
		position[1]++;
	}
	// Delivered to place
	else if ((levelMatrix[x][y + 1] == 4) && (levelMatrix[x][y + 2] == 3)) {
		levelMatrix[x][y + 1] = 3;
		levelMatrix[x][y + 2] = 4;
		gameMatrix[x][y + 1].setTexture(placeTexture);
		gameMatrix[x][y + 2].setTexture(deliveredTexture);
		player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y + bSize));
		position[1]++;
	}
}


void Level::CreateMatrix(int matrix[MATRIX_X][MATRIX_Y]) {
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++) {
			levelMatrix[i][j] = matrix[i][j];
			Vector2f pos = Vector2f(i * 50, j * 50);
			switch (levelMatrix[i][j]) {
			case 0:
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
				levelMatrix[i][j] = 1;
				gameMatrix[i][j].setTexture(pathTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				player.setTexture(playerTexture);
				player.setScale(0.5, 0.5);
				player.setPosition(pos);
				position[0] = i;
				position[1] = j;
			}
			}
		}
			
}


int Level::run(RenderWindow &window) {
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed: // exit handling
			window.close();
			break;
		case Event::KeyReleased: // Moving
			switch (event.key.code) {
			case(Keyboard::Left):
				MoveLeft();
				break;
			case(Keyboard::Right):
				MoveRight();
				break;
			case(Keyboard::Up):
				MoveUp();
				break;
			case(Keyboard::Down):
				MoveDown();
				break;
			default:
				break;
			}
		}
	}
	window.draw(background);
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			window.draw(gameMatrix[i][j]);
	window.draw(player);
	return GameState();
}


int Level::GameState() {
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			if (levelMatrix[i][j] == 3)
				return 0;
	return 1;
}