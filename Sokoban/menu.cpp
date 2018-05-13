#include "screens.h"
#include <fstream>

Menu::Menu(int width, int height, std::string firstButton, std::string secondButton, std::string thirdButton) {
	font.loadFromFile("arial.ttf");													// Load font and textures
	buttonTexture.loadFromFile("Textures/button.png");
	buttonSelectedTexture.loadFromFile("Textures/buttonSelected.png");
	sokobanLogoTexture.loadFromFile("Textures/sokobanLogo.png");
	backgroundTexture.loadFromFile("Textures/background.png");

	background.setTexture(backgroundTexture);										// Set background, and logo
	logo.setTexture(sokobanLogoTexture);
	logo.setPosition(Vector2f(width / 2 - logo.getGlobalBounds().width / 2, 0));

	// Play button
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString(firstButton);
	menu[0].setPosition(Vector2f(width / 2 - menu[0].getGlobalBounds().width / 2,
		height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 1));			// Positioning text in right place
	buttons[0].setTexture(buttonSelectedTexture);									// First button is selected
	float buttonX = width / 2 - buttons[0].getGlobalBounds().width / 2;				// Centering buttons
	buttons[0].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 1));

	// Level creator button
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString(secondButton);
	menu[1].setPosition(Vector2f(width / 2 - menu[1].getGlobalBounds().width / 2,
		height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 2));
	buttons[1].setTexture(buttonTexture);
	buttons[1].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 2));

	// Exit button
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString(thirdButton);
	menu[2].setPosition(Vector2f(width / 2 - menu[2].getGlobalBounds().width / 2,
		height / 4 + 30 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 3));
	buttons[2].setTexture(buttonTexture);
	buttons[2].setPosition(Vector2f(buttonX, height / 4 + height / (1.5 * (MAX_NUMBER_OF_ITEMS + 1)) * 3));

	selectedItemIndex = 0;													// First button is selected
}

Menu::~Menu() {
}

void Menu::draw(RenderWindow &window) {										// Drawing everything on window
	window.draw(background);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(buttons[i]);
		window.draw(menu[i]);
	}
	window.draw(logo);
}

void Menu::moveUp() {														// Moving up in menu	
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(Color::White);
		buttons[selectedItemIndex].setTexture(buttonTexture);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
		buttons[selectedItemIndex].setTexture(buttonSelectedTexture);
	}
}

void Menu::moveDown() {														// Moving up in menu
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(Color::White);
		buttons[selectedItemIndex].setTexture(buttonTexture);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
		buttons[selectedItemIndex].setTexture(buttonSelectedTexture);
	}
}

int Menu::run(RenderWindow &window) {										// Running menu
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:													// exit handling
			window.close();
			break;
		case Event::KeyReleased:
			switch (event.key.code) {
			case(Keyboard::Up):												// Moving through menu
				moveUp();
				break;
			case(Keyboard::Down):
				moveDown();
				break;
			case(Keyboard::Space):    									    // Pressing buttons
				return selectedItemIndex + 1;
				break;
			case(Keyboard::Return):
				return selectedItemIndex + 1;
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
	draw(window);															// drawing everything
	return 0;
}