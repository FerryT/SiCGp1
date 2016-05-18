#pragma once

#include "Particle.h"

class CircularWireConstraint
{
public:
	CircularWireConstraint(Particle *P, const Vec2f &C, const double R)
		: p(P), center(C), radius(R) {}
	void draw();
	
private:
	Particle *const p;
	Vec2f const center;
	double const radius;
};

