//------------------------------------------------------------------------------
//  A constraint that keeps particles on a circle
//------------------------------------------------------------------------------

#pragma once

#include "Constraint.h"
#include "Particle.h"

class CircularWireConstraint : public Constraint
{
public:
	CircularWireConstraint(Particle *P, const Vec2f &C, const double R)
		: p(P), center(C), radius(R) {}
	virtual void draw();
	
private:
	Particle *const p;
	Vec2f const center;
	double const radius;
};

//------------------------------------------------------------------------------
