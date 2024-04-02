#ifndef PLAYER1_H
#define PLAYER1_H

#include "Game.h"

// Child Player1 class from Game Class.
class Player1 : Game{
	public:

		// Constructor for player object.
		Player1();

		// Moves player up or down.
		void movement();

		// Controls what happens when the player hits the ball.
		void hittingTheBall();

		// Controls what happens if the player scores.
		void score();

		// If player 1 wins the point, reset sprite position.
		void reset();

		// If player wins the game, resets game sprites.
		void gameOver();

		// Getter for score counter.
		int getScoreCounter(int);

	private:

		// Keeps the player's score.
		int score_counter;
};
#endif