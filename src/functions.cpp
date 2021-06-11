
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "projections.h"


float x_rotation = 0.0f, y_rotation = 0.0f, tx = 0.0f, ty = 0.0f, tz = 0.0f;
float dx = 0.0f, dy = 0.0f;
int mouseClicked = 0;


void createCube(){
	glTranslatef(tx, ty, tz);

	glBegin(GL_QUADS);

	// TOP SQUARE
	glColor3f(0.3f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	// BOTTOM SQUARE
	glColor3f(0.3f, 0.3f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	// FRONT SQUARE
	glColor3f(0.0f, 0.0f, 0.3f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// BACK	SQUARE
	glColor3f(0.3f, 0.0f, 0.3f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5, -0.5f);

	// RIGHT SQUARE
	glColor3f(0.2f, 0.6f, 0.2f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	// LEFT SQUARE
	glColor3f(0.4f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();
}


int initialize(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);
	return 1;
}


void displayCube(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	gluLookAt(
	0.0, 0.0f, 3.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f);

	glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
	glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
	createCube();

	glFlush();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseClicked = 1;
		dx = x - y_rotation;
		dy = -y + x_rotation;
	}
	else mouseClicked = 0;
}


void mouseMovement(int x, int y){
	if (mouseClicked){
		y_rotation = x - dx;
		x_rotation = y + dy;
		glutPostRedisplay();
	}
}


void perspective_projection(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(50.0, w / h, 1.0, 100.0 * 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void cavalier_projection(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	double theta = 45.0;
    double cavalier[16] = {
            1.0                               , 0.0                               , 0.0, 0.0,
            0.0                               , 1.0                               , 0.0, 0.0,
            4.0 * cos((theta)/(180.0 / M_PI)) , 4.0 * sin((theta)/(180.0 / M_PI)) , 1.0, 0.0,
            0.0                               , 0.0                               , 0.0, 1.0};
    glMultMatrixd(cavalier);
	glOrtho(-1.5,1.5,-1.5,1.5,-3.0,9.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void cabinet_projection(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	double theta = 63.4;
    double cabinet[16] = {
            1.0                               , 0.0                               , 0.0, 0.0,
            0.0                               , 1.0                               , 0.0, 0.0,
            2.0 * cos((theta)/(180.0 / M_PI)) , 2.0 * sin((theta)/(180.0 / M_PI)) , 1.0, 0.0,
            0.0                               , 0.0                               , 0.0, 1.0};
    glMultMatrixd(cabinet);
	glOrtho(-1.5,1.5,-1.5,1.5,-3.0,9.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}