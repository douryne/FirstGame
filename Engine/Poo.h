#pragma once

#include "Dude.h"
#include "Graphics.h"
#include "Vec2.h"


class Poo
{
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	bool TestCollision(const Dude& dude) const;
	void Draw(Graphics& gfx) const;
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24.0f;
	static constexpr float height = 24.0f;
};