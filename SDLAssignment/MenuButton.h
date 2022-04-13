#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Screen.h"

class MenuButton : public GameObject
{
public:
	enum class ButtonState
	{
		DEFAULT,
		HOVER,
		CLICKED
	};

	MenuButton(const std::string& filename, Screen& screen);
	void Initialise(Screen& screen);
	void GetButtonRect();
	const ButtonState& GetState() const;
	void ShutDown();
	// Inherited via GameObject
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:
	Sprite m_sprite;

	SDL_Rect buttonPosition;
	SDL_Point mousePosition;
	ButtonState buttonState;
};

