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

	Bullet(Vector2D spawnPos, Vector2D bulletDir, Screen& screen);
	~Bullet();
	
	void Initialise(Screen& screen);
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);
	void CheckCollision(std::list<GameObject*> objects);

private:

	int speed = 4;
	SDL_Color m_color;

	Screen m_window;
	Sprite m_bulletSprite;
	Vector2D m_direction;
	Vector2D m_velocity;
};

