#include "Platform.h"

Platform::Platform()
{
	isStatic = true;
	m_tag = "platform";
	m_color = { 29, 255, 0, 1 };
	this->SetSize(200, 30);
}

Platform::~Platform()
{
}

void Platform::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
}

void Platform::Update(Input& input)
{
	m_image.Update();
}

void Platform::Render(Screen& screen)
{
	SDL_Rect box;
	box.x = m_position.x;
	box.y = m_position.y;
	box.h = m_size.y;
	box.w = m_size.x;

	SDL_SetRenderDrawColor(screen.GetRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
	SDL_RenderFillRect(screen.GetRenderer(), &box);
}

void Platform::ShutDown()
{
	m_image.Unload();
}