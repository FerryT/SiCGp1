// TinkerToy.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#include "System.h"

#include "imageio.h"

#define WINDOW_TITLE "Tinkertoys!"

// global variables
int N = 64;
float dt = 0.1;
float d = 5.0;

bool simulate = false;
bool dump_frames = false;
int frame_number = 0;

unsigned char *frame_buffer = NULL;
size_t frame_buffer_size = 0;

#define FRAME_INTERVAL 4

//------------------------------------------------------------------------------
//  main --- main routine
//------------------------------------------------------------------------------

void init_system();
void init_glut();
void exit_func();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	
	if (argc < 4)
		fprintf(stderr, "Using defaults : N=%d dt=%g d=%g\n", N, dt, d);
	else
	{
		N = atoi(argv[1]);
		dt = atof(argv[2]);
		d = atof(argv[3]);
	}
	
	printf("\n\nHow to use this application:\n\n");
	printf("\t Toggle construction/simulation display with the spacebar key\n");
	printf("\t Dump frames by pressing the 'd' key\n");
	printf("\t Quit by pressing the 'q' or 'esc' key\n");
	
	atexit(exit_func);
	
	init_system();
	System::Init();
	
	init_glut();
	glutMainLoop();
	
	exit(0);
}

void exit_func()
{
	if (frame_buffer)
	{
		frame_buffer = NULL;
		frame_buffer_size = 0;
	}
	System::Exit();
}

//------------------------------------------------------------------------------
//  free/clear/allocate simulation data
//------------------------------------------------------------------------------

void init_system()
{
	const double dist = 0.2;
	const Vec2f center(0.0, 0.0);
	const Vec2f offset(dist, 0.0);
	
	Particle *p1 = System::Create<Particle>(center + offset * 1);
	Particle *p2 = System::Create<Particle>(center + offset * 2);
	Particle *p3 = System::Create<Particle>(center + offset * 3);
	
	System::Create<SpringForce>(p1, p2, dist, 1.0, 1.0);
	System::Create<RodConstraint>(p2, p3, dist);
	System::Create<CircularWireConstraint>(p1, center, dist);
	System::Create<GravityForce>(center, perp(offset) * 0.981);
}

//------------------------------------------------------------------------------
//  init GLUT --- open a glut compatible window and set callbacks
//------------------------------------------------------------------------------

static void key_func(unsigned char key, int x, int y);
static void mouse_func(int button, int state, int x, int y);
static void motion_func(int x, int y);
static void reshape_func(int width, int height);
static void idle_func();
static void display_func();

void pre_display();
void post_display();

void get_from_UI();
void remap_GUI();

struct
{
	int id;
	int width, height;
} win = {0, 512, 512};

int mouse_down[3];
int mouse_release[3];
int mouse_shiftclick[3];
int omx, omy, mx, my;
int hmx, hmy;

void init_glut()
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(win.width, win.height);
	win.id = glutCreateWindow(WINDOW_TITLE);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	pre_display();
	glutKeyboardFunc(key_func);
	glutMouseFunc(mouse_func);
	glutMotionFunc(motion_func);
	glutReshapeFunc(reshape_func);
	glutIdleFunc(idle_func);
	glutDisplayFunc(display_func);
}

//------------------------------------------------------------------------------
// GLUT callback routines
//------------------------------------------------------------------------------

static void key_func(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'c':
		case 'C':
			System::Reset();
			break;
		
		case 'd':
		case 'D':
			dump_frames = !dump_frames;
			printf("%s dumping frames.\n", dump_frames ? "Started" : "Stopped");
			break;
			
		case 'q':
		case 'Q':
		case '\e':
			exit(0);
			break;
			
		case ' ':
			simulate = !simulate;
			break;
	}
}

static void mouse_func(int button, int state, int x, int y)
{
	omx = mx = x;
	omx = my = y;
	
	if (!mouse_down[0])
	{
		hmx = x;
		hmy = y;
	}
	
	if (mouse_down[button])
	{
		mouse_release[button] = state == GLUT_UP;
		mouse_shiftclick[button] = glutGetModifiers() == GLUT_ACTIVE_SHIFT;
	}
	mouse_down[button] = state == GLUT_DOWN;
}

static void motion_func(int x, int y)
{
	mx = x;
	my = y;
}

static void reshape_func(int width, int height)
{
	glutSetWindow(win.id);
	glutReshapeWindow(width, height);
	win.width = width;
	win.height = height;
}

static void idle_func()
{
	if (simulate)
		System::Simulate(Solvers::Dummy, dt);
	else
	{
		get_from_UI();
		remap_GUI();
	}
	
	glutSetWindow(win.id);
	glutPostRedisplay();
}

static void display_func()
{
	pre_display();
	System::Draw();
	post_display();
}

//------------------------------------------------------------------------------
//  OpenGL specific drawing routines
//------------------------------------------------------------------------------

void pre_display()
{
	float ratio = (float) win.width / (float) win.height;
	glViewport(0, 0, win.width, win.height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-ratio, ratio, -1.0, 1.0);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void post_display()
{
	if (dump_frames && !(frame_number % FRAME_INTERVAL))
	{
		const unsigned int w = win.width;
		const unsigned int h = win.height;
		const size_t size = w * h * 4;
		
		if (frame_buffer_size != size)
		{
			if (frame_buffer)
				delete [] frame_buffer;
			frame_buffer = new unsigned char[size];
			frame_buffer_size = size;
		}
		
		if (!frame_buffer)
		{
			dump_frames = false;
			perror("Unable to allocate memory for frame dump.");
		}
		
		glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, frame_buffer);
		static char filename[80];
		sprintf(filename, "snapshots/img%.5i.png", frame_number / FRAME_INTERVAL);
		//printf("Dumped %s.\n", filename);
		saveImageRGBA(filename, frame_buffer, w, h);
	}
	
	frame_number++;
	glutSwapBuffers();
}

//------------------------------------------------------------------------------
//  relates mouse movements to tinker toy construction
//------------------------------------------------------------------------------

// Todo: Rewrite this

void get_from_UI()
{
	int i, j;
	// int size, flag;
	int hi, hj;
	
	// float x, y;
	if (!mouse_down[0] && !mouse_down[2] && !mouse_release[0]
	        && !mouse_shiftclick[0] && !mouse_shiftclick[2]) return;
	        
	i = (int)((mx / (float)win.width) * N);
	j = (int)(((win.height - my) / (float)win.height) * N);
	
	if (i < 1 || i > N || j < 1 || j > N) return;
	
	if (mouse_down[0])
	{
	}
	
	if (mouse_down[2])
	{
	}
	
	hi = (int)((hmx / (float)win.width) * N);
	hj = (int)(((win.height - hmy) / (float)win.height) * N);
	
	if (mouse_release[0])
	{
	}
	
	omx = mx;
	omy = my;
}

void remap_GUI()
{
	/*int ii, size = pVector.size();
	
	for (ii = 0; ii < size; ii++)
	{
		pVector[ii]->pos[0] = pVector[ii]->ini[0];
		pVector[ii]->pos[1] = pVector[ii]->ini[1];
	}*/
}

//------------------------------------------------------------------------------
