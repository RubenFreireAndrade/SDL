#pragma once
#include <string>
#include <SDL.h>
#include "Screen.h"
#include "GameObject.h"
#include "Sprite.h"

class Background : public GameObject
{

public:

	Background();
	~Background() {}
	
	void Initialise(Screen& screen);
	void Update(Input& input);
	void Render(Screen& screen);

private:
	
	Sprite m_image;
	Vector2D m_velocity;

	int speed = 3;
	bool m_shooting;

	int worldSize;
};

