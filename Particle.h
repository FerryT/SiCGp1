//------------------------------------------------------------------------------
//  Particle definition
//------------------------------------------------------------------------------

#pragma once

#include <gfx/vec2.h>

#include "Entity.h"

class Particle : public Entity
{
public:
	Particle(const Vec2f &P) : ini(P), pos(P), vel(Vec2f(0.0, 0.0)) {}
	
	virtual void reset();
	virtual void draw();
	
	Vec2f ini, pos, vel;
};

//------------------------------------------------------------------------------
