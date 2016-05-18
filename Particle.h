#pragma once

#include <gfx/vec2.h>

class Particle
{
public:
	Particle(const Vec2f &P) : ini(P), pos(P), vel(Vec2f(0.0, 0.0)) {}
	//virtual ~Particle() {} // Why? Seems like we don't use the polymorphism
	
	void reset();
	void draw();
	
	Vec2f ini, pos, vel;
};
