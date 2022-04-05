#include "Player.h"
#include "Input.h"
#include "Coin.h"

Player::Player()
{
	m_tag = "player";
	score = 0;

	m_position.x = 20;
	m_position.y = 480;
	isStatic = false;

	this->SetSize(120, 145);
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
		m_image[i].SetSpriteDimension(150,150);
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
		Vector2D offSet;
		Vector2D direction;
		if (m_spriteDirection == Player::Direction::RIGHT)
		{
			offSet = Vector2D(140, 60);
			direction = Vector2D(1, 0);
		}
		else
		{
			offSet = Vector2D(-30, 60);
			direction = Vector2D(-1, 0);
		}
		Vector2D spawnPos = m_position.Add(offSet);
		Bullet* bullet = new Bullet(spawnPos, direction);
		m_gameObjects->push_back(bullet);
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
		m_image[m_state].Render(m_position.x, m_position.y, screen, Sprite::HORZ_FLIP);
	}
	else
	{
		m_image[m_state].Render(m_position.x, m_position.y, screen, Sprite::NO_FLIP);
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