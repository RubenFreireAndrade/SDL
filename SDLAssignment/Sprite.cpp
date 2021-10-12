#include <iostream>
#include "Sprite.h"
#include <SDL_image.h>

Sprite::Sprite()
{
	m_image = nullptr;

	m_isAnimated = false;
	m_isAnimatedLooping = false;

	m_spriteDimension = {0, 0};
	m_cellDimension = {0, 0};
	m_imageDimension = {0, 0};
}

void Sprite::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}

void Sprite::IsAnimationLooping(bool flag)
{
	m_isAnimatedLooping = flag;
}

void Sprite::SetAnimationSpeed(float speed)
{
	m_animationSpeed = speed;
}

void Sprite::SetSpriteDimension(int width, int height)
{
	m_spriteDimension.x = width;
	m_spriteDimension.y = height;
}

void Sprite::SetImageDimension(int columns, int rows, int width, int height)
{
	m_imageDimension.x = columns;
	m_imageDimension.y = rows;

	m_cellDimension.x = width / columns;
	m_cellDimension.y = height / rows;
}

void Sprite::SetImageCell(int column, int row)
{
	m_imageCell = ((row - 1) * m_imageDimension.x) + (column - 1);
}

bool Sprite::Load(const std::string& filename, Screen& screen)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());
	if (!rawImageData)
	{
		std::cout << "Error loading image file." << std::endl;
		return false;
	}
	m_image = SDL_CreateTextureFromSurface(screen.GetRenderer(), rawImageData);
	return true;
}

void Sprite::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Sprite::Update()
{
	if (m_isAnimated)
	{
		static float total = 0.0f;
		total += m_animationSpeed;

		m_imageCell = static_cast<int> (total * m_animationSpeed) % (m_imageDimension.x * m_imageDimension.y);
	}
}

void Sprite::Render(int xPos, int yPos, Screen& screen, Flip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	sourceRect.x = (m_imageCell % m_imageDimension.x) * m_cellDimension.x;
	sourceRect.y = (m_imageCell / m_imageDimension.x) * m_cellDimension.y;
	sourceRect.w = m_cellDimension.x;
	sourceRect.h = m_cellDimension.y;

	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = m_spriteDimension.x;
	targetRect.h = m_spriteDimension.y;

	SDL_Point centre{ m_spriteDimension.x * 0.5f, m_spriteDimension.y * 0.5f };
	SDL_RenderCopyEx(screen.GetRenderer(), m_image, &sourceRect, &targetRect, 0.0, &centre, static_cast<SDL_RendererFlip>(flip));
}