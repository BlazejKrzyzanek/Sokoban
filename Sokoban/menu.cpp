#include "screens.h"

Menu::Menu(int width, int height) {
	// Load font
	if (!font.loadFromFile("arial.ttf")) {
		// handle error
	}

	// Load button, logo and background textures
	if (!buttonTexture.loadFromFile("Textures/button.png")) {
		// handle error
	}
	if (!buttonSelectedTexture.loadFromFile("Textures/buttonSelected.png")) {
		// handle error
	}
	if (!buttonPressedTexture.loadFromFile("Textures/buttonPressed.png")) {
		// handle error
	}
	if (!sokobanLogoTexture.loadFromFile("Textures/sokobanLogo.png")) {
		// handle error
	}
	if (!backgroundTexture.loadFromFile("Textures/background.png")) {
		// handle error
	} 

	background.setTexture(backgroundTexture);

	logo.setTexture(sokobanLogoTexture);
	logo.setPosition(Vector2f(width / 2 - logo.getGlobalBounds().width / 2, 0));

	// Play button
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2 - menu[0].getGlobalBounds().width / 2, height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 1));
	buttons[0].setTexture(buttonSelectedTexture);
	float buttonX = width / 2 - buttons[0].getGlobalBounds().width / 2;
	buttons[0].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 1));

	// Level creator button
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Level creator");
	menu[1].setPosition(Vector2f(width / 2 - menu[1].getGlobalBounds().width / 2, height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 2));
	buttons[1].setTexture(buttonTexture);
	buttons[1].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 2));

	// Exit button
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f(width / 2 - menu[0].getGlobalBounds().width / 2, height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 3));
	buttons[2].setTexture(buttonTexture);
	buttons[2].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 3));


	selectedItemIndex = 0;
}

Menu::~Menu() {
}

void Menu::draw(RenderWindow &window) {
	window.draw(background);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(buttons[i]);
		window.draw(menu[i]);
	}
	window.draw(logo);
}

void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(Color::White);
		buttons[selectedItemIndex].setTexture(buttonTexture);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
		buttons[selectedItemIndex].setTexture(buttonSelectedTexture);
	}
}

void Menu::moveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(Color::White);
		buttons[selectedItemIndex].setTexture(buttonTexture);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
		buttons[selectedItemIndex].setTexture(buttonSelectedTexture);
	}
}

int Menu::press() {
	buttons[selectedItemIndex].setTexture(buttonPressedTexture);
	return selectedItemIndex;
}

void Menu::noPress() {
	buttons[selectedItemIndex].setTexture(buttonSelectedTexture);
}

int Menu::run(RenderWindow &window) {
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed: // exit handling
			window.close();
			break;
		case Event::KeyReleased:
			switch (event.key.code) {
			case(Keyboard::Up):
				moveUp();
				break;
			case(Keyboard::Down):
				moveDown();
				break;
				// Buttons
			case(Keyboard::Space): {
				int index = press();
				noPress();

				if (index == 0) { // play game
					noPress();
					return 1;
				}
				if (index == 1) { // level creator
					noPress();
					return 2;
				}
				if (index == 2) { // exit
					noPress();
					window.close();
				}
				break;
			}
			case(Keyboard::Return): {
				int index = press();
				noPress();

				if (index == 0) { // play game
					noPress();
					return 1;
				}
				if (index == 1) { // level creator
					noPress();
					return 2;
				}
				if (index == 2) { // exit
					noPress();
					window.close();
				}
				break;
			}
			}
		default:
			break;
		}
	}
	draw(window);
	return 0;
}