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
#include "Vector2.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	sprite(32, 32, IntRect(0, Graphics::ScreenWidth, Graphics::ScreenHeight, 0), "img.bmp", 0.1f),
	animationTime(0),
	grid({0,0}, 32),
	grassSprite(32, 32, IntRect(0, Graphics::ScreenWidth, Graphics::ScreenHeight, 0), "grass.bmp", 0.3f)
{
	sprite.SetState(3);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			IntVector2 pos = grid.FitToGrid({ i * 32, j * 32 });
			grassTiles.push_back({ pos, 32, grassSprite });
		}
	}
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
	if (wnd.kbd.KeyIsPressed('A'))
	{
		sprite.SetFrameTime(0.1f);
		sprite.SetState(0);
		pos.x -= 2;
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		sprite.SetFrameTime(0.1f);
		sprite.SetState(1);
		pos.x += 2;
	}
	else if (wnd.kbd.KeyIsPressed('W')) 
	{
		sprite.SetFrameTime(0.1f);
		sprite.SetState(2);
		pos.y -= 2;
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		sprite.SetFrameTime(0.1f);
		sprite.SetState(3);
		pos.y += 2;
	}
	else
	{
		sprite.SetFrame(0);
		sprite.SetFrameTime(100000000000.f);
	}

	time.Mark();
	sprite.AdvanceFrame(time.DeltaTime());
}

void Game::ComposeFrame()
{
	for (auto i = grassTiles.begin(); i < grassTiles.end(); i++)
	{
		auto pos = i->GetScenePos();
		i->Draw(pos.x, pos.y, gfx, Colors::Magenta);
	}
	sprite.Draw(pos.x, pos.y, gfx, Colors::Magenta);
}
