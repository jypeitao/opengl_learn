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

void drawRect(void)
{
        glColor3f(0,1.0,0);
        glLineWidth(2);
        glBegin(GL_POLYGON);
        glVertex2i(-2,2);
        glVertex2i(-2,-2);
        glVertex2i(2,-2);
        glVertex2i(2,2);
        glEnd();
}

void myDisplay(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        drawAxis();
        drawRect();
        glFlush();
}

//Fix View, then Window w/h = View w/h
void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(-5.0, -5.0, 10.0*screenWidth/screenHeight, 10.0);
        setViewport(0.0, 0.0, 640.0, 480.0);
}

//Fix View, then Window w/h = View w/h, but view extends beyond the pysical screen
void myInit2()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(-5.0, -5.0, 10.0*screenWidth/screenHeight, 10.0);
        setViewport((640-480)/2.0, 0.0, 640.0, 480.0);
}

//Fix Window, then View w/h = Window w/h
void myInit3()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(-5.0, -5.0, 10.0, 10.0);
        setViewport((640-480)/2, 0.0, 480.0, 480.0);
}

//Fix Window, then View w/h = Window w/h
void myInit4()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(-5.0, -5.0, 10.0, 10.0);
        setViewport(0.0, 0.0, 480.0, 480.0);
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        initWindow();
        myInit2();
        glutMainLoop();
}

extern void myReshape(int width, int height) {};

extern void myMouse(int button, int state, int x, int y)
{
        if (state == GLUT_DOWN) {
                if (button == GLUT_LEFT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawAxis();
                        glFlush();
                } else if (button == GLUT_RIGHT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawRect();
                        glFlush();
                }
        }
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
