#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

bool MainMenuState::OnEnter(Screen& screen)
{
	m_mainMenuBackground = std::make_unique<MainMenu>();

	m_mainMenuBackground->Initialise(screen);
	m_music.Initialise();

	m_button.push_back(MenuButton("Play", screen));
	m_button.push_back(MenuButton("Controls", screen));
	m_button.push_back(MenuButton("Settings", screen));
	m_button.push_back(MenuButton("Quit", screen));
	m_music.Load("Assets/Audio/MenuBGM.mp3");
	m_music.SetVolume(1);
	m_music.Play();

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
	m_mainMenuBackground->Update(input);
	for (auto& button : m_button)
	{
		button.Update(input);
		auto tag = button.GetTag();
		if (button.GetState() == MenuButton::ButtonState::CLICKED)
		{
			if (tag == "Play")
			{
				return new PlayState;
			}
			if (tag == "Quit")
			{
				return 0;
			}
		}
	}
	return this;
}

bool MainMenuState::Render(Screen& screen)
{
	m_mainMenuBackground->Render(screen);
	for (auto& button : m_button)
	{
		button.Render(screen);
	}
	return true;
}

void MainMenuState::OnExit()
{
	m_music.Shutdown();
	m_mainMenuBackground->ShutDown();
	for (auto& button : m_button)
	{
		button.ShutDown();
	}
}
