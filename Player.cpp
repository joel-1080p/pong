#include "DarkGDK.h"
#include "Player.h"
#include "NPC.h"
#include <time.h> 


// Constructor for player object.
Player::Player(void){

	// Sets the default score to 1 because it will pull the image "1" which is 0.
	current_score = 1;

	// Default paddle speed.
	paddle_speed = 8;

	return;
}



// Controls what happens when the player hits the ball.
void Player::hittingTheBall(void){

	// If there has not been collision between player 1 and ball.
	if (dbSpriteCollision(sprite_paddle, 4) == 0) {
		return;
	}

	// Initialize random seed.
	srand(time(NULL));

	// Random number from 1 to 9.
	int rand_angel = rand() % 9 + 1;

	// If the random number == 5, send the ball straight.
	if (rand_angel == 5) {
		dbRotateSprite(4, push_ball_angle_straight);
		return;
	}

	// If the random number is even, send the ball up.
	if (rand_angel % 2 == 0) {
		dbRotateSprite(4, push_ball_angle_up);
		return;
	}

	// If the number is odd, send the ball down.
	dbRotateSprite(4, push_ball_angle_down);

	return;
}



// Controls what happens if the player scores.
void Player::score(void){

	// If there has been a collision between apposing player wall and the ball.
	if(dbSpriteCollision(4, scoring_wall_sprite) == 1 && dbSpriteHit(4, scoring_wall_sprite) == 1){

		// Increases player score by 1.
		current_score++;

		// Sets player sprite score (visual score) to current score.
		dbSetSpriteFrame(score_sprite, current_score);
	}

	return;
}



// If player wins the point, reset sprite position.
void Player::reset(){

	// If the space bar is hit and the ball does not exsist.
	if(dbSpaceKey() == 1 && dbSpriteExist(4) == 0)
		dbSprite(sprite_paddle, paddle_x, paddle_y, 2);
	return;
}



// Getter for score counter.
int Player::getCurrentScore(void){
	return current_score;
}



// Setter for score counter.
void Player::setCurrentScore(int x){
	current_score = x;
	return;
}

int Player::getScoreSprite(void){
	return score_sprite;
}