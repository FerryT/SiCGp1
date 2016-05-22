//------------------------------------------------------------------------------
//  System to manage particles, forces and constraints
//------------------------------------------------------------------------------

#pragma once

#include "Entity.h"
#include "Particle.h"
#include "SpringForce.h"
#include "GravityForce.h"
#include "RodConstraint.h"
#include "CircularWireConstraint.h"
#include "Solvers.h"

namespace System {

//------------------------------------------------------------------------------

void Init();
void Exit();

void Draw();
void Simulate(Solver, float dt);
void Reset();

void Register(Entity *);
template <typename T, typename... Args> inline T *Create(Args... args)
	{ T *ptr = new T(args...); Register(ptr); return ptr; }
void Clear();

//------------------------------------------------------------------------------

} /* namespace System */

//------------------------------------------------------------------------------
