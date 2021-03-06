#include "Player.h"
#include "Coin.h"

Player::Player()
{
	score = 0;
	isStatic = false;
	this->SetTag("player");
	this->SetSize(50, 110);
	this->m_position.x = 20;
	this->m_position.y = 500;
}

Player::~Player()
{
	m_image[IDLE].Unload();
}

void Player::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
	m_state = IDLE;
	m_spriteDirection = Player::Direction::RIGHT;

	m_image[IDLE].Load("Assets/Images/HeroIdleAnimation.png", screen);
	m_image[RUN].Load("Assets/Images/HeroRunAnimation.png", screen);
	m_image[SHOOT].Load("Assets/Images/HeroShootAnimation.png", screen);
	m_image[JUMP].Load("Assets/Images/HeroJumpAnimation.png", screen);
	m_image[DEAD].Load("Assets/Images/HeroDeadAnimation.png", screen);
	
	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_image[i].SetSpriteDimension(120, 120);
		m_image[i].SetImageDimension(10, 1, 5670, 556);
		m_image[i].SetAnimationSpeed(0.3f);
		m_image[i].IsAnimated(true);
		if (i == JUMP || i == DEAD)
		{
			m_image[i].IsAnimationLooping(false);
		}
		else
		{
			m_image[i].IsAnimationLooping(true);
		}

		if (i == RUN)
		{
			m_image[i].SetImageDimension(8, 1, 4536, 556);
		}

		if (i == DEAD)
		{
			m_image[i].SetImageDimension(10, 1, 5620, 519);
		}

		if (i == SHOOT)
		{
			m_image[i].SetImageDimension(4, 1, 2268, 556);
		}
	}
}

void Player::Update(Input& input)
{
	if (input.IsKeyDown(SDLK_a))
	{
		m_velocity.x -= speed;
		m_state = RUN;
		m_spriteDirection = Player::Direction::LEFT;
	}

	if (input.IsKeyDown(SDLK_d))
	{
		m_velocity.x += speed;
		m_state = RUN;
		m_spriteDirection = Player::Direction::RIGHT;
	}

	if (input.IsKeyDown(SDLK_w) && isGrounded && !isJumping)
	{
		m_state = JUMP;
		m_velocity.y -= jumpHeight;
		isJumping = true;
		isGrounded = false;
		isBlocked = false;
	}

	if (input.IsMouseClicked() && !m_shooting)
	{
		m_state = SHOOT;
		m_shooting = true;
	}

	if (!input.IsMouseClicked())
	{
		m_shooting = false;
	}

	if (!input.IsKeyPressed())
	{
		m_state = IDLE;
	}

	if (m_velocity.y > 0)
	{
		isJumping = false;
	}
	m_image[m_state].Update();
}

void Player::Render(Screen& screen)
{
	if (m_spriteDirection != Player::Direction::RIGHT)
	{
		m_image[m_state].Render(m_position.x, m_position.y, screen, Sprite::Flip::HORZ_FLIP);
	}
	else
	{
		m_image[m_state].Render(m_position.x, m_position.y, screen, Sprite::Flip::NO_FLIP);
	}

	if (m_shooting == true)
	{
		Bullet* bullet;
		Vector2D offSet;
		Vector2D direction;
		if (m_spriteDirection == Player::Direction::RIGHT)
		{
			offSet = Vector2D(90, 40);
			direction = Vector2D(1, 0);
		}
		if (m_spriteDirection == Player::Direction::LEFT)
		{
			offSet = Vector2D(-30, 40);
			direction = Vector2D(-1, 0);
		}
		Vector2D spawnPos = m_position.Add(offSet);
		bullet = new Bullet(spawnPos, direction, screen);
		m_gameObjects->push_back(bullet);
	}
}

void Player::CheckCollision(std::list<GameObject*> objects)
{
	isBlocked = false;
	for (GameObject* obj : objects)
	{
		if (obj->GetTag() == "pickup")
		{
			if (this->IsCollidingWith(obj))
			{
				((Coin*)obj)->Pickup(this);
			}
		}

		if (obj->GetTag() == "platform")
		{
			if (this->IsCollidingWith(obj))
			{
				isBlocked = true;
				m_position.y -= m_velocity.y;
			}
		}

		if (obj->GetTag() == "enemy")
		{
			if (this->IsCollidingWith(obj))
			{
				this->FlagForDeletion();
			}
		}

		if (obj->GetTag() == "rocket")
		{
			if (this->IsCollidingWith(obj))
			{
				if (this->GetScore() == maxCoinPoints)
				{
					AddScore(1);
				}
			}
		}
	}
}

void Player::AddScore(int amount)
{
	score += amount;
}

int Player::GetScore()
{
	return score;
}

void Player::SetState(State state)
{
	m_state = state;
}