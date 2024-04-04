#ifndef NPC_H
#define NPC_H

#include "Player.h"

// Child NPC class from Player Class.
class NPC: public Player {
	public:
		NPC(void);

		// Moves NPC up or down.
		void move(void);
};

#endif