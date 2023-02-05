#pragma once
#include "GameObject.h"
#include "TextToScreen.h"
#include "Player.h"

class Score : public GameObject
{
public:
	Score();
	~Score();

	void Initialise(Screen& screen, Player* p);
	virtual void Update(Input& input, GameState& state) override;
	void Render(Screen& screen);
	void AddToScore();
private:
	TextToScreen m_text = {};
	Player* m_player = {};

	// Inherited via GameObject
};

