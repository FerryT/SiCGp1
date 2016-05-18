#pragma once

#include "Particle.h"

class SpringForce
{
public:
	SpringForce(Particle *P, Particle *Q, double D, double KS, double KD)
		: p1(P), p2(Q), dist(D), ks(KS), kd(KD) {}
	
	void draw();
	
private:
	Particle *const p1;  // particle 1
	Particle *const p2;  // particle 2
	double const dist;   // rest length
	double const ks, kd; // spring strength constants
};
