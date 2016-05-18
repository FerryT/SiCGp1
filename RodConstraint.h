#pragma once

#include "Particle.h"

class RodConstraint
{
public:
	RodConstraint(Particle *P, Particle *Q, double D)
		: p1(P), p2(Q), dist(D) {}
	
	void draw();
	
private:
	Particle *const p1;
	Particle *const p2;
	double const dist;
};
