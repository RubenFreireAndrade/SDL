#include "EndScreenState.h"
#include <iostream>

EndScreenState::EndScreenState(ConditionState c)
{
    m_enumState = c;
    conditionState = static_cast<int>(m_enumState);
}

EndScreenState::~EndScreenState()
{
    m_endScreen.Unload();
}

bool EndScreenState::OnEnter(Screen& screen)
{
    return true;
}

GameState* EndScreenState::Update(Input& input)
{
    //input.Update();
    // Quiting Game
    if (input.IsKeyDown(SDLK_ESCAPE))
    {
        return 0;
    }
    return this;
}

bool EndScreenState::Render(Screen& screen)
{
    m_endScreen.RenderEndScreen(screen, conditionState);
    return true;
}

void EndScreenState::OnExit()
{
    m_endScreen.Unload();
}