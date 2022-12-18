#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal(Vec2& pos_in)
		:
		pos(pos_in)
	{}
	void Draw(Graphics& gfx) const
	{
		gfx.DrawRectDim(int(pos.x), int(pos.y), int(dimension), int(dimension), c);
	}
	bool TestCollision(const Dude& dude) const
	{
		float dudeRight = dude.GetPos().x + dude.GetWidth();
		float dudeBottom = dude.GetPos().y + dude.GetHeight();
		float pooRight = pos.x + dimension;
		float pooBottom = pos.y + dimension;

		return
			dudeRight >= pos.x &&
			dude.GetPos().x<= pooRight &&
			dudeBottom >= pos.y &&
			dude.GetPos().y <= pooBottom;
	}
	void Respawn(const Vec2& pos_in)
	{
		pos = pos_in;
	}
private:
	static constexpr float dimension = 20;
	static constexpr Color c = Colors::Red;
	Vec2 pos;
};