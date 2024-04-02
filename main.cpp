#include "DarkGDK.h"
#include "Player1.h"
#include "Ball.h"
#include "Game.h"
#include "NPC.h"

void DarkGDK(){
	dbSyncOn;
	dbSyncRate(60);
	dbSetImageColorKey(126, 255, 64);
	dbRandomize(dbTimer());

	// Game objects.
	Player1 Player1;
	NPC npc;
	Ball Ball;
	Game game;

	//Gets all Images for this game.
	game.getImages();				

	//Shows "Pong, By....."
	dbSprite(12, 0, 0, 9);			

	//Wait 4 seconds
	dbWait(4750);					

	//Deletes "Pong, by...."
	dbDeleteSprite(12);				

	//Create Sprites
	game.createGameSprites();

	//Hide Sprites
	game.hideAllGameSprites();

	while (LoopGDK()){

		// Places all of the sprites.
		game.showAllGameSprites();

		// If user presses return key, the game will pause
		if (dbReturnKey())					
			game.pause();

		// Player objects and methods.
		Player1.movement();
		Player1.hittingTheBall();
		Player1.score();
		Player1.reset();
		Player1.gameOver();
		
		// NPC objects and methods.
		npc.movement();
		npc.hittingTheBall();
		npc.score();
		npc.reset();
		npc.gameOver();

		// Ball objects and methods.
		Ball.movement();
		Ball.collision();
		Ball.goalCheck();
		Ball.reset();

		dbSync();
	}

	// If the game is over, will be clean up memory.
	game.DeleteAllSprites();

	dbWaitKey();
}