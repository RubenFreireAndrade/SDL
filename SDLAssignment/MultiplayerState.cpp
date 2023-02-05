#include "MultiplayerState.h"

MultiplayerState::MultiplayerState(Player* p, std::string connectType) : PlayState(p)
{
	this->m_player = p;
	this->connectType = connectType;
}

bool MultiplayerState::OnEnter(Screen& screen, Input& input)
{
	PlayState::OnEnter(screen, input);

	if (this->connectType == "CLIENT")
	{
		m_chatBox = new ChatBox("ChatBox", "Attempting To Find Server", screen);

		m_chatBox->Initialise(screen);

		this->objects.push_back(m_chatBox);

		this->SDLNetInitialize();
		this->ConnectToServer();

		if (serverSocket)
		{
			input.RegisterKeyBind(SDLK_RETURN, std::bind(&MultiplayerState::ToggleChatMode, this));
			input.RegisterAnyKeyBind(std::bind(&MultiplayerState::RecordChatInput, this, std::placeholders::_1));
		}
	}
	return true;
}

GameState* MultiplayerState::Update(Input& input)
{
	// TODO - Delete Update func if not using it.
	PlayState::Update(input);
	return this;
}

void MultiplayerState::SentMessage(std::string message)
{
	std::cout << "You Sent: " << message << std::endl;
}

void MultiplayerState::ReceiveMessage(std::string message)
{
	std::cout << this->GetIp(serverSocket) << " Sent: " << message << std::endl;
	m_chatBox->SetIncomingText(message);
}

void MultiplayerState::ToggleChatMode()
{
	m_player->isChatting = !m_player->isChatting;
	if (m_player->isChatting)
	{
		std::cout << "chat mode enabled" << std::endl;
	}
	else
	{
		std::cout << std::endl << "chat mode disabled" << std::endl;
	}
}

void MultiplayerState::RecordChatInput(char key)
{
	if (!m_player->isChatting)
	{
		this->SendMessageToServer(chatInput);
		chatInput.clear();
		return;
	}
	chatInput += key;
	std::cout << key;
	m_chatBox->SetChatInput(chatInput);
}