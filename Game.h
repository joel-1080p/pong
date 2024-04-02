#ifndef GAME_H
#define GAME_H

class Game{
	public:
		Game();

		// Gets all immages for this game as bmp. Size : 640 X 480.
		void getImages( void);

		// Creates sprites for this game.
		void createGameSprites( void);

		// Hides all sprites while initial loading screen.
		void hideAllGameSprites( void);	

		// Show all sprites afrer loading screen is done.
		void showAllGameSprites( void);	

		// Deletes all the sprites.
		void DeleteAllSprites( void);		
	
		// Shows or removes pause screen after hitting space bar.
		void pause();

		// Getter for pause variable.
		int getPause()const;

		// Setter for pause variable.
		void changePause( int);

	protected:

		// Controls if pause screen is enabled.
		int pause_button;

		// Speed of the ball.
		int ball_speed;

		// Speed of NPC paddle.
		int npc_speed;

		// Speed of player paddle.
		int player_speed;
};

#endif