#include "GravityForce.h"
#include <GL/glut.h>

GravityForce::GravityForce(const Vec2f &O, const Vec2f &V) : force(O)
{
  force.m_Velocity = V;
  force.m_Position = O + V;
}

void GravityForce::draw()
{
  glBegin( GL_LINES );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_ConstructPos[0], force.m_ConstructPos[1] );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_Position[0], force.m_Position[1] );
  glEnd();
  
  Vec2f arrow = (perp(force.m_Velocity) + force.m_Velocity) / 4;
  
  glBegin( GL_LINES );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_Position[0], force.m_Position[1] );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_Position[0] + arrow[0], force.m_Position[1] - arrow[1] );
  glEnd();
  glBegin( GL_LINES );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_Position[0], force.m_Position[1] );
  glColor3f(0.8, 0.7, 0.6);
  glVertex2f( force.m_Position[0] - arrow[0], force.m_Position[1] - arrow[1]);
  glEnd();
}
