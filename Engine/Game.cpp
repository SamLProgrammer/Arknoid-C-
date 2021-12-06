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
#include "Vec2DF.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	frameTimer(),
	ball(Vec2DF(200.0f, 20.0f), Vec2DF(1.0f, 1.0f)),
	paddle(Vec2DF(350.0f, 550.0f), Vec2DF(10.0f, 0.0f)),
	initializer(),
	interceptor()
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float delta_time = frameTimer.mark() * 60;
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		paddle.move(delta_time, true);
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		paddle.move(delta_time, false);
	}

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		ball.fast();
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		ball.slow();
	}

	ball.move(delta_time);
	initializer.check_collisions(ball);
	interceptor.ball_wall_collision(ball, 0, Graphics::ScreenHeight, Graphics::ScreenWidth, 0);
	interceptor.ball_paddle_collision(ball, paddle);

}

void Game::ComposeFrame()
{
	initializer.drawBricks(gfx);
	ball.draw(gfx);
	paddle.draw(gfx);
}
