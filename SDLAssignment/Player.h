#pragma once
#include <iostream>
#include <SDL.h>
#include "input.h"
#include "Sprite.h"
#include "Sounds.h"
#include "Bullet.h"
#include "Vector2D.h"
#include "GameObject.h"

class Player : public GameObject
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

	enum class Direction
	{
		LEFT,
		RIGHT
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

	Input input;
	State m_state = {};
	Direction m_spriteDirection = {};
	Sprite m_image[TOTAL_STATES];

	int score;
	int speed = 3;
	int jumpHeight = 70;
	int maxCoinPoints = 4;

	bool isTouching = false;
	bool m_shooting = false;
	bool isJumping = false;
	bool isChatting = false;
	std::string chatInput;

	std::list<GameObject*>* m_gameObjects = {};
};
