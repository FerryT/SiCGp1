
#include <vector>

#include "Particle.h"

#define DAMP 0.98f
#define RAND (((rand()%2000)/1000.f)-1.f)
void simulation_step(std::vector<Particle*> pVector, float dt)
{
	int ii, size = pVector.size();
	
	for (ii = 0; ii < size; ii++)
	{
		pVector[ii]->pos += dt * pVector[ii]->vel;
		pVector[ii]->vel = DAMP * pVector[ii]->vel + Vec2f(RAND, RAND) * 0.005;
	}
}

