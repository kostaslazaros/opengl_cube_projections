// to compile correctly: g++ main.cpp functions.cpp -lglut -lGL -lGLU
// then to run: ./a.out


#include<stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "projections.h"


int main(int argc, char *argv[]){

	glutInit(&argc, argv);

	glutInitWindowPosition(10, 150);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Perspective Projection");
	glutDisplayFunc(displayCube);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMovement);
	glutReshapeFunc(perspective_projection);

	if (!initialize())
		return 1;

	glutInitWindowPosition(510, 150);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Cavalier Projection");
	glutDisplayFunc(displayCube);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMovement);
	glutReshapeFunc(cavalier_projection);

	if (!initialize())
		return 1;

	glutInitWindowPosition(1010, 150);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Cabinet Projection");
	glutDisplayFunc(displayCube);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMovement);
	glutReshapeFunc(cabinet_projection);

	if (!initialize())
		return 1;

	glutMainLoop();

	return 0;
}
