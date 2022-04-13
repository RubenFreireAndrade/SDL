#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	buttonPos.x = 0;
	buttonPos.y = 0;
}

MainMenuState::~MainMenuState()
{
}

bool MainMenuState::OnEnter(Screen& screen)
{
	m_mainMenuBackground = std::make_unique<MainMenu>();

	m_button.push_back(MenuButton("Play", screen));
	m_button.push_back(MenuButton("Controls", screen));
	m_button.push_back(MenuButton("Settings", screen));
	m_button.push_back(MenuButton("Quit", screen));

	m_mainMenuBackground->Initialise(screen);
	//m_button[0].Initialise(screen);
	/*for (auto& button : m_button)
	{
		button.SetPosition(buttonPos);
		buttonPos.y += 100;
	}*/
	return true;
}

GameState* MainMenuState::Update(Input& input)
{
	input.Update();
	m_mainMenuBackground->Update(input);
	//m_button[0].Update(input);
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
			if (tag == "Exit")
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
		/*button.SetPosition(buttonPos);
		buttonPos.y += 100;*/
		//auto tag = button.GetTag();
		button.Render(screen);
		//m_button[0].Render(screen);
	}
	return true;
}

void MainMenuState::OnExit()
{
	m_mainMenuBackground->ShutDown();
	m_button[0].ShutDown();
}