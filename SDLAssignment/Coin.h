#pragma once

#include<SDL.h>
#include "Screen.h"
#include "GameObject.h"
#include "Player.h"
#include "Sprite.h"
#include "Vector2D.h"



class Coin : public GameObject
{

public:

	Coin(/*int x, int y*/);
	~Coin();

	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

	void Pickup(Player* player);


private:

	Sprite m_image;
	std::list<GameObject*>* m_gameObjects;
};

