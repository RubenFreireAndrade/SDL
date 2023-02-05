#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

bool MainMenuState::OnEnter(Screen& screen, Input& input)
{
	m_background = std::make_unique<Background>(Background("MountainBackgrundBlue", screen));
	m_music.Initialise();

	m_button.push_back(MenuButton("PlayButton", 1200, 200, screen));
	m_button.push_back(MenuButton("MultiPlayerButton", 1200, 200, screen));
	m_button.push_back(MenuButton("ControlsButton", 1200, 200, screen));
	m_button.push_back(MenuButton("SettingsButton", 1200, 200, screen));
	m_button.push_back(MenuButton("QuitButton", 1200, 200, screen));

	m_music.Load("Assets/Audio/MenuBGM.mp3");
	m_music.SetVolume(2);
	m_music.Play();

	// Making each element in the container spread out by 100px.
	for (auto i = 0; i < m_button.size(); i++)
	{
		auto button = &m_button[i];
		auto newX = button->GetPosition().x;
		auto newY = button->GetPosition().y + 100 * i + screen.GetResolution().y / m_button.size();
		button->SetPosition(newX, newY);
	}
	return true;
}

GameState* MainMenuState::Update(Input& input)
{
	for (auto& button : m_button)
	{
		button.Update(input, *this);
		auto& tag = button.GetTag();
		if (button.GetState() == MenuButton::ButtonState::CLICKED)
		{
			if (tag == "PlayButton")
			{
				return new Level1(nullptr);
			}
			if (tag == "MultiPlayerButton")
			{
				return new MultiplayerMenuState;
			}
			if (tag == "QuitButton")
			{
				return 0;
			}
		}
	}
	return this;
}

bool MainMenuState::Render(Screen& screen)
{
	m_background->Render(screen);
	for (auto& button : m_button)
	{
		button.Render(screen);
	}
	return true;
}

void MainMenuState::OnExit(Screen& screen, Input& input)
{
	m_background->ShutDown();
	for (auto& button : m_button)
	{
		button.ShutDown();
	}
}
