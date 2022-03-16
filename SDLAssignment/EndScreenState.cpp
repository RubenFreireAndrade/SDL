#include "EndScreenState.h"
#include <iostream>

EndScreenState::EndScreenState(ConditionState c)
{
    m_enumState = c;
    conditionState = static_cast<int>(m_enumState);
}

bool EndScreenState::OnEnter(Screen& screen)
{
    return true;
}

GameState* EndScreenState::Update(Input& input)
{
    input.Update();
    return this;
}

bool EndScreenState::Render(Screen& screen)
{
    m_endScreen.RenderEndScreen(screen, conditionState);
    std::cout << "end screen is rendered" << std::endl;
    return true;
}

void EndScreenState::OnExit()
{
    m_endScreen.Unload();
}