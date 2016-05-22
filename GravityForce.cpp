
#include <GL/glut.h>

#include "GravityForce.h"

//------------------------------------------------------------------------------

GravityForce::GravityForce(const Vec2f &O, const Vec2f &G, const Particles *P)
	: origin(O), force(G), position(O + G), arrow((perp(G) + G) / 4.0),
	particles(P)
{
}

void GravityForce::draw()
{
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(origin[0], origin[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(position[0], position[1]);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(position[0], position[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(position[0] + arrow[0], position[1] - arrow[1]);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(position[0], position[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(position[0] - arrow[0], position[1] - arrow[1]);
	glEnd();
}

//------------------------------------------------------------------------------

void GravityForce::act()
{
	for (Particle *p : *particles)
		p->force += p->mass * force;
}

//------------------------------------------------------------------------------
