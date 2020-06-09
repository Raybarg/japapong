#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "paddle.h"
#include "ball.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "japa pong";
	}

public:
	pong::ball* ball;
	pong::paddle* paddle;
	olc::Pixel c = olc::BLACK;

public:
	bool OnUserCreate() override
	{
		ball = new pong::ball(olc::vi2d{ 400, 300 });
		paddle = new pong::paddle();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		FillRect(olc::vi2d{ 0,0 }, olc::vi2d{ 800,600 }, c);

		if (!ball->move(fElapsedTime, paddle))
		{
			// Game over
			c = olc::RED;
		}
		paddle->move(this);

		ball->draw(this);
		paddle->draw(this);

		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(800, 600, 1, 1))
		demo.Start();
	return 0;
}

