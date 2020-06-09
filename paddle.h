#pragma once

namespace pong
{
	class paddle {

	public:
		int y;

		paddle()
		{
			y = 270;
		}

		void draw(olc::PixelGameEngine* pge)
		{
			olc::vi2d pos{ 0, y };

			pge->FillRect(pos, olc::vi2d{ 10, 80 }, olc::WHITE);
		}

		void move(olc::PixelGameEngine* pge)
		{
			if (pge->GetKey(olc::UP).bPressed || pge->GetKey(olc::UP).bHeld)
			{
				y -= 10;
			}

			if (pge->GetKey(olc::DOWN).bPressed || pge->GetKey(olc::DOWN).bHeld)
			{
				y += 10;
			}

			if (y < 0) y = 0;
			if (y > 520) y = 520;
		}

	};
}