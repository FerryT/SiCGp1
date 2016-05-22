//------------------------------------------------------------------------------
//  Solvers used for simulation steps
//------------------------------------------------------------------------------

#pragma once

#include "Particle.h"

typedef void (*Solver)(Particle &, float dt);

namespace Solvers {

//------------------------------------------------------------------------------

void Dummy(Particle &, float dt);

//------------------------------------------------------------------------------

} /* Solvers */

//------------------------------------------------------------------------------
