
#include <GL/glut.h>

#include "CircularWireConstraint.h"

#define PI 3.1415926535897932384626433832795

static void draw_circle(const Vec2f &vect, float radius)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < 360; i = i + 18)
	{
		float rad = i * PI / 180;
		glVertex2f(vect[0] + cos(rad) * radius, vect[1] + sin(rad) * radius);
	}
	glEnd();
}

void CircularWireConstraint::draw()
{
	draw_circle(center, radius);
}
