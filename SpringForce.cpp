
#include <GL/glut.h>

#include "SpringForce.h"

void SpringForce::draw()
{
	glBegin(GL_LINES);
	glColor3f(0.6, 0.7, 0.8);
	glVertex2f(p1->pos[0], p1->pos[1]);
	glColor3f(0.6, 0.7, 0.8);
	glVertex2f(p2->pos[0], p2->pos[1]);
	glEnd();
}
