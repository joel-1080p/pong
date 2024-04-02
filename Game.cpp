#include <DarkGDK.h>
#include "Game.h"



// Game object constructors.
Game::Game(){

	// Pause screen set to off.
	pause_button = 0;

	// Default NPC speed.
	npc_speed = 8;

	// Default ball speed.
	ball_speed = 9;

	// Default player speed.
	player_speed = 8;
}



// Loads images and assigns id.
void Game::getImages( void){

	// Gets all immages for this game as bmp. Size : 640 X 480.
	dbLoadImage("png_files/Background.bmp", 1);
	dbLoadImage("png_files/Paddle.bmp", 2);
	dbLoadImage("png_files/Ball.bmp", 3);
	dbLoadImage("png_files/TopBottomBorder.bmp", 4);
	dbLoadImage("png_files/LeftRightBorder.bmp", 5);
	dbCreateAnimatedSprite(9,"png_files/Numbers.bmp", 8, 1, 6);		// Player score.
	dbCreateAnimatedSprite(10,"png_files/Numbers.bmp", 8, 1, 6);	// NPC Score.
	dbLoadImage("png_files/Winner.bmp", 7);
	dbLoadImage("png_files/Pause.bmp",8);
	dbLoadImage("png_files/TittleScreen.bmp",9);
	dbLoadImage("png_files/PauseScreen.bmp", 10);

	return;
}




// Creates sprites for this game.
void Game::createGameSprites( void){
	dbSprite(1, 0, 0, 1);			// Game wallpaper
	dbSprite(2, 25, 220, 2);		// Player 1
	dbSprite(3, 610, 220, 2);		// NPC
	//dbSprite(4, x, y, 3);			// Ball [CREATED LATER]
	dbSprite(5, 0, 0, 4);			// top border
	dbSprite(6, 0, 475, 4);			// bottom border
	dbSprite(7, -10, 0, 5);			// left wall
	dbSprite(8, 648, 0, 5);			// Right wall
	dbSprite(9, 135, 30, 6);		// Player 1 Score
	dbSprite(10, 455, 30, 6);		// NPC Score

	return;
}



// Hides all sprites while initial loading screen.
void Game::hideAllGameSprites( void){
	dbHideSprite(1);			//Wallpaper
	dbHideSprite(2);			//Player1
	dbHideSprite(3);			//Player2
	dbHideSprite(4);			//Ball
	dbHideSprite(5);			//Top border
	dbHideSprite(6);			//Bottom border
	dbHideSprite(7);			//Left wall
	dbHideSprite(8);			//Right wall
	dbHideSprite(9);			//Player 1 score
	dbHideSprite(10);			//Player 2 score		
	return;
}



// Show all sprites afrer loading screen is done.
void Game::showAllGameSprites( void){
	dbShowSprite(1);			// Wallpaper
	dbShowSprite(2);			// Player 1
	dbShowSprite(3);			// NPC
	dbShowSprite(4);			// Ball
	dbShowSprite(5);			// Top border
	dbShowSprite(6);			// Bottom border
	dbShowSprite(7);			// Left wall
	dbShowSprite(8);			// Right wall
	dbShowSprite(9);			// Player 1 score
	dbShowSprite(10);			// Player 2 score
	return;
}



// Deletes all the sprites.
void Game::DeleteAllSprites( void){
	for(int i = 1; i <= 20; i++)
	{
		dbDeleteImage(i);
		dbDeleteSprite(i);
	}
	return;
}



// Shows or removes pause screen after hitting space bar.
void Game::pause(){

	// If pause screen is not showing.
	if(pause_button == 0){
		pause_button = 1;

		//Creates pause menu sprite.
		dbSprite(17, 0, 0, 10);

		// Waits for user input.
		dbWaitKey();

		//Deletes pause menu sprite.
		dbDeleteSprite(17);

	}

	// If pause screen is already showing.
	else{
		pause_button = 0;
	}

	return;
}



// Getter for pause variable.
int Game::getPause(void)const{
	return pause_button;
}



// Setter for pause variable.
void Game::changePause(int x){
	pause_button = x;
}