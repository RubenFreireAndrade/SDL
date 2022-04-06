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

	bool Initialize(const std::string& windowTitle = "<No name>");

	void Clear();
	void Present();
	void Shutdown();
	Vector2D GetResolution();

	SDL_Renderer* GetRenderer();
	int width = 1280;
	int height = 720;

private:

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	Vector2D screenDimension;
};
