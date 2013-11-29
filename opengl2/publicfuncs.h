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

#include "interface.h"

#define FUNCPOINT_N 1000
extern GLPoint funcpoints[FUNCPOINT_N];
typedef float (*FUNC)(float x);

void initWindow(void);
void drawDot(GLfloat x, GLfloat y);
void setWindow(GLdouble left, GLdouble bottom, GLdouble width, GLdouble height);
void setViewport(GLdouble left, GLdouble bottom, GLdouble width, GLdouble height);
void createFuncPoints(FUNC func, float startx, float endx);
void drawPolyLineFile(const char * fileName);

GLPoint calViewportXYWantScreenCentre(GLdouble wl, GLdouble wb, GLdouble ww, GLdouble wh, GLdouble vw, GLdouble vh, GLdouble gw, GLdouble gh);
#define WHEEL_BUTTOM_UP 4
#define WHEEL_BUTTOM_DOWN 3


#endif
