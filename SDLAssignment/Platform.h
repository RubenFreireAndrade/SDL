#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include <SDL.h>

class Platform : public GameObject
{

public: 

	Platform(/*int x, int y*/);
	~Platform();

	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);
	void Collision();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);



private:

	SDL_Color m_color;
	Sprite m_image;
	std::list<GameObject*>* m_gameObjects;
};

