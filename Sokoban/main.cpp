#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screens.h"
#include "levels.h"
#include "levelCreator.h"
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
	LevelCreator levelCreator(app.getSize().x, app.getSize().y);
	levelCreator.createMatrix("Levels/nullLevel.txt");

	// Read levels from files
	vector<Level> levels;
	createLevel(levels, "Levels/level1.txt", app);
	createLevel(levels, "Levels/level2.txt", app);
	createLevel(levels, "Levels/level3.txt", app);
	createLevel(levels, "Levels/level4.txt", app);
	createLevel(levels, "Levels/level5.txt", app);
	createLevel(levels, "Levels/level6.txt", app);
	createLevel(levels, "Levels/level7.txt", app);
	createLevel(levels, "Levels/level8.txt", app);
	createLevel(levels, "Levels/level9.txt", app);
	createLevel(levels, "Levels/level10.txt", app);
	createLevel(levels, "Levels/level11.txt", app);
	createLevel(levels, "Levels/customLevel.txt", app);
	for (int i =0; i < levels.size(); i++)
		levels[i].createMatrix(levels[i].saveMatrix);

	// Main game loop
	while (app.isOpen()){
			app.clear();
			switch (screen) {	
			case 0: {// Menu screen
				int state = menu.run(app);
				if (state == 1)
					screen = 1;
				else if (state == 2)
					screen = 2;
				break;
			}
			case 1: { // Choose level screen
				level = levelMenu.run(app);
				if (level > -1) screen = 3;
				else if (level == -2) screen = 0;
				break;
			}
					// Level creator screen, just menu screen for a while -  will change it later
			case 2: {
				int state = levelCreator.run(app);
				if (state == 2)
					screen = 0;
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
					int state = levels[3].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 4: {
					int state = levels[4].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 5: {
					int state = levels[5].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 6: {
					int state = levels[6].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 7: {
					int state = levels[7].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 8: {
					int state = levels[8].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 9: {
					int state = levels[9].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 10: {
					int state = levels[10].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 11: {
					int state = levels[11].run(app);
					if (state == 1) {
						level++;
					}
					else if (state == 2) {
						screen = 4;
					}
					break;
				}
				case 12: {
					int state = levels[12].run(app);
					if (state == 1) {
						level = 0;
						screen = 0;
					}
					else if (state == 2) {
						screen = 4;
					}
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