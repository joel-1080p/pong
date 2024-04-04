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
	Player1 player1;
	NPC npc;
	Ball Ball;
	Game game;

	// Launches splash screen and loads all of the sprites.
	game.loadGame();

	// Main game loop.
	while (LoopGDK()){

		// If user presses return key, the game will pause.
		if (dbReturnKey())
			game.pause();

		// Player objects and functions.
		player1.move();
		player1.hittingTheBall();
		player1.score();
		player1.reset();

		// NPC objects and functions.
		npc.move();
		npc.hittingTheBall();
		npc.score();
		npc.reset();

		// Ball objects and functions.
		Ball.movement();
		Ball.collision();
		Ball.goalCheck();
		Ball.reset();

		// Checks to see if there is a winner.
		game.gameOver(npc, player1);

		dbSync();
	}

	// If the game is over, clean up memory.
	game.DeleteAllSprites();

	dbWaitKey();
}