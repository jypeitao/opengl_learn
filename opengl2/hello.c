#include "interface.h"
#include "publicfuncs.h"

void myDisplay(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0, 0);
        glutWireTeapot(3);
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

extern void myMouse(int button, int state, int x, int y) {};

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
