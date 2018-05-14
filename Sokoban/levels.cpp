#include "levels.h"

Level::Level(int width, int height) {
	// load textures
	pathTexture.loadFromFile("Textures/path.png");
	cargoTexture.loadFromFile("Textures/cargo.png");
	deliveredTexture.loadFromFile("Textures/delivered.png");
	placeTexture.loadFromFile("Textures/place.png");
	brickTexture.loadFromFile("Textures/brick.png");
	playerTexture.loadFromFile("Textures/player.png");
	backgroundTexture.loadFromFile("Textures/background.png");
	congratsTexture.loadFromFile("Textures/congrats.png");
	keysTexture.loadFromFile("Textures/keys.png");
	emptyTexture.loadFromFile("Textures/empty.png");
}

Level::~Level() {

}

void Level::moveLeft() {
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

void Level::moveRight() {
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

void Level::moveUp() {
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

void Level::moveDown() {
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

void Level::read(int matrix[MATRIX_X][MATRIX_Y]) {						
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++) {
			saveMatrix[i][j] = matrix[i][j];
		}
}

void Level::createMatrix(int matrix[MATRIX_X][MATRIX_Y]) {				// Creating matrix of sprites
	background.setTexture(backgroundTexture);
	congrats.setTexture(congratsTexture);
	keys.setTexture(keysTexture);

	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++) {
			levelMatrix[i][j] = matrix[i][j];							// Matrix for game (it is changing when playing)
			saveMatrix[i][j] = matrix[i][j];							// Matrix for save (to draw after restarting level)
			Vector2f pos = Vector2f(i * 50, j * 50);					// Position of sprite
			switch (levelMatrix[i][j]) {
			case 0:
				gameMatrix[i][j].setTexture(emptyTexture);				// Showing background under level
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 1:
				gameMatrix[i][j].setTexture(pathTexture);				
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 2:
				gameMatrix[i][j].setTexture(cargoTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 3:
				gameMatrix[i][j].setTexture(placeTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 4:
				gameMatrix[i][j].setTexture(deliveredTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				break;
			case 5:
				levelMatrix[i][j] = 1;									// Draw path under player
				gameMatrix[i][j].setTexture(pathTexture);
				gameMatrix[i][j].setScale(0.5, 0.5);
				gameMatrix[i][j].setPosition(pos);
				player.setTexture(playerTexture);						
				player.setScale(0.5, 0.5);
				player.setPosition(pos);								// Set player position and save it
				position[0] = i;
				position[1] = j;
			default:
				break;
			}
		}
}

int Level::run(RenderWindow &window) {
	Event event;	
	congrats.setPosition(Vector2f(window.getSize().x / 2 - congrats.getGlobalBounds().width / 2,		// Setting position of congrats to coenter
		window.getSize().y / 2 - congrats.getGlobalBounds().height / 2));
	keys.setPosition(Vector2f(0, window.getSize().y - keys.getGlobalBounds().height));
	int state = gameState(window);								// Actual state of game (0 - running, 1- winning)
	window.draw(background);									// Drawing sprites
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			window.draw(gameMatrix[i][j]);
	window.draw(player);
	window.draw(keys);

	if (state == 0) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:									// exit handling
				window.close();
				break;
			case Event::KeyReleased:   							// Moving
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
				case(Keyboard::R):								// Restart
					createMatrix(saveMatrix);
					break;
				case(Keyboard::Escape):							// Pause menu
					return 2;
					break;
				default:
					break;
				}
			}
		}
	}
	if (state == 1) {											// Winning
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:									// exit handling
				window.close();
				break;
			case Event::KeyReleased:							// Moving
				switch (event.key.code) {
				case(Keyboard::Space):
					return 1;
					break;
				case(Keyboard::Escape):
					return 2;
					break;
				case(Keyboard::R):								// Restart
					createMatrix(saveMatrix);
					break;
				default:
					break;
				}
			}
		 }
		window.draw(congrats);
		return 0;
	}	
}

int Level::gameState(RenderWindow &window) {					// Looking for "place"
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			if (levelMatrix[i][j] == 3)
				return 0;
	return 1;
}