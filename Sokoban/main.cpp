#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screens.h"
#include "levels.h"
#include "levelCreator.h"

using namespace sf;
using namespace std;

#define WWIDTH 1200
#define WHEIGHT 800

int main(){
	// Initialize screen and level numbers
	int screen = 0;
	int curLvl = 0;
	// Create window
	RenderWindow app(VideoMode(WWIDTH, WHEIGHT, 32),
		"Sokoban v. alpha 0.1 by B. Krzyzanek",
		Style::Titlebar | Style::Close);
	app.setMouseCursorVisible(false);
	app.setFramerateLimit(60); 
	// Create objects of screens
	Menu menu(app.getSize().x, app.getSize().y, "Play", "Custom level", "Exit");
	LevelMenu levelMenu(app.getSize().x, app.getSize().y);
	Menu pauseMenu(app.getSize().x, app.getSize().y, "Continue", "Back to menu", "Exit");
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
	for (int i = 0; i < levels.size(); i++)
		levels[i].createMatrix(levels[i].saveMatrix);
	// Main game loop
	while (app.isOpen()){
			app.clear();  
			switch (screen) {	
			case 0: {												// Menu screen
				int state = menu.run(app);							// Which button was pressed
				if (state == 1) screen = 1;							//  -> Level choosing menu
				else if (state == 2) screen = 2;					//  -> Level creator
				else if (state == 3) app.close();
				break;
			}
			case 1:  												// Level choosing menu
				curLvl = levelMenu.run(app);						// Selected level if space pressed
				if (curLvl > -1) screen = 3;						// Display game level
				else if (curLvl == -2) screen = 0;					// Go to previous menu if Esc pressed
				break;
			case 2: {												// Level Creator screen
				int state = levelCreator.run(app, levels[11]);		// Which screen should be presented next
				if (state == 0) screen = 0;							// Go to previous menu if Esc pressed
				break;
			}
			case 3: {												// Levels screen (with game)
				int state = levels[curLvl].run(app);				// State of the game (0 - play, 1 - next level, 2 - pause)
				if (state == 1 && curLvl < 11) curLvl++;			// Level to next if possible (after winning)
				else if (state == 1 && curLvl == 11) {
					curLvl = 0;										//  Level to first
					screen = 0;										// -> Menu
				}
				else if (state == 2) screen = 4;					// -> Pause
				break;
			}
			case 4: {	
				int state = pauseMenu.run(app);						// Which button was pressed
				if (state == 1) screen = 3;							//  -> Level choosing menu
				else if (state == 2) screen = 0;					//  -> Level creator
				else if (state == 3) app.close();
				break;// Pause menu
			}
			}
			
			app.display();											// display everything
	}
	return EXIT_SUCCESS;
}