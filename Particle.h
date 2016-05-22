//------------------------------------------------------------------------------
//  Particle definition
//------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <gfx/vec2.h>

#include "Entity.h"

class Particle : public Entity
{
public:
	Particle(const Vec2f &P, float M = 1.0)
		: ini(P), pos(P), vel(Vec2f(0.0, 0.0)), force(), mass(M) {}
	
	virtual void reset();
	virtual void draw();
	
	Vec2f ini, pos, vel;
	Vec2f force;
	float mass;
};

typedef std::vector<Particle *> Particles;

//------------------------------------------------------------------------------
