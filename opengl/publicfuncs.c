#include "publicfuncs.h"
#include "interface.h"

void initWindow(void)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("my first attempt");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutMotionFunc(myMovedMouse);
    glutPassiveMotionFunc(myPassiveMotion);
}

void drawDot(GLfloat x, GLfloat y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

