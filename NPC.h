#ifndef NPC_H
#define NPC_H

#include "Game.h"

// Child NPC class from Game Class.
class NPC : Game{
	public:

		// Constructor for NPC object.
		NPC();

		// Moves NPC up or down.
		void movement();

		// Controls what happens when the NPC hits the ball.
		void hittingTheBall();

		// Controls what happens if the NPC scores.
		void score();

		// If NPC wins the point, reset sprite position.
		void reset();

		// If NPC wins the game, resets game sprites.
		void gameOver();

		// Getter for score counter.
		int getScoreCounter(int);

	private:

		// Keeps the NPC score.
		int score_counter;
};

#endif