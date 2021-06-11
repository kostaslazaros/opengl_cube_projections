#ifndef PROJECTIONS
#define PROJECTIONS


void createCube();
int initialize(void);
void displayCube(void);
void mouse(int button, int state, int x, int y);
void mouseMovement(int x, int y);
void perspective_projection(int w, int h);
void cavalier_projection(int w, int h);
void cabinet_projection(int w, int h);

#endif
