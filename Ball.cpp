#include "DarkGDK.h"
#include "Ball.h"



// Ball constructor.
Ball::Ball(void){

	// Player always gets the ball at first.
	ball_control = 1;

	// Default ball speed.
	ball_speed = 9;

	return;
}



// If ball sprite (4) exist, move at set ball speed.
void Ball::movement(void){
	if(dbSpriteExist(4) == 1){
		dbMoveSprite(4, ball_speed);
	}

	return;
}



// Checks when the ball hits a wall.
void Ball::collision(void){

	// If ball hits top border.
	if(dbSpriteCollision(4, 5) == 1){

		// If the ball hits at 45*, rotate to 135*.
		if(dbSpriteAngle(4) == 45){
			dbRotateSprite(4, 135);
		}

		// If the ball hits at 315*, rotate to 225*.
		if(dbSpriteAngle(4) == 315)
			dbRotateSprite(4, 225);

	}

	// If it hits bottom border.
	if(dbSpriteCollision(4, 6) == 1){

		// If the ball hits at 225*, rotate to 315*.
		if (dbSpriteAngle(4) == 225){
			dbRotateSprite(4, 315);
		}

		// If the ball hits at 135*, rotate to 45*.
		if(dbSpriteAngle(4) == 135){
			dbRotateSprite(4, 45);
		}
	}

	return;
}



// Checks collisions with outside walls.
void Ball::goalCheck(void){

	// If the ball goes outside screen on left.
	if(dbSpriteX(4) < -10 && dbSpriteExist(4) == 1){

		// lets first player have the ball.
		ball_control = 1;

		// Delete ball sprite.
		dbDeleteSprite(4);

		return;
	}

	// IF the ball goes outside screen right.
	else if(dbSpriteX(4) > 650 && dbSpriteExist(4) == 1){

		// Lets NPC have the ball.
		ball_control = 2;

		// Delete ball sprite.
		dbDeleteSprite(4);

		return;
	}

	return;
}



// If a wining collision happens, reset ball sprite.
void Ball::reset(void){

	// If the user hits space key and ball sprite does not exist,
	// reset the game.
	if(dbSpaceKey() == 1 && dbSpriteExist(4) == 0){

		// First players ball after NPC scores.
		// Reset all of the sprites for ball.
		if(ball_control == 1){

			// Create ball sprite on the NPC side.
			dbSprite(4, 700, 240, 3);

			// Rotates the ball in the direction of player 1.
			dbOffsetSprite(4, 10, 10);
			dbRotateSprite(4, 270);
			dbMoveSprite(4, 270);
		}

		// NPC ball after player 1 scores.
		// Reset all of the sprites ball.
		if(ball_control == 2){

			// Create ball sprite on the player 1 side.	
			dbSprite(4, 300, 240, 3);

			// Rotates the ball in the direction of player 1.
			dbOffsetSprite(4, 10, 10);
			dbRotateSprite(4, 90);
		}
	}

	return;
}