#pragma once

#include <SDL.h>
#include "Sprite.h"
#include "GameObject.h"

class Platform : public GameObject
{

public: 

	Platform();
	~Platform();

	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);
	void ShutDown();

	virtual void Update(Input& input, GameState& state);
	virtual void Render(Screen& screen);

private:

	Sprite m_image;
	std::list<GameObject*>* m_gameObjects = {};
};

