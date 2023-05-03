/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

double birdVelo = 0;
double birdPos = 300;
double Accel = 0.02;
double t = 0;
double ObstPos = 779;
double ObstH = 300;
bool dead = true;

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
		dead = false;
	if (!dead) {
		wnd.kbd.DisableAutorepeat();
		t++;
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {							// keyboard input 
			if (birdVelo > 0) {
				birdVelo = -0.13;
				t = 0;
			}
		}
		birdVelo += Accel * t * 0.00001;								// calculate velocity
		birdPos += birdVelo;
		if (birdPos >= 600 || birdPos <= 10) {							// if death
			dead = true;												// reset all variables
			birdPos = 300;
			birdVelo = 0;
			ObstPos = 779;
		}
		ObstPos -= 0.15;												// move obstacle across screen
		if (ObstPos < 10) {												// generate new height for obstacle
			ObstH = rand() % 450+150;
			ObstPos = 779;
		}
		if (birdPos > ObstH && ObstPos > 290 && ObstPos < 321) {		// obstacle collision (bottom)
			dead = true;
			birdPos = 300;
			birdVelo = 0;
			ObstPos = 779;
		}
		if (birdPos < ObstH - 100 && ObstPos > 290 && ObstPos < 321) {	// obstacle collision (bottom)
			dead = true;
			birdPos = 300;
			birdVelo = 0;
			ObstPos = 779;
		}
	}
}

void Game::ComposeFrame()
{
	for (int i = 290; i < 321; i++) {									// draw bird on screen (box)
		gfx.PutPixel(i, birdPos-10, 255, 255, 255);
		gfx.PutPixel(i, birdPos, 255, 255, 255);
	}
	for (int i = birdPos; i > birdPos - 10; i--) {
		gfx.PutPixel(290, i, 255, 255, 255);
		gfx.PutPixel(320, i, 255, 255, 255);
	}
	for (int i = 599; i > ObstH; i--) {									// draw bottom part of obstacle
		gfx.PutPixel(ObstPos, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+1, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+2, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+3, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+4, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+5, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+6, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+7, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+8, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+9, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+10, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+11, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+12, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+13, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+14, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+15, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+16, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+17, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+18, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+19, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+20, i, 255, 255, 255);
	}
	for (int i = 0; i < ObstH - 100; i++) {
		gfx.PutPixel(ObstPos, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+1, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+2, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+3, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+4, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+5, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+6, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+7, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+8, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+9, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+10, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+11, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+12, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+13, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+14, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+15, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+16, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+17, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+18, i, 255, 255, 255);
		gfx.PutPixel(ObstPos+19, i, 255, 255, 255);
	}
}
