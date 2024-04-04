#ifndef PLAYER_H
#define PLAYER_H


class Player {
	public:
		Player(void);

		// Controls what happens when the player hits the ball.
		void hittingTheBall(void);

		// Controls what happens if the player scores.
		void score(void);

		// If player 1 wins the point, reset sprite position.
		void reset(void);

		// Getter for score counter.
		int getCurrentScore(void);

		// Setter for score counter.
		void setCurrentScore(int);

		int getScoreSprite(void);


	protected:
		// Keeps the score.
		int current_score;

		// Speed of player paddle.
		int paddle_speed;

		// Angle up when the paddle sprite and ball sprite collide.
		int push_ball_angle_up;

		// Straight angle when the paddle sprite and ball sprite collide.
		int push_ball_angle_straight;

		// Angle down when the paddle sprite and ball sprite collide.
		int push_ball_angle_down;

		// The number of the sprite paddle index.
		int sprite_paddle;

		// The sprite the ball needs to hit for this player to get a point.
		int scoring_wall_sprite;

		// When the player scores, it changes the score sprite number.
		int score_sprite;

		// Reset X position of the paddle sprite;
		int paddle_x;

		// Reset Y position of the paddle sprite;
		int paddle_y;
};

#endif