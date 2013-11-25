#ifndef PUBLICFUNCS
#define PUBLICFUNCS
#define LINUX
#ifdef LINUX
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else 
#include <GLUT/glut.h>
#endif

void initWindow(void);
void drawDot(GLfloat x, GLfloat y);

#endif
