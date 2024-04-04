#include "DarkGDK.h"
#include "Player1.h"
#include "NPC.h"
#include <time.h> 

#include "Player.h"

// Constructor for player object.
Player1::Player1(void){

	// Angle up when the paddle sprite and ball sprite collide.
	push_ball_angle_up = 45;

	// Straight angle when the paddle sprite and ball sprite collide.
	push_ball_angle_straight = 135;

	// Angle down when the paddle sprite and ball sprite collide.
	push_ball_angle_down = 90;

	// The number of the sprite paddle index.
	sprite_paddle = 2;

	// The sprite the ball needs to hit for this player to get a point.
	scoring_wall_sprite = 8;

	// When the player scores, it changes the score sprite number.
	score_sprite = 9;

	// Reset X position of the paddle sprite;
	paddle_x = 25;

	// Reset Y position of the paddle sprite;
	paddle_y = 220;

	return;
}



// Moves player up or down.
void Player1::move(void){

	// If arrow up is hit and there hasn't been a ball collision.
	if (dbUpKey() == 1 && dbSpriteCollision(2, 5) == 0){

		// Moves player 2 pixels at set speed.
		dbMoveSprite(2, paddle_speed);

		return;
	}

	// If arrow down is hit and there hasn't been a ball collision.
	if (dbDownKey() == 1 && dbSpriteCollision(2, 6) == 0) {

		// Moves player -2 pixels at set speed.
		dbMoveSprite(2, (-1 * paddle_speed));

		return;
	}

	return;
}