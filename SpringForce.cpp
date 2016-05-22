
#include <GL/glut.h>

#include "SpringForce.h"

//------------------------------------------------------------------------------

void SpringForce::draw()
{
	glBegin(GL_LINES);
	glColor3f(0.6, 0.7, 0.8);
	glVertex2f(p1->pos[0], p1->pos[1]);
	glColor3f(0.6, 0.7, 0.8);
	glVertex2f(p2->pos[0], p2->pos[1]);
	glEnd();
}

void SpringForce::act()
{
	Vec2 l = p1->pos - p2->pos,
		dl = p1->vel - p2->vel;
	double nl = norm(l);
	Vec2 f = (ks * (nl - dist) + kd * ((l * dl) / nl)) * (l / nl);
	p1->force += f;
	p2->force -= f;
}

//------------------------------------------------------------------------------
