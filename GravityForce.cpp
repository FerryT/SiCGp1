
#include <GL/glut.h>

#include "GravityForce.h"

void GravityForce::draw()
{
	force.pos = force.ini + force.vel;
	
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.ini[0], force.ini[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.pos[0], force.pos[1]);
	glEnd();
	
	Vec2f arrow = (perp(force.vel) + force.vel) / 4;
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.pos[0], force.pos[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.pos[0] + arrow[0], force.pos[1] - arrow[1]);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.pos[0], force.pos[1]);
	glColor3f(0.8, 0.7, 0.6);
	glVertex2f(force.pos[0] - arrow[0], force.pos[1] - arrow[1]);
	glEnd();
}
