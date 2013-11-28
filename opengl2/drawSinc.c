#include "interface.h"
#include "publicfuncs.h"

float sinc(float x)
{
        float y=(x==0)?1:sin(PI*x)/(PI*x);
        return y;
}

void drawAxis(int left, int right, int bottom, int top)
{
        glColor3f(1.0, 0, 0);
        glLineWidth(8);
        glBegin(GL_LINES);
        glVertex2i(left,0);
        glVertex2i(right,0);
        glVertex2i(0,bottom);
        glVertex2i(0,top);
        glEnd();
}

void drawFunc(void)
{
        glColor3f(0,1.0,0);
        glLineWidth(4);
        glPointSize(4);
        glBegin(GL_POINTS);
        for (int i=0; i<FUNCPOINT_N; i++) {
                glVertex2f(funcpoints[i].x,funcpoints[i].y);
        }
        glEnd();
}


float startx=-10.0;
float endx=10.0;
float deltax=1;
float deltay=1;
float miny=-1;
float maxy=1;

void myDisplay(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        drawAxis(startx-deltax,endx+deltax,miny-deltay,maxy+deltay);
        drawFunc();
        glFlush();
}

void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(startx-2*deltax,miny-2*deltay, endx-startx+4*deltax, maxy-miny+4*deltay);
        glViewport((screenWidth-screenHeight)/2, 0, screenHeight, screenHeight);
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        initWindow();
        myInit();
        createFuncPoints(sinc,startx, endx);
        glutMainLoop();
}

extern void myReshape(int width, int height) {};

extern void myMouse(int button, int state, int x, int y)
{
        if (state == GLUT_DOWN) {
                if (button == GLUT_LEFT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawAxis(-10,10,-10,10);
                        glFlush();
                } else if (button == GLUT_RIGHT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawFunc();
                        glFlush();
                }
        }
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
