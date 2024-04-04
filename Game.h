#ifndef GAME_H
#define GAME_H

#include "Player1.h"
#include "NPC.h"

class Game{
	public:
		Game(void);

		// Launches splash screen and loads all of the sprites.
		void loadGame(void);

		// Gets all images for this game as bmp. Size : 640 X 480.
		void getImages(void);

		// Creates sprites for this game.
		void createGameSprites(void);

		// Deletes all the sprites.
		void DeleteAllSprites(void);

		// Shows or removes pause screen after hitting space bar.
		void pause(void);

		// Getter for pause variable.
		int getPause(void);

		// Setter for pause variable.
		void setPause(int);

		// Checks if either NPC or Player 1 has won.
		// If so, reset all of the sprites.
		void gameOver(NPC& npc, Player1& player1);
	
	private:

		// Controls if pause screen is enabled.
		int pause_button;
};

#endif