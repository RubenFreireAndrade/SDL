#include <iostream>
#include "Screen.h"

Screen::Screen()
{
	m_window = nullptr;
	m_renderer = nullptr;
}

bool Screen::Initialize(const std::string& fileName)
{
	std::map<std::string, std::string> dataMap;
	if (!m_parser.LoadConfigFile(fileName, dataMap))
	{
		std::cout << "Config.ini was not loaded properly" << std::endl;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		return false;
	}
	auto screenFlag = std::stoi(dataMap["Fullscreen"]) | SDL_WINDOW_RESIZABLE;

	m_window = SDL_CreateWindow(dataMap["Name"].c_str(),
		SDL_WINDOWPOS_CENTERED,    //pos x
		SDL_WINDOWPOS_CENTERED,    //pos y
		std::stoi(dataMap["Width"]), 
		std::stoi(dataMap["Height"]),
		screenFlag);

	if (!m_window)
	{
		std::cout << "Error creating game window." << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}
	return true;
}

void Screen::Clear()
{
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Vector2D Screen::GetResolution()
{
	SDL_GetWindowSize(m_window, &screenDimension.x, &screenDimension.y);
	return screenDimension;
}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}