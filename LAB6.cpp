// LAB6_Zadanie1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <GL\freeglut.h>
#include <iostream>

int button_x;
int button_y;
int button_state = GLUT_UP;
float rotatex;
float rotatey;
float distance = -20.0f;
int N = 10;

enum SHAPES
{
	CONE,
	CUBE,
	CYLINDER,
	DODECAHEDRON,
	COSAHEDON,
	OCTAHEDRON,
	RHOMBICDODECAHEDRON,
	SHPERE,
	TEAPOT,
	TETRAHEDRON,
	THORUS
};

SHAPES shape;

void DrawFunction()
{

}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(0.0f, -5.0f, distance);
	glRotatef(rotatex, 1.0f, 0.0, 0.0);
	glRotatef(rotatey, 0.0f, 1.0f, 0.0f);

	for (int n = 0; n < N; n++)
	{
		for (int i = 0; i < N - n; i++)
		{
			for (int j = 0; j < N - n; j++)
			{
				glPushMatrix();
				glTranslatef(j - (N - n) / 2.0, i - (N - n) / 2.0, -n);
				glRotatef(180, 1.0f, 0.0f, 0.0f);
				switch (shape)
				{
				case SHAPES::CONE:
					glutSolidCone(1, 1, 10, 10);
					break;
				case SHAPES::CUBE:
					glutSolidCube(1);
					break;
				case SHAPES::CYLINDER:
					glutSolidCylinder(0.5, 1, 20, 20);
					break;
				case SHAPES::DODECAHEDRON:
					glutSolidDodecahedron();
					break;
				case SHAPES::COSAHEDON:
					glutSolidIcosahedron();
					break;
				case SHAPES::OCTAHEDRON:
					glutSolidOctahedron();
					break;
				case SHAPES::RHOMBICDODECAHEDRON:
					glutSolidRhombicDodecahedron();
					break;
				case SHAPES::SHPERE:
					glutSolidSphere(0.5, 50, 50);
					break;
				case SHAPES::TEAPOT:
					glutSolidTeapot(0.4);
					break;
				case SHAPES::TETRAHEDRON:
					glutSolidTetrahedron();
					break;
				case SHAPES::THORUS:
					glutSolidTorus(0.1, 0.2, 50, 10);
					break;
				}
				glPopMatrix();
			}
		}
	}


	glPopMatrix();

	glutSwapBuffers();
}

void Idle()
{
	glutPostRedisplay();
}

void Resize(int w, int h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	float a = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75.0, a, 0.1, 100);
}

void InitScene()
{
	glClearColor(0, 0, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glFrontFace(GL_CW);
	glShadeModel(GL_FLAT);

	shape = SHAPES::OCTAHEDRON;
}

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		button_state = state;

		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		rotatey -= (x - button_x) / 2.0;
		button_x = x;
		rotatex -= (y - button_y) / 2.0;
		button_y = y;
		glutPostRedisplay();
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == '+')
		distance += 0.5f;
	if (key == '-')
		distance -= 0.5f;
}

void Menu(int value)
{
	switch (value)
	{
	case CONE:
		shape = CONE;
		break;
	case CUBE:
		shape = CUBE;
		break;
	case CYLINDER:
		shape = CYLINDER;
		break;
	case DODECAHEDRON:
		shape = DODECAHEDRON;
		break;
	case COSAHEDON:
		shape = COSAHEDON;
		break;
	case OCTAHEDRON:
		shape = OCTAHEDRON;
		break;
	case RHOMBICDODECAHEDRON:
		shape = RHOMBICDODECAHEDRON;
		break;
	case SHPERE:
		shape = SHPERE;
		break;
	case TEAPOT:
		shape = TEAPOT;
		break;
	case TETRAHEDRON:
		shape = TETRAHEDRON;
		break;
	case THORUS:
		shape = THORUS;
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("LAB 6");

	InitScene();

	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutReshapeFunc(Resize);
	glutMotionFunc(MouseMotion);
	glutMouseFunc(MouseButton);
	glutKeyboardFunc(Keyboard);

	glutCreateMenu(Menu);
	glutAddMenuEntry("Cone", CONE);
	glutAddMenuEntry("Cube", CUBE);
	glutAddMenuEntry("Cylinder", CYLINDER);
	glutAddMenuEntry("Dodecahedron", DODECAHEDRON);
	glutAddMenuEntry("Cosahedon", COSAHEDON);
	glutAddMenuEntry("Octahedron", OCTAHEDRON);
	glutAddMenuEntry("RombicDodecahedron", RHOMBICDODECAHEDRON);
	glutAddMenuEntry("Sphere", SHPERE);
	glutAddMenuEntry("Teapot", TEAPOT);
	glutAddMenuEntry("Tetrahedron", TETRAHEDRON);
	glutAddMenuEntry("Thorus", THORUS);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	return 0;
}