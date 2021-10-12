#pragma once
#include <SDL.h>
#include "Screen.h"
#include "GameObject.h"
#include "Sprite.h"

class MainMenu : public GameObject
{

public:

	MainMenu();
	~MainMenu();

	void Initialise(Screen& screen);
	void Update(Input& input);
	void Render(Screen& screen);

private:

	Sprite m_image;
	//int gameState;
};

