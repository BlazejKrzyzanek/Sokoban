#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screens.h"
#include "levels.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>

#define MATRIX_X 24
#define MATRIX_Y 16

using namespace sf;
using namespace std;


int main(){
	// Initialize screen and level
	int screen = 0;
	int level = 0;
	// Create game window
	int wWidth = 1200;
	int wHeight = 800;
	RenderWindow app(VideoMode(wWidth, wHeight, 32), "Sokoban v. alpha 0.0 by B. Krzyzanek", Style::Titlebar | Style::Close);
	app.setMouseCursorVisible(false);
	app.setFramerateLimit(60); 

	Menu menu(app.getSize().x, app.getSize().y);
	LevelMenu levelMenu(app.getSize().x, app.getSize().y);
	PauseMenu pauseMenu(app.getSize().x, app.getSize().y);

	// Read levels from files
	vector<Level> levels;
	createLevel(levels, "Levels/level1.txt", app);



	// Main game loop
	while (app.isOpen()){
			app.clear();
			Event event;
			switch (screen) {
					// Menu screen
			case 0: {
				int state = menu.run(app);
				if (state == 1)
					screen = 1;
				else if (state == 2)
					screen = 2;
				break;
			}
					// Level choosing screen
			case 1: { // Choose level screen
				level = levelMenu.run(app);
				if (level != -1) screen = 3;
				break;
			}
					// Level creator screen, just menu screen for a while -  will change it later
			case 2: {
								int state = menu.run(app);
				if (state == 1)
					screen = 1;
				else if (state == 2)
					screen = 2;
				break;
			}// end of temporary settings screen
					// Levels screen
			case 3: {
				switch (level) {
				case 0: {
					int state = levels[0].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 1: {
					int state = levels[1].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 2: {
					int state = levels[2].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
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
				break;
			}
					// pause menu
			case 4: {
				int state = pauseMenu.run(app);
				if (state == 1)
					screen = 3;
				else if (state == 2)
					screen = 0;
				break;
			}
			}
			
			app.display();
	}
	return EXIT_SUCCESS;
}