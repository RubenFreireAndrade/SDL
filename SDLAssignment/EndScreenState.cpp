#include "EndScreenState.h"

EndScreenState::EndScreenState(ConditionState c)
{
    m_enumState = c;
	conditionState = static_cast<int>(m_enumState);
}

EndScreenState::~EndScreenState()
{
}

bool EndScreenState::OnEnter(Screen& screen, Input& input)
{
	m_background = std::make_unique<Background>(Background("MountainBackgrundBlue", screen));

	m_textToScreen.Load("Assets/Fonts/impact.ttf", 300);
	m_textToScreen.SetColor(0, 168, 255, 255);
    m_endScreen->Initialise(screen);

	m_button.push_back(MenuButton("QuitButton", screen ));
	// Making each element in the container spread out by 100px.
	for (auto i = 0; i < m_button.size(); i++)
	{
		auto button = &m_button[i];
		auto newX = button->GetPosition().x;
		auto newY = button->GetPosition().y + 100 * i + screen.GetResolution().y / 2;
		button->SetPosition(newX, newY);
	}
    return true;
}

GameState* EndScreenState::Update(Input& input)
{
	for (auto& button : m_button)
	{
		button.Update(input);
		auto tag = button.GetTag();
		if (button.GetState() == MenuButton::ButtonState::CLICKED)
		{
			if (tag == "QuitButton")
			{
				return new MainMenuState;
			}
		}
	}
    // Quiting Game
    if (input.IsKeyDown(SDLK_ESCAPE))
    {
        return 0;
    }
    return this;
}

bool EndScreenState::Render(Screen& screen)
{
	if (m_enumState == ConditionState::WIN)
	{
		const char* message = "";
		message = "You Win!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(300, 150);
	}
	else if (m_enumState == ConditionState::LOSS)
	{
		const char* message = "";
		message = "You Lost! Restart Game To Try Again!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(700, 150);
	}
	m_background->Render(screen);
	m_textToScreen.Render((screen.GetResolution().x / 2) - m_textToScreen.GetDimension().x / 2, screen.GetResolution().y / 3 - m_textToScreen.GetDimension().y / 3, screen);
	for (auto& button : m_button)
	{
		button.Render(screen);
	}
    return true;
}

void EndScreenState::OnExit()
{
	m_textToScreen.ShutDown();
	m_background->ShutDown();
	for (auto button : m_button)
	{
		button.ShutDown();
	}
}