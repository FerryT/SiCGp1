
#include <GL/glut.h>

#include "RodConstraint.h"

//------------------------------------------------------------------------------

void RodConstraint::draw()
{
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(p1->pos[0], p1->pos[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(p2->pos[0], p2->pos[1]);
	glEnd();
}

//------------------------------------------------------------------------------
