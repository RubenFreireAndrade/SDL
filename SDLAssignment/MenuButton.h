#pragma once
#include <iostream>
#include "Sprite.h"
#include "Screen.h"
#include "GameObject.h"

class MenuButton : public GameObject
{
public:
	enum class ButtonState
	{
		DEFAULT,
		HOVER,
		CLICKED
	};

	MenuButton(const std::string& filename, int imgWidth, int imgHeight, Screen& screen);
	void Initialise(Screen& screen);
	// Inherited via GameObject
	virtual void Update(Input& input, GameState& state);
	virtual void Render(Screen& screen);
	void ShutDown();
	
	void GetButtonRect();
	const ButtonState& GetState() const;

private:
	Sprite m_btnSprite;

	SDL_Rect buttonPosition;
	SDL_Point mousePosition;
	ButtonState buttonState;
};

