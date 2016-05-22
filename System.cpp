
#include "System.h"

//------------------------------------------------------------------------------

namespace System {

std::vector<Entity *> entities;
std::vector<Particle *> particles;
std::vector<Force *> forces;

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
		p->force = 0;
	for (Force *f : forces)
		f->act();
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
	if (dynamic_cast <Force *> (ent))
		forces.push_back((Force *) ent);
}

void Clear()
{
	for (Entity *ent : entities)
		delete ent;
	entities.clear();
	particles.clear();
	forces.clear();
}

const Particles *GetParticles()
{
	return &particles;
}

//------------------------------------------------------------------------------

} /* namespace System */

//------------------------------------------------------------------------------
