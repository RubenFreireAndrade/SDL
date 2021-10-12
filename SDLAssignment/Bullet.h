#pragma once
#include <SDL.h>
#include "Vector2D.h"
#include "GameObject.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

class Bullet : public GameObject
{

public:

	Bullet(Vector2D spawnPos, Vector2D bulletDir);
	~Bullet();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);
	void CheckCollision(std::list<GameObject*> objects);
	void AddScore(int amount);

	int GetScore();

	//bool isDead = false;

private:

	SDL_Color m_color;

	int speed = 4;
	int score;

	Sprite m_image;
	Screen m_window;
	Vector2D m_direction;
	Vector2D m_velocity;
};

