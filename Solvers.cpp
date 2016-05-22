
#include <vector>

#include "Solvers.h"

#define DAMP 0.98f
#define RAND (((rand()%2000)/1000.f)-1.f)

namespace Solvers {

//------------------------------------------------------------------------------

void Dummy(Particle &p, float dt)
{
	p.pos += dt * p.vel;
	p.vel = DAMP * p.vel + Vec2f(RAND, RAND) * 0.005;
}

//------------------------------------------------------------------------------

} /* namespace Solvers */

//------------------------------------------------------------------------------
