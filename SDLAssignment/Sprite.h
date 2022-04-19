#pragma once
#include <string>
#include <SDL.h>
#include "Screen.h"
#include "Vector.h"

class Sprite
{

public:

	enum Flip
	{
		NO_FLIP = SDL_FLIP_NONE,
		HORZ_FLIP = SDL_FLIP_HORIZONTAL,
		VERT_FLIP = SDL_FLIP_VERTICAL
	};
	Sprite();
	~Sprite() {}

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	Vector<int> GetSpriteDimension() const;
	Vector<int> GetImageDimension() const;
	Vector<int> GetSpriteDimension();

	void SetAnimationSpeed(float speed);
	void SetSpriteDimension(int width, int height); // size on screen.
	void SetImageDimension(int columns, int rows, int width, int height); //size in folder.
	void SetImageCell(int column, int row);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, Screen& screen, Flip flip = NO_FLIP);

private:

	int m_imageCell;
	bool m_isAnimated;
	bool m_isAnimatedLooping;
	float m_animationSpeed;

	SDL_Texture* m_image;

	Vector<int> m_cellDimension;
	Vector<int> m_imageDimension;
	Vector<int> m_spriteDimension;
};
