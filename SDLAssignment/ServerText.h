#pragma once
#include"GameObject.h"
#include"TextToScreen.h"

class ServerText : public GameObject
{
public:
	ServerText(const std::string& message, Screen& screen);
	~ServerText();

	// Inherited via GameObject
	void Initialise(Screen& screen);
	void Update(Input& input, GameState& state);
	void Render(Screen& screen);
	void Shutdown();

	void SetIncomingText(std::string text);
	std::string GetIncomingText();

private:
	TextToScreen m_serverTxt;

	std::string m_incomingText;
};

