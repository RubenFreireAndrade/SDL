#pragma once

#include "GameObject.h"
#include <SDL.h>
#include "Sprite.h"
#include "Vector2D.h"
#include "Sounds.h"
#include "Bullet.h"
#include "input.h"

class Player : public GameObject		//inheritance - player is a game object
{

public:

	enum State 
	{
		IDLE,
		RUN,
		JUMP,
		DEAD,
		SHOOT,
		TOTAL_STATES
	};

	enum Direction
	{
		LEFT,
		RIGHT,
	};

	Player();
	~Player();

	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);
	virtual void CheckCollision(std::list<GameObject*> objects);

	void AddScore(int amount);
	void SetState(State state);

	int GetScore();

private:

	Sprite m_image[TOTAL_STATES];			// containment - player has an image

	State m_state;
	Direction m_spriteDirection;
	Input input;

	int speed = 3;
	int jumpHeight = 70;
	int score;
	int itemOnFloor;

	bool isTouching;
	bool m_shooting;
	bool isJumping;
	bool isGoalReached;

	std::list<GameObject*>* m_gameObjects;
};