#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

bool MainMenuState::OnEnter(Screen& screen)
{
	m_background = std::make_unique<Background>(Background("MountainBackgrundBlue", screen));
	m_music.Initialise();

	m_button.push_back(MenuButton("PlayButton", screen));
	m_button.push_back(MenuButton("ControlsButton", screen));
	m_button.push_back(MenuButton("SettingsButton", screen));
	m_button.push_back(MenuButton("QuitButton", screen));
	m_music.Load("Assets/Audio/MenuBGM.mp3");
	m_music.SetVolume(1);
	m_music.Play();
	// Making each element in the container spread out by 100px.
	for (auto i = 0; i < m_button.size(); i++)
	{
		auto button = &m_button[i];
		auto newX = button->GetPosition().x;
		auto newY = button->GetPosition().y + 100 * i + screen.GetResolution().y / 3;
		button->SetPosition(newX , newY);
	}
	return true;
}

GameState* MainMenuState::Update(Input& input)
{
	input.Update();
	for (auto& button : m_button)
	{
		button.Update(input);
		auto tag = button.GetTag();
		if (button.GetState() == MenuButton::ButtonState::CLICKED)
		{
			if (tag == "PlayButton")
			{
				return new PlayState;
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

void MainMenuState::OnExit()
{
	m_music.Shutdown();
	m_background->ShutDown();
	for (auto& button : m_button)
	{
		button.ShutDown();
	}
}
