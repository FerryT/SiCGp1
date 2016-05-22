//------------------------------------------------------------------------------
//  A constraint that keeps particles on a line segment
//------------------------------------------------------------------------------

#pragma once

#include "Constraint.h"
#include "Particle.h"

class RodConstraint : public Constraint
{
public:
	RodConstraint(Particle *P, Particle *Q, double D)
		: p1(P), p2(Q), dist(D) {}
	virtual void draw();
	
private:
	Particle *const p1;
	Particle *const p2;
	double const dist;
};

//------------------------------------------------------------------------------
