#pragma once
#include"Sprite.h"
#include"GameObject.h"
#include"TextToScreen.h"

class ChatBox : public GameObject
{
public:
	ChatBox(const std::string fileName, Screen& screen);
	~ChatBox();
	// Inherited via GameObject
	void Initialise(Screen& screen);
	void Update(Input& input, GameState& state);
	void Render(Screen& screen);
	void Shutdown();

	void SetChatInput(std::string t);
	void AddChatText(std::string t);
	void AddIncomingText(std::string username, std::string t);
	void AddOutgoingText(std::string t);

private:
	TextToScreen m_inputLine;
	std::vector<TextToScreen> m_chat;

	Sprite m_image;
};