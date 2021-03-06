//------------------------------------------------------------------------------
// A base class for all forces acting on particles
//------------------------------------------------------------------------------

#pragma once

#include "Entity.h"

class Force : public Entity
{
public:
	Force() {};
	virtual ~Force() {};
	
	virtual void act() = 0;
};

//------------------------------------------------------------------------------
