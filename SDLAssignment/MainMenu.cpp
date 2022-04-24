#include "MainMenu.h"

MainMenu::MainMenu()
{
	isStatic = true;
}

MainMenu::~MainMenu()
{
}

void MainMenu::Initialise(Screen& screen)
{
	m_sprite.Load("Assets/Images/MountainBackgrundBlue.png", screen);
	m_sprite.SetSpriteDimension(1280, 720);
	m_sprite.SetImageDimension(1, 1, 1280, 720);
}

void MainMenu::Update(Input& input)
{
}

void MainMenu::Render(Screen& screen)
{
	m_sprite.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void MainMenu::ShutDown()
{
	m_sprite.Unload();
}