#include "interface.h"
#include "publicfuncs.h"

void drawAxis(void)
{
    glColor3f(1.0, 0, 0);
    glLineWidth(8);
    glBegin(GL_LINES);
        glVertex2i(-4,0);
        glVertex2i(4,0);
        glVertex2i(0,4);
        glVertex2i(0,-4);
    glEnd();
}

void drawSin(void)
{
    glColor3f(0,1.0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    int N=50;
    for (int i=0;i<N;i++)
    {
	float x=2*PI*i/(N-1)-PI;
	float y=sin(x);
	glVertex2f(x,y);
    }
    glEnd();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    drawSin();
    glFlush();
}

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    initWindow();
    myInit();
    glutMainLoop();
}

extern void myReshape(int width, int height) {};

extern void myMouse(int button, int state, int x, int y) 
{
    if (state == GLUT_DOWN)
    {   
        if (button == GLUT_LEFT_BUTTON)
        {   
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
	    drawAxis();
            glFlush();
        }   
        else if (button == GLUT_RIGHT_BUTTON)
        {   
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
	    drawSin();
            glFlush();
        }   
    }   
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
