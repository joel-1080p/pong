#include "DarkGDK.h"
#include "Player1.h"
#include "NPC.h"
#include <time.h> 

// basic file operations
#include <iostream>
#include <fstream>
using namespace std;



// Constructor for player object.
Player1::Player1(){

	// Sets score to 1 beacuse it will pull the image "1" which is 0.
	score_counter = 1;
}



// Moves player up or down.
void Player1::movement(){

	// If arrow up is hit and there hasn't been a ball collision.
	if (dbUpKey() == 1 && dbSpriteCollision(2, 5) == 0){

		// Moves player 2 pixels at set speed.
		dbMoveSprite(2, player_speed);
	}

	// If arrow down is hit and there hasn't been a ball collision.
	if (dbDownKey() == 1 && dbSpriteCollision(2, 6) == 0) {

		// Moves player -2 pixels at set speed.
		dbMoveSprite(2, (-1 * player_speed));
	}

	return;
}




// Controls what happens when the player hits the ball.
void Player1::hittingTheBall(){

	// If there has been collision between player 1 and ball.
	if (dbSpriteCollision(2, 4) == 1) {

		// ANGLE REFRENCE
		// 45 : up
		// 135 : down
		// 90 : straight

		/* initialize random seed: */
		srand(time(NULL));

		// Randon number for all of the posible angles.
		int rand_angel = rand() % 9 + 1;

		// If the random number == 5, send the ball straight.
		if (rand_angel == 5) {
			dbRotateSprite(4, 90);
			return;
		}

		// If the random number is even, send the ball up.
		if (rand_angel % 2 == 0) {
			dbRotateSprite(4, 45);
			return;
		}

		// If the number is odd, send the ball down.
		dbRotateSprite(4, 135);

		return;

	}
	return;
}



// Controls what happens if the player scores.
void Player1::score(){

	// If there has been a collision between NPC wall and the ball.
	if(dbSpriteCollision(4, 8) == 1 && dbSpriteHit(4, 8) == 1){

		// Increases player 1 score by 1.
		score_counter++;

		// Sets score sprite (9) to the next score number.
		dbSetSpriteFrame(9, score_counter);
	}
}



// If player 1 wins the point, reset sprite position.
void Player1::reset(){
	if(dbSpaceKey() == 1 && dbSpriteExist(4) == 0)
		dbSprite(2, 25, 220, 2);
}



// If the game is over, reset all player 1 sprite positions.
void Player1::gameOver(){

#	// If player score is 7 (8th sprite).
	if(score_counter == 8){

		// Show that player 1 is the winner.
		dbSprite(11, 63, 100, 7);		

		// If the user hits space to start a new game.
		if(dbSpaceKey() == 1){

			// Deletes player 1 winner logo
			dbDeleteSprite(11);

			// Reset player 1 score.
			score_counter = 1;

			
			dbSetSpriteFrame(9, score_counter);

			// Creates NPC object
			NPC npc;

			// Sets NPC score
			npc.getScoreCounter(1);

			// Show 0 for player 1 and loops game
			dbSetSpriteFrame(14, score_counter);

			// Show 0 for plaeyr 2 and loops game
			dbSetSpriteFrame(15, score_counter);

			dbSetSpriteFrame(10, 1);
		}
	}
}



// Getter for score counter.
int Player1::getScoreCounter(int x){
	x = score_counter;
	return x;
}