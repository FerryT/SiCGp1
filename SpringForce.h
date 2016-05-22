//------------------------------------------------------------------------------
//  A force that acts as a spring
//------------------------------------------------------------------------------

#pragma once

#include "Force.h"
#include "Particle.h"

class SpringForce : public Force
{
public:
	SpringForce(Particle *P, Particle *Q, double D, double KS, double KD)
		: p1(P), p2(Q), dist(D), ks(KS), kd(KD) {}
	virtual void draw();
	virtual void act();
	
private:
	Particle *const p1;  // particle 1
	Particle *const p2;  // particle 2
	double const dist;   // rest length
	double const ks, kd; // spring strength constants
};

//------------------------------------------------------------------------------
