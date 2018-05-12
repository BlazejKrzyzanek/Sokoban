#include "screens.h"
#include <sstream>

LevelMenu::LevelMenu(int width, int height) {
	if (!font.loadFromFile("arial.ttf")) {
		// handle error
	}
	if (!backgroundTexture.loadFromFile("Textures/background.png")) {
		// handle error
	}
	if (!squareTexture.loadFromFile("Textures/level.png")) {
		// handle error
	}
	if (!squareSelectedTexture.loadFromFile("Textures/levelSelected.png")) {
		// handle error
	}

	background.setTexture(backgroundTexture);

	levels[0].setTexture(squareSelectedTexture);
	levelNumbers[0].setFont(font);
	levelNumbers[0].setFillColor(Color::Red);
	levelNumbers[0].setString("1");

	for (int i = 1; i < NUMBER_OF_LEVELS; i++) {
		levels[i].setTexture(squareTexture);
		// Create numbers of levels
		std::stringstream number;
		if (i == NUMBER_OF_LEVELS -1)
			number << "custom";
		else
			number << i + 1;
		std::string s = number.str();
		levelNumbers[i].setFont(font);
		levelNumbers[i].setFillColor(Color::Black);
		levelNumbers[i].setString(s);
	}
	for (int i = 0; i < NUMBER_OF_LEVELS; i++) {  
		float x, y;
		if (i < NUMBER_OF_LEVELS / 3)
			y = height / 4;
		else if (i < 2 * NUMBER_OF_LEVELS / 3)
			y = 2 * height / 4;
		else
			y = 3 * height / 4;

		if (i < NUMBER_OF_LEVELS / 3)
			x = (width / 5) * (i + 1);
		else if (i < 2 * NUMBER_OF_LEVELS / 3)
			x = (width / 5) * (i + 1 - NUMBER_OF_LEVELS / 3);
		else
			x = (width / 5) * (i + 1 - 2 * NUMBER_OF_LEVELS / 3);
		levels[i].setPosition(Vector2f(x - levels[i].getGlobalBounds().width / 2, y - levels[i].getGlobalBounds().height / 2));
		levelNumbers[i].setPosition(Vector2f(x - levelNumbers[i].getGlobalBounds().width / 2, y - levelNumbers[i].getGlobalBounds().height / 2));
	}

	selectedLevel = 0;

}

LevelMenu::~LevelMenu() {

}

void LevelMenu::moveLeft() {
	if (selectedLevel - 1 >= 0) {
		levelNumbers[selectedLevel].setFillColor(Color::Black);
		levels[selectedLevel].setTexture(squareTexture);
		selectedLevel--;
		levelNumbers[selectedLevel].setFillColor(Color::Red);
		levels[selectedLevel].setTexture(squareSelectedTexture);
	}
}

void LevelMenu::moveRight() {
	if (selectedLevel + 1 < NUMBER_OF_LEVELS) {
		levelNumbers[selectedLevel].setFillColor(Color::Black);
		levels[selectedLevel].setTexture(squareTexture);
		selectedLevel++;
		levelNumbers[selectedLevel].setFillColor(Color::Red);
		levels[selectedLevel].setTexture(squareSelectedTexture);
	}
}

void LevelMenu::moveUp() {
	if (selectedLevel - 4 >= 0) {
		levelNumbers[selectedLevel].setFillColor(Color::Black);
		levels[selectedLevel].setTexture(squareTexture);
		selectedLevel -= 4;
		levelNumbers[selectedLevel].setFillColor(Color::Red);
		levels[selectedLevel].setTexture(squareSelectedTexture);
	}
}

void LevelMenu::moveDown() {
	if (selectedLevel + 4 < NUMBER_OF_LEVELS) {
		levelNumbers[selectedLevel].setFillColor(Color::Black);
		levels[selectedLevel].setTexture(squareTexture);
		selectedLevel += 4;
		levelNumbers[selectedLevel].setFillColor(Color::Red);
		levels[selectedLevel].setTexture(squareSelectedTexture);
	}
}

int LevelMenu::press() {
	return selectedLevel;
}

void LevelMenu::draw(RenderWindow &window) {
	window.draw(background);
	for (auto x : levels) window.draw(x);
	for (auto x : levelNumbers) window.draw(x);

}

int LevelMenu::run(RenderWindow &window) {
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed: // exit handling
			window.close();
			break;
		case Event::KeyReleased: // Moving through levels
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
			case(Keyboard::Space):
				return press();
				break;
			case(Keyboard::Return):
				return press();
				break;
			case(Keyboard::Escape):
				return -2; // comes back to normal menu
				break; 
			default:
				break;
			}
		default:
			break;
		}
	}
	draw(window);
	return -1;
}