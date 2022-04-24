#include "EndScreenState.h"
#include <iostream>

EndScreenState::EndScreenState(ConditionState c)
{
    m_enumState = c;
    conditionState = static_cast<int>(m_enumState);
}

EndScreenState::~EndScreenState()
{
}

bool EndScreenState::OnEnter(Screen& screen)
{
    m_endScreen = std::make_unique<EndScreen>();
    m_endScreen->Initialise(screen);
    return true;
}

GameState* EndScreenState::Update(Input& input)
{
    input.Update();
    // Quiting Game
    if (input.IsKeyDown(SDLK_ESCAPE))
    {
        return 0;
    }
    return this;
}

bool EndScreenState::Render(Screen& screen)
{
    m_endScreen->Render(screen, conditionState);
    return true;
}

void EndScreenState::OnExit()
{
    m_endScreen->ShutDown();
}