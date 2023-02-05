#pragma once
#include<string>

#include"Sprite.h"
#include"GameObject.h"
#include"TextToScreen.h"

class MenuButtonText : public GameObject
{
public:
	enum class ButtonState
	{
		DEFAULT,
		HOVER,
		CLICKED
	};

	MenuButtonText(std::string text);
	// Inherited via GameObject
	virtual void Update(Input& input, GameState& state);
	virtual void Render(Screen& screen);
	void ShutDown();

	void GetButtonRect();
	const ButtonState& GetState() const;
private:
	Sprite m_btnSprite;
	TextToScreen m_btnText;

	SDL_Rect buttonPosition;
	SDL_Point mousePosition;
	ButtonState buttonState;
};