//------------------------------------------------------------------------------
//  A force that acts constantly uniformely in a single direction
//------------------------------------------------------------------------------

#pragma once

#include "Force.h"
#include "Particle.h"

//------------------------------------------------------------------------------

class GravityForce : public Force
{
public:
	GravityForce(const Vec2f &origin, const Vec2f &velocity)
		: force(origin) { force.vel = velocity; }
	virtual void draw();
	
private:
	Particle force;
};

//------------------------------------------------------------------------------
