#include "Bullet.h"

Bullet::Bullet(Vector2D spawnPos, Vector2D bulletDir, Screen& screen)
{
	m_bulletSprite.Load("Assets/Images/RedLaser.png", screen);
	m_bulletSprite.SetImageDimension(1, 1, 251, 144);
	m_bulletSprite.SetSpriteDimension(70, 70);

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
	m_bulletSprite.Render(this->m_position.x, this->m_position.y, screen);
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

