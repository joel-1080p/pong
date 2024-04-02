#include <iostream>
#include "DarkGDK.h"
#include "Player1.h"
#include "NPC.h"
#include <time.h> 

// basic file operations
#include <iostream>
#include <fstream>
using namespace std;


// Constructor for NPC.
NPC::NPC(){

	// Sets score to 1 beacuse it will pull the image "1" which is 0.
	score_counter = 1;
}



// Moves NPC up or down.
void NPC::movement(){

	// Gets current ball x and y position.
	int ballYPos = dbSpriteY(4);
	int ballXPos = dbSpriteX(4);

	// Gets current NPC position.
	int npc_y_pos = dbSpriteY(3);
	
	// If the ball exsists.
	if(dbSpriteExist(4) == 1){

		// If the ball x position is less than 450 pxl (On the user's side)
		if(ballXPos < 450){

			// Stop moving the NPC.
			dbMoveSprite(3, 0);
		}

		// If the ball x position is on the UPC side.
		else {

			// If the ball Y posiyion < NPC Y position, move NPC down by -3.
			if (npc_y_pos < ballYPos) {
				dbMoveSprite(3, (-1 * npc_speed));
				return;
			}

			// If the ball Y posiyion > NPC Y position.
			dbMoveSprite(3, npc_speed);
		}
	}

	return;
}



// Controls what happens when the NPC hits the ball.
void NPC::hittingTheBall(){

	// If there is a collisino with the ball.
	if(dbSpriteCollision(3, 4) == 1){

		// ANGLE REFRENCE
		// 315 : up
		// 225 : down
		// 270 : straight

		/* initialize random seed: */
		srand(time(NULL));

		// Randon number for all of the posible angles.
		int rand_angel = rand() % 9 + 1;

		// If the random number == 5, send the ball straight.
		if (rand_angel == 5) {
			dbRotateSprite(4, 270);
			return;
		}

		// If the random number is even, send the ball up.
		if (rand_angel % 2 == 0) {
			dbRotateSprite(4, 315);
			return;
		}

		// If the number is odd, send the ball down.
		dbRotateSprite(4, 225);

		return;
	}
}



// Controls what happens if the NPC scores.
void NPC::score(){

	// If there is a collission on the left wall and the ball.
	if(dbSpriteCollision(4, 7) == 1 && dbSpriteHit(4, 7) == 1){
		score_counter++;

		// Shows score.
		dbSetSpriteFrame(10, score_counter);			
	}

	return;
}



// If NPC wins the point, reset sprite position.
void NPC::reset(){

	// If space bar is hit after game is over.
	if (dbSpaceKey() == 1 && dbSpriteExist(4) == 0) {

		// Reset sprite.
		dbSprite(3, 610, 220, 2);
	}

	// If NPC wins with 8 points,
	if(score_counter == 8){

		// Shows the score.
		dbSprite(11, 383, 100, 7);
	}
}



// NPC score getter.
int NPC::getScoreCounter(int x){
	x = score_counter;
	return x;
}



// If the game is over, reset all NPC sprite positions.
void NPC::gameOver(){

	// If the NPC has 8 points.
	if(score_counter == 8){

		// Show if NPC is the winner.
		dbSprite(11, 400, 100, 7);			

		// If space key is hit to start new game.
		if(dbSpaceKey() == 1){

			//Deletes player 2 winner logo
			dbDeleteSprite(11);

			// Reset NPC score.
			score_counter = 1;

			// Changes score sprite back to 0.
			dbSetSpriteFrame(10, score_counter);

			// Resets player 1 sprites and score.
			Player1 plr1;							
			plr1.getScoreCounter(1);
			dbSetSpriteFrame(14, score_counter);
			dbSetSpriteFrame(15, score_counter);
			dbSetSpriteFrame(9, 1);
		}
	}
}