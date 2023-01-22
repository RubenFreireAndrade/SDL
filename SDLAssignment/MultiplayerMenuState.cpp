#include "MultiplayerMenuState.h"
#include "MultiplayerLevel1.h"

bool MultiplayerMenuState::OnEnter(Screen& screen, Input& input)
{
    m_background = std::make_unique<Background>(Background("Moon", screen));

    m_btnText.push_back(MenuButtonText("HOST GAME"));
    m_btnText.push_back(MenuButtonText("JOIN GAME"));
    // Making each element in the container spread out by 100px.
    for (auto i = 0; i < m_btnText.size(); i++)
    {
        auto btnText = &m_btnText[i];
        auto newX = btnText->GetPosition().x;
        auto newY = btnText->GetPosition().y + 100 * i + screen.GetResolution().y / m_btnText.size();
        btnText->SetPosition(newX, newY);
    }
    return true;
}

GameState* MultiplayerMenuState::Update(Input& input)
{
    for (auto& btnText : m_btnText)
    {
        btnText.Update(input);
        auto& tag = btnText.GetTag();
        if (btnText.GetState() == MenuButtonText::ButtonState::CLICKED)
        {
            if (tag == "JOIN GAME")
            {
                return new MultiplayerLevel1(new Player(true), "CLIENT");
            }

            // TODO - Add BACK button when have time
            /*if (tag == "QuitButton")
            {
                return 0;
            }*/
        }
    }
    // TODO - change this when proper buttons are implemented.
    if (input.IsKeyDown(SDLK_ESCAPE))
    {
        return 0;
    }
    return this;
}

bool MultiplayerMenuState::Render(Screen& screen)
{
    m_background->Render(screen);
    for (auto& btnText : m_btnText)
    {
        btnText.Render(screen);
    }
    return true;
}

void MultiplayerMenuState::OnExit()
{
    m_background->ShutDown();
    for (auto& btnText : m_btnText)
    {
        btnText.ShutDown();
    }
}

