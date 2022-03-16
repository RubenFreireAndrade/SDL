#include "WriteToScreen.h"
#include <SDL_ttf.h>
#include "Screen.h"

Screen screen;

WriteToScreen::WriteToScreen(/*Player* p*/)
{
	//player = p;
	font = TTF_OpenFont("Assets/Fonts/impact.ttf", 50);
	color = { 255, 255, 255 };
}

WriteToScreen::~WriteToScreen()
{
	
}

bool WriteToScreen::Initialise()
{
	if (TTF_Init() == -1) return false;
	return true;
}

void WriteToScreen::Unload()
{
	TTF_CloseFont(font);
}

void WriteToScreen::RenderScore(Screen& screen)
{
	int score = player.GetScore(); // Get score from player.
	std::string scoreString = std::to_string(score);		// converting score to string
	std::string scorePrint = "Score: " + scoreString;		// Score: is a prefix before the variable score

	surface = TTF_RenderText_Solid(font, scorePrint.c_str(), color);
	texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), surface);

	textBox.x = 0;
	textBox.y = 0;
	textBox.w = 120;
	textBox.h = 50;
	SDL_RenderCopy(screen.GetRenderer(), texture, NULL, &textBox);
}