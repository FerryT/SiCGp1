
#include <GL/glut.h>

#include "Particle.h"

void Particle::reset()
{
	pos = ini;
	vel = Vec2f(0.0, 0.0);
}

void Particle::draw()
{
	const double h = 0.03;
	glColor3f(1.f, 1.f, 1.f);
	glBegin(GL_QUADS);
	glVertex2f(pos[0] - h / 2.0, pos[1] - h / 2.0);
	glVertex2f(pos[0] + h / 2.0, pos[1] - h / 2.0);
	glVertex2f(pos[0] + h / 2.0, pos[1] + h / 2.0);
	glVertex2f(pos[0] - h / 2.0, pos[1] + h / 2.0);
	glEnd();
}
