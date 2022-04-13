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
	m_image.Load("Assets/Images/MountainBackgrundBlue.png", screen);
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 1280, 720);
}

void MainMenu::Update(Input& input)
{
}

void MainMenu::Render(Screen& screen)
{
	m_image.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void MainMenu::ShutDown()
{
	m_image.Unload();
}