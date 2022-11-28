#include "MultiplayerState.h"

bool MultiplayerState::OnEnter(Screen& screen)
{
    m_multiplayer.SDLNetInitialize();
    return true;
}

GameState* MultiplayerState::Update(Input& input)
{
    input.Update();
    return this;
}

bool MultiplayerState::Render(Screen& screen)
{
    return false;
}

void MultiplayerState::OnExit()
{
    m_multiplayer.ShutDown();
}

