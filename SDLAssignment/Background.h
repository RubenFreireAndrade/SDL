#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "GameObject.h"

class Background : public GameObject
{
public:

	Background(const std::string& fileName, Screen& screen);
	~Background() {}
	
	void Initialise(Screen& screen);
	void Update(Input& input, GameState& state);
	void Render(Screen& screen);
	void ShutDown();

private:
	Sprite m_image;
};

