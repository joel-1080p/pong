#include <iostream>
#include "DarkGDK.h"
#include "Player1.h"
#include "NPC.h"
#include <time.h> 



// Constructor for NPC.
NPC::NPC(void){

	// Angle up when the paddle sprite and ball sprite collide.
	push_ball_angle_up = 315;

	// Straight angle when the paddle sprite and ball sprite collide.
	push_ball_angle_straight = 270;

	// Angle down when the paddle sprite and ball sprite collide.
	push_ball_angle_down = 225;

	// The number of the sprite paddle index.
	sprite_paddle = 3;

	// The sprite the ball needs to hit for this player to get a point.
	scoring_wall_sprite = 7;

	// When the player scores, it changes the score sprite number.
	score_sprite = 10;

	// Reset X position of the paddle sprite;
	paddle_x = 610;

	// Reset Y position of the paddle sprite;
	paddle_y = 220;

	return;
}



// Moves NPC up or down.
void NPC::move(void){

	// If the ball does not exists (Match over).
	if (dbSpriteExist(4) != 1) {
		return;
	}

	// Gets current ball x and y position.
	int ballYPos = dbSpriteY(4);
	int ballXPos = dbSpriteX(4);

	// Gets current NPC Y position.
	int npc_y_pos = dbSpriteY(3);
	
	// If the ball X position is less than 450 pxl (On the user's side)
	if(ballXPos < 450){

		// Stop moving the NPC.
		dbMoveSprite(sprite_paddle, 0);

		return;
	}

	// If the ball x position is on the UPC side.
	// If the ball Y position < NPC Y position, move NPC down by -3.
	if (npc_y_pos < ballYPos) {
		dbMoveSprite(sprite_paddle, (-1 * paddle_speed));
		return;
	}

	// If the ball Y position > NPC Y position.
	dbMoveSprite(sprite_paddle, paddle_speed);

	return;
}