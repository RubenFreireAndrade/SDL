#pragma once
#include <string>
#include <SDL.h>
#include "Screen.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Player.h"

class Enemy : public GameObject
{

public:
	
	Enemy(Vector2D pos, Vector2D dest);
	~Enemy();
	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);
	void Render(Screen& screen);
	void Update(Input& input);
	void EnemyHit();
private:

	Sprite m_image;

	int speed = 2;
	bool toDestination = true;

	Vector2D m_destination;
	Vector2D m_startingPos;

	std::list<GameObject*>* m_gameObjects = {};
};
