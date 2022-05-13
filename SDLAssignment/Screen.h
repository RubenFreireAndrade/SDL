#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_ttf.h>
#include "Vector2D.h"
#include "Parser.h"

class Screen
{
public:

	Screen();

	bool Initialize(const std::string& fileName);

	void Clear();
	void Present();
	void Shutdown();
	Vector2D GetResolution();
	SDL_Renderer* GetRenderer();

private:

	int width = 1280;
	int height = 720;
	Parser m_parser;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	Vector2D screenDimension;
};
