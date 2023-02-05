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

	virtual void Update(Input& input, GameState& state);
	virtual void Render(Screen& screen);
	virtual void Instantiate(Screen& screen, GameState& state);
	void CheckCollision(std::list<GameObject*> objects);

private:

	int speed = 4;
	SDL_Color m_color;

	Screen m_window;
	Sprite m_bulletSprite;
	Vector2D m_direction;
	Vector2D m_velocity;
};

