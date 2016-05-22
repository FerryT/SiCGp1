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
	GravityForce(const Vec2f &origin, const Vec2f &force, const Particles *);
	virtual void draw();
	virtual void act();
	
private:
	Vec2f origin, force, position, arrow;
	const Particles *particles;
};

//------------------------------------------------------------------------------
