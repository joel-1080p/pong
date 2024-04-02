#ifndef BALL_H
#define BALL_H

#include "Game.h"

// Child Ball class from Game Class.
class Ball : Game{
	public:
		Ball();

		// If ball sprite (4) exist, move at set ball speed.
		void movement();

		// Checks when the ball hits a wall.
		void collision();

		// Checks collisions with outside walls.
		void goalCheck();

		// If a wining collision hapens, reset sprites.
		void reset();
	
	private:

		// Who gets the ball after scoring.
		int ball_control;
};

#endif