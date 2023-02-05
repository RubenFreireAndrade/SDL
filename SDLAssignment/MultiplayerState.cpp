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
		m_chatBox = new ChatBox("ChatBox", screen);
		m_serverTxt = new ServerText("Attempting To Find Server", screen);

		this->objects.push_back(m_serverTxt);

		m_chatBox->Initialise(screen);
		m_serverTxt->Initialise(screen);

		this->SDLNetInitialize();
		this->ConnectToServer();

		input.RegisterKeyBind(SDLK_RETURN, std::bind(&MultiplayerState::ToggleChatMode, this));
		input.RegisterAnyKeyBind(std::bind(&MultiplayerState::RecordChatInput, this, std::placeholders::_1));
	}
	return true;
}

GameState* MultiplayerState::Update(Input& input)
{
	PlayState::Update(input);
	return this;
}

bool MultiplayerState::Render(Screen& screen)
{
	PlayState::Render(screen);
	if (m_player->isChatting)
	{
		m_chatBox->Render(screen);
	}
	return true;
}

void MultiplayerState::SentMessage(std::string message)
{
	std::cout << "You Sent: " << message << std::endl;
}

void MultiplayerState::ReceiveMessage(std::string message)
{
	std::cout << this->GetIp(serverSocket) << " Sent: " << message << std::endl;
	//m_chatBox->SetIncomingText(message);
	m_serverTxt->SetIncomingText(message);
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
		// TODO - fix to not break whenever user presses Enter twice.
		if(serverSocket) this->SendMessageToServer(chatInput);
		chatInput.clear();
		return;
	}
	chatInput += key;
	std::cout << key;
	m_chatBox->SetChatInput(chatInput);
}