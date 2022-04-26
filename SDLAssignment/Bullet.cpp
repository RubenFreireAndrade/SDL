#include "Bullet.h"

Bullet::Bullet(Vector2D spawnPos, Vector2D bulletDir)
{
	m_color = { 255, 0, 0, 1 };
	m_position = spawnPos;
	m_direction = bulletDir;
	m_velocity = m_direction.Scale(speed);
	m_size = { 30, 10 };
	isStatic = true;
}

Bullet::~Bullet()
{

}

void Bullet::Update(Input& input)
{
	m_position = m_position.Add(m_velocity);
	if (m_position.x < 0 || m_position.x > 1400)
	{
		this->FlagForDeletion();
	}
}

void Bullet::Render(Screen& screen)
{
	SDL_Rect box;
	box.x = m_position.x;
	box.y = m_position.y;
	box.h = m_size.y;
	box.w = m_size.x;

	SDL_SetRenderDrawColor(screen.GetRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
	SDL_RenderFillRect(screen.GetRenderer(), &box);
}

void Bullet::CheckCollision(std::list<GameObject*> objects)
{
	for (GameObject* obj : objects)
	{
		if (obj->GetTag() == "enemy")
		{
			if (this->IsCollidingWith(obj))
			{
				((Enemy*)obj)->EnemyHit();
			}
		}
	}
}

