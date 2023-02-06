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

		input.RegisterKeyBind(SDLK_RETURN, std::bind(&MultiplayerState::ToggleChatMode, this), "MP");
		input.RegisterAnyKeyBind(std::bind(&MultiplayerState::RecordChatInput, this, std::placeholders::_1), "MP");

		if (serverSocket) m_serverTxt->SetIncomingText("Connected To Server!");
	}
	return true;
}

void MultiplayerState::OnExit(Screen& screen, Input& input)
{
	PlayState::OnExit(screen, input);
	input.UnRegisterKeyBind(SDLK_RETURN, "MP");
	input.UnRegisterAnyKeyBind("MP");
}

GameState* MultiplayerState::Update(Input& input)
{
	if (isNewPlayer)
	{
		auto newPlayer = new MpPlayer();

		SpawnObject(newPlayer);

		newPlayer->SetPosition(700, 200);

		isNewPlayer = false;
	}

	auto playStateUpdate = PlayState::Update(input);
	return playStateUpdate;
}

bool MultiplayerState::Render(Screen& screen)
{
	PlayState::Render(screen);
	if (m_isChatEnabled)
	{
		m_chatBox->Render(screen);
	}
	return true;
}

void MultiplayerState::SentMessage(std::string message)
{
	m_chatBox->AddOutgoingText(chatInput);
}

void MultiplayerState::ReceiveMessage(std::string message)
{
	if (message == "Client Connected!")
	{
		isNewPlayer = true;
	}
	m_chatBox->AddIncomingText("Other player", message);
}

void MultiplayerState::ToggleChatMode()
{
	m_isChatEnabled = !m_isChatEnabled;
	m_player->SetFrozen(m_isChatEnabled);
	if (!m_isChatEnabled)
	{
		if (serverSocket && chatInput.size() > 0) this->SendMessageToServer(chatInput);
		chatInput = "";
	}
}

void MultiplayerState::RecordChatInput(char key)
{
	if (!m_isChatEnabled) return;

	if (key == SDLK_BACKSPACE)
	{
		chatInput.pop_back();
	}
	else if(key == SDLK_RETURN)
	{
		// Do nothing (ignore enter key)
	}
	else 
	{ 
		chatInput += key;
	}
	m_chatBox->SetChatInput(chatInput);
}