
#include <vector>

#include "System.h"

//------------------------------------------------------------------------------

namespace System {

std::vector<Entity *> entities;
std::vector<Particle *> particles;

//------------------------------------------------------------------------------

void Init()
{
}

void Exit()
{
	Clear();
}

void Draw()
{
	for (Entity *ent : entities)
		ent->draw();
}

void Simulate(Solver solve, float dt)
{
	for (Particle *p : particles)
		solve(*p, dt);
}

void Reset()
{
	for (Entity *ent : entities)
		ent->reset();
}

void Register(Entity *ent)
{
	entities.push_back(ent);
	if (dynamic_cast <Particle *> (ent))
		particles.push_back((Particle *) ent);
}

void Clear()
{
	for (Entity *ent : entities)
		delete ent;
	entities.clear();
	particles.clear();
}

//------------------------------------------------------------------------------

} /* namespace System */

//------------------------------------------------------------------------------
