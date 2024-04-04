#ifndef BALL_H
#define BALL_H

class Ball {
	public:
		Ball(void);

		// If ball sprite (4) exist, move at set ball speed.
		void movement(void);

		// Checks when the ball hits a wall.
		void collision(void);

		// Checks collisions with outside walls.
		void goalCheck(void);

		// If a wining collision happens, reset ball sprite.
		void reset(void);
	
	private:

		// Who gets the ball after scoring.
		int ball_control;

		// Speed of the ball.
		int ball_speed;
};

#endif