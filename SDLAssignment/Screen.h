#pragma once

#include<iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Vector2D.h"

class Screen
{

public:

	Screen();

	bool Initialize(const std::string& windowTitle, int width, int height);

	void Clear();
	void Present();
	void Shutdown();
	int GetResolution();

	SDL_Renderer* GetRenderer();
	int m_width;
	int m_height;

private:

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	//Vector2D m_size;
};
