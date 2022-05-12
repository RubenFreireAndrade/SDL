#pragma once

#include "Sprite.h"
#include "GameObject.h"

class Rocket : public GameObject
{

public:

	Rocket();
	~Rocket();

	void Initialise(Screen& screen, std::list<GameObject*>* gameObjects);
	void ShutDown();

	// Inherited via GameObject
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:
	Sprite m_rocket;
	std::list<GameObject*>* m_gameObjects = {};
};

