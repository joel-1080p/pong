#ifndef PLAYER1_H
#define PLAYER1_H

#include "Player.h"

// Child Player1 class from Player Class.
class Player1: public Player {
	public:

		// Constructor for player object.
		Player1(void);

		// Moves player up or down.
		void move(void);
};

#endif