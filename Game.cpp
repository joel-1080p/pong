#include <DarkGDK.h>
#include "Game.h"



// Game object constructor.
Game::Game(void){

	// Pause screen set to off.
	pause_button = 0;

	return;
}


// Launches splash screen and loads all of the sprites.
void Game::loadGame(void) {

	//Gets all Images for this game.
	getImages();

	//Shows "Pong, By....."
	dbSprite(12, 0, 0, 9);

	//Wait 4 seconds
	dbWait(4750);

	//Deletes "Pong, by...."
	dbDeleteSprite(12);

	//Create Sprites
	createGameSprites();

	return;
}


// Loads images and assigns id.
void Game::getImages(void){

	// Gets all images for this game as bmp. Size : 640 X 480.
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
void Game::createGameSprites(void){
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
	//dbSprite(11, x, y, 7);		// Winner Banner [CREATED LATER]
	//dbSprite(12, 0, 0, 10);		// Pause screen sprite [CREATED LATER]

	return;
}



// Deletes all the sprites to clean memory. 
void Game::DeleteAllSprites(void){
	for(int i = 1; i <= 20; i++){
		dbDeleteImage(i);
		dbDeleteSprite(i);
	}
	return;
}



// Shows or removes pause screen after hitting space bar.
void Game::pause(void){

	// If pause screen is already showing, unpause.
	if (pause_button != 0) {
		pause_button = 0;
		return;
	}

	// If pause screen is not showing.
	pause_button = 1;

	//Creates pause menu sprite.
	dbSprite(12, 0, 0, 10);

	// Waits for user input.
	dbWaitKey();

	//Deletes pause menu sprite.
	dbDeleteSprite(12);
	
	return;

}



// Getter for pause variable.
int Game::getPause(void){
	return pause_button;
}



// Setter for pause variable.
void Game::setPause(int x){
	pause_button = x;
	return;
}



// Checks if either NPC or Player 1 has won.
// If so, reset all of the sprites.
void Game::gameOver(NPC& npc, Player1& player1) {

	// If neither player 1 or npc has won the game.
	if (npc.getCurrentScore() != 8 && player1.getCurrentScore() != 8 ) {
		return;
	}

	// If player 1 wins the game, show banner.
	if (player1.getCurrentScore() == 8) {
		dbSprite(11, 63, 100, 7);
	}
	// If npc wins the game, show banner.
	else {
		dbSprite(11, 400, 100, 7);
	}

	// If the user hits space to start a new game.
	if (dbSpaceKey() == 1) {

		// Deletes player winner banner.
		dbDeleteSprite(11);

		// Reset player scores.
		player1.setCurrentScore(1);
		npc.setCurrentScore(1);

		// Resets the score printed on the screen for both players.
		dbSetSpriteFrame(player1.getScoreSprite(), player1.getCurrentScore());
		dbSetSpriteFrame(npc.getScoreSprite(), npc.getCurrentScore());
	}

	return;
}