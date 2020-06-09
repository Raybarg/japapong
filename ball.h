#pragma once
#include "olcPixelGameEngine.h"
#include "paddle.h"

namespace pong
{
	class ball
	{
	public:
		olc::vi2d pos;
		olc::vi2d dir;
		float speed;

		ball(olc::vi2d startpos)
		{
			pos = startpos;
			dir = olc::vi2d{ 5, 5 };
			speed = 200;
		}

		void draw(olc::PixelGameEngine* pge)
		{
			pge->FillCircle(pos, 10, olc::WHITE);
		}

		bool move(float fElapsedTime, pong::paddle *paddle)
		{
			// Screen boundaries check
			if (pos.x >= 790) dir.x *= -1;
			if (pos.y >= 590) dir.y *= -1;
			if (pos.y <= 0) dir.y *= -1;

			// Paddle check
			if (pos.x > 2 && pos.x <= 15 && pos.y >= paddle->y && pos.y <= (paddle->y + 80)) {
				dir.x *= -1;
				pos.x = 21;
			}

			// "Game over" check
			if (pos.x < 0) return false;

			pos += dir;
			return true;
		}
	};
}