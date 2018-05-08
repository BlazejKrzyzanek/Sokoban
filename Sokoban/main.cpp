#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screens.h"
#include "levels.h"
#include <cmath>
#include <iostream>
#include <fstream>

#define MATRIX_X 24
#define MATRIX_Y 16

using namespace sf;
using namespace std;


int main(){
	Level levels[5];
	int levelsMatrix[MATRIX_X][MATRIX_Y];
	int screen = 0;
	int level = 0;
	// Create game window
	int wWidth = 1200;
	int wHeight = 800;
	RenderWindow app(VideoMode(wWidth, wHeight, 32), "Sokoban v. 0.0 by B. Krzyzanek", Style::Titlebar | Style::Close);
	app.setMouseCursorVisible(false);

	Menu menu(app.getSize().x, app.getSize().y);
	LevelMenu levelMenu(app.getSize().x, app.getSize().y);
	// Read levels from file

	//createLevel("Levels/level1.txt", app, 0);

	std::ifstream lvl("Levels/level1.txt");
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			lvl >> levelsMatrix[i][j];
	Level tmp(app.getSize().x, app.getSize().y);
	tmp.CreateMatrix(levelsMatrix);
	levels[0] = tmp;

	std::ifstream lv2("Levels/level2.txt");
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			lv2 >> levelsMatrix[i][j];
	Level tmp2(app.getSize().x, app.getSize().y); // Tablica tego
	tmp2.CreateMatrix(levelsMatrix);
	levels[1] = tmp2;

	std::ifstream lv3("Levels/level3.txt");
	for (int i = 0; i < MATRIX_X; i++)
		for (int j = 0; j < MATRIX_Y; j++)
			lv3 >> levelsMatrix[i][j];
	Level tmp3(app.getSize().x, app.getSize().y);
	tmp3.CreateMatrix(levelsMatrix);
	levels[2] = tmp3;




	// Main game loop
	while (app.isOpen()){
		app.clear();
		Event event;
		switch (screen) {
			// Menu screen
		case 0: {
			while (app.pollEvent(event)) {
				switch (event.type) {
				case Event::Closed: // exit handling
					app.close();
					break;
				case Event::KeyReleased:
					switch (event.key.code) {
					case(Keyboard::Up):
						menu.MoveUp();
						break;
					case(Keyboard::Down):
						menu.MoveDown();
						break;
						// Buttons
					case(Keyboard::Space): {
						int index = menu.Press();

						if (index == 0) {
							screen = 1;
						}
						if (index == 1) {
							screen = 2;
						}
						if (index == 2) {
							app.close();
						}
						break;
					}
					case(Keyboard::Return): {
						int index = menu.Press();

						if (index == 0) {
							screen = 1;
						}
						if (index == 1) {
							screen = 2;
						}
						if (index == 2) {
							app.close();
						}
						break;
					}
					}
				default:
					break;
				}
			}
			menu.draw(app);
			break;
		}
				// Level choosing screen
		case 1: { // Choose level screen
			while (app.pollEvent(event)) {
				switch (event.type) {
				case Event::Closed: // exit handling
					app.close();
					break;
				case Event::KeyReleased: // Moving through levels
					switch (event.key.code) {
					case(Keyboard::Left):
						levelMenu.MoveLeft();
						break;
					case(Keyboard::Right):
						levelMenu.MoveRight();
						break;
					case(Keyboard::Up):
						levelMenu.MoveUp();
						break;
					case(Keyboard::Down):
						levelMenu.MoveDown();
						break;
					case(Keyboard::Space):
						level = menu.Press();
						screen = 3;
						break;
					case(Keyboard::Return):
						level = menu.Press();
						screen = 3;
						break;
					default:
						break;
					}
				default:
					break;
				}
			}
			levelMenu.draw(app);
			break;
		}
				// Level creator screen, just menu screen for a while -  will change it later
		case 2: {
			while (app.pollEvent(event)) {  // exit handling
				switch (event.type) {
				case Event::Closed:
					app.close();
					break;
				case Event::KeyReleased:
					switch (event.key.code) {
					case(Keyboard::Up):
						menu.MoveUp();
						break;
					case(Keyboard::Down):
						menu.MoveDown();
						break;
						// Buttons
					case(Keyboard::Space): {
						int index = menu.Press();

						if (index == 0) {
							screen = 1;
						}
						if (index == 1) {
							screen = 2;
						}
						if (index == 2) {
							app.close();
						}
						break;
					}
					case(Keyboard::Return): {
						int index = menu.Press();

						if (index == 0) {
							screen = 1;
						}
						if (index == 1) {
							screen = 2;
						}
						if (index == 2) {
							app.close();
						}
						break;
					}
					}
				default:
					break;
				}
			}
			menu.draw(app);
			break;
		}// end of temporary settings screen
		// Levels screen
		case 3: {
			switch (level) {
			case 0: {
				if (levels[0].run(app)) {
					level++;
				}
				break;
			}
			case 1: {
				if (levels[1].run(app)) {
					level++;
				}
				break;
			}
			case 2: {
				if (levels[2].run(app)) {
					level++;
				}
				break;
			}
			case 3: {
				if (levels[3].run(app)) {
					level++;
				}
				break;
			}
			case 4: {
				if (levels[4].run(app)) {
					level++;
				}
				break;
			}
			case 5: {
				if (levels[5].run(app)) {
					level++;
				}
				break;
			}
			case 6: {
				if (levels[6].run(app)) {
					level++;
				}
				break;
			}
			case 7: {
				if (levels[7].run(app)) {
					level++;
				}
				break;
			}
			case 8: {
				if (levels[8].run(app)) {
					level++;
				}
				break;
			}
			case 9: {
				if (levels[9].run(app)) {
					level++;
				}
				break;
			}
			case 10: {
				if (levels[10].run(app)) {
					level++;
				}
				break;
			}
			case 11: {
				if (levels[11].run(app));
				break;
			}

			}
		}
		}
		app.display();
	}
	return EXIT_SUCCESS;
}