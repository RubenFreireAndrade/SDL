#pragma once
#include <vector>
#include "Screen.h"
#include "Sprite.h"
#include "GameObject.h"

class EndScreen : public GameObject
{
public:

	enum ConditionState
	{
		WIN,
		LOSS
	};

	enum class EndScreenButtonState
	{
		DEFAULT,
		HOVERED,
		CLICKED
	};

	EndScreen(const std::string& fileName, Screen& screen);
	~EndScreen();

	// Inherited via GameObject
	virtual void Update(Input& input);
	virtual void Render(Screen& screen, int state);
	void Initialise(Screen& screen);
	void ShutDown();
private:

	TTF_Font* font = nullptr;

	int PosX = 0;
	int PosY = 0;
	Sprite m_button;
};

