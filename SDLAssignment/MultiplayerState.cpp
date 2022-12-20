#include "MultiplayerState.h"

bool MultiplayerState::OnEnter(Screen& screen)
{
    m_host = new Host();
    m_host->SDLNetInitialize();
    m_host->OpenSocket();
    //m_join->SDLNetInitialize();
    //m_join->OpenSocket();

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

GameState* MultiplayerState::Update(Input& input)
{
    input.Update();
    for (auto& btnText : m_btnText)
    {
        btnText.Update(input);
        auto& tag = btnText.GetTag();
        if (btnText.GetState() == MenuButtonText::ButtonState::CLICKED)
        {
            if (tag == "HOST GAME")
            {
                int clientId = m_host->ListenSocket();
                std::thread receiveMsgThr(&Host::ReceiveMessage, m_host, clientId);
                receiveMsgThr.detach();
                return new PlayState;
            }
            if (tag == "JOIN GAME")
            {
                return new PlayState;
            }
            // TODO - Add BACK button when have time
            /*if (tag == "QuitButton")
            {
                return 0;
            }*/
        }
    }
    // change this when proper buttons are implemented.
    if (input.IsKeyDown(SDLK_ESCAPE))
    {
        return 0;
    }
    return this;
}

bool MultiplayerState::Render(Screen& screen)
{
    m_background->Render(screen);
    for (auto& btnText : m_btnText)
    {
        btnText.Render(screen);
    }
    return true;
}

void MultiplayerState::OnExit()
{
    m_background->ShutDown();
    for (auto& btnText : m_btnText)
    {
        btnText.ShutDown();
    }
    //m_host.ShutDown();
    //m_join.ShutDown();
}

