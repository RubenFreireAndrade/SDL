#include "EndScreen.h"
//TODO: Make this into a state.
EndScreen::EndScreen()
{

}

EndScreen::~EndScreen()
{

}

void EndScreen::RenderEndScreen(Screen& screen, int state)
{
	font = TTF_OpenFont("Assets/Fonts/impact.ttf", 100);

	color = { 255, 153, 51 };

	const char* message = "";
	if (state == WIN)
	{
		message = "You Win!";
		textBox.w = 300;
		textBox.x = 525;
	}
	else
	{
		message = "You Lost! Restart Game To Try Again!";
		textBox.w = 700;
		textBox.x = 300;
	}

	surface = TTF_RenderText_Solid(font, message, color);

	texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), surface);

	textBox.y = 600 / 2;
	textBox.h = 150;

	SDL_RenderCopy(screen.GetRenderer(), texture, NULL, &textBox);

	TTF_CloseFont(font);
}
