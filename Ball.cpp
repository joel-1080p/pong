#include "DarkGDK.h"
#include "Ball.h"


// Ball constructor.
Ball::Ball(){

	//Player always gets the ball at first.
	ball_control = 1;
}



// If ball sprite (4) exist, move at set ball speed.
void Ball::movement(){
	if(dbSpriteExist(4) == 1){
		dbMoveSprite(4, ball_speed);
	}
}



// Checks when the ball hits a wall.
void Ball::collision(){

	// If ball hits top border.
	if(dbSpriteCollision(4, 5) == 1){

		// If the ball hits at 45*, rotate to 135%.
		if(dbSpriteAngle(4) == 45){
			dbRotateSprite(4, 135);
		}

		// If the ball hits at 315*, rotate to 225%.
		if(dbSpriteAngle(4) == 315)
			dbRotateSprite(4, 225);

	}

	// If it hits bottom border.
	if(dbSpriteCollision(4, 6) == 1){

		// If the ball hits at 225*, rotate to 315%.
		if (dbSpriteAngle(4) == 225){
			dbRotateSprite(4, 315);
		}

		// If the ball hits at 135*, rotate to 45%.
		if(dbSpriteAngle(4) == 135){
			dbRotateSprite(4, 45);
		}
	}
}



// Checks collisions with outside walls.
void Ball::goalCheck(){

	// If the ball goes outside screen on left.
	if(dbSpriteX(4) < -10 && dbSpriteExist(4) == 1){
		dbDeleteSprite(4);

		// lets first player have the ball.
		ball_control = 1;
	}

	// IF the ball goes outside screen right.
	if(dbSpriteX(4) > 650 && dbSpriteExist(4) == 1){
		dbDeleteSprite(4);

		// Lets NPC have the ball.
		ball_control = 2;
	}
}



// If a wining collision hapens, reset sprites.
void Ball::reset(){
	if(dbSpaceKey() == 1 && dbSpriteExist(4) == 0){

		// First players ball after NPC scores.
		// Reset all of the sprites.
		if(ball_control == 1){
			dbSprite(4, 700, 240, 3);
			dbOffsetSprite(4, 10, 10);
			dbRotateSprite(4, 270);
			dbMoveSprite(4, 270);
		}

		// NPC ball after player 1 scores.
		// Reset all of the sprites.
		if(ball_control == 2){			
			dbSprite(4, 300, 240, 3);
			dbOffsetSprite(4, 10, 10);
			dbRotateSprite(4, 90);
		}
	}
}