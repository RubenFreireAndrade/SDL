#include "MainMenu.h"
//TODO: Make this into a state.
MainMenu::MainMenu()
{
	this->SetSize(1280, 720);
	isStatic = true;
}

MainMenu::~MainMenu()
{
	m_image.Unload();
}

void MainMenu::Initialise(Screen& screen)
{
	m_image.Load("Assets/Images/MainMenu.png", screen);
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 1280, 720);
}

void MainMenu::Update(Input& input)
{
	
}

void MainMenu::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, screen);
}
