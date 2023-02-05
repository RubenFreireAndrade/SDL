#include "Platform.h"

Platform::Platform()
{
	isStatic = true;
	this->SetTag("platform");
	this->SetSize(64, 64);
}

Platform::~Platform()
{
}

void Platform::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
	m_image.Load("Assets/Images/PlatformGreen.png", screen);
	m_image.SetSpriteDimension(64, 64);
	m_image.SetImageDimension(1, 1, 64, 64);
}

void Platform::Update(Input& input, GameState& state)
{
}

void Platform::Render(Screen& screen)
{
	m_image.Render((m_image.GetSpriteDimension().x / 2 - m_image.GetImageDimension().x / 2) + this->m_position.x, this->m_position.y, screen, Sprite::Flip::NO_FLIP);
}

void Platform::ShutDown()
{
	m_image.Unload();
}