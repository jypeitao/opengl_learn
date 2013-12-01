#include "interface.h"
#include "publicfuncs.h"

float initial = 0.1f;
float factor = 0.7f;
float calculateY(float x)
{
    return 4*factor*x*(1-x);

}
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

void drawCircle(void)
{
        glColor3f(0,1.0,0);
        glLineWidth(8);
        glPointSize(2);
        glBegin(GL_POINTS);
        for (float t=0; t<2*PI; t+=0.01) {
                float x=cos(t);
                float y=sin(t);
                glVertex2f(x,y);
        }
        glEnd();
}
void drawParabola()
{
 GLPoint current;
GLPoint next; 

current.x = initial;
current.y = calculateY(current.x);
    glColor3f(0,1.0,0);
    glLineWidth(8);
    glPointSize(2);
    glBegin(GL_LINES);
    for (float t=0; t<2*PI; t+=0.01) {
        float x=cos(t);
        float y=sin(t);
        glVertex2f(x,y);
    }
    glEnd();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawParabola();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void myInit()
{
//        glClearColor(0.0, 0.0, 0.0, 0.0);
//        setWindow(-4,-4,8*screenWidth/screenHeight,8);
//        GLPoint xy = calViewportXYWantScreenCentre(-4,-4,8*screenWidth/screenHeight,8,screenWidth,screenHeight,screenWidth,screenHeight);
//        glViewport(xy.x, xy.y, screenWidth, screenHeight);
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        initWindow();
        myInit();
        glutMainLoop();
}

extern void myReshape(int width, int height) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    setWindow(-4,-4,8*width/height,8);
    GLPoint xy = calViewportXYWantScreenCentre(-4,-4,8*width/height,8,width,height,width,height);
    glViewport(xy.x, xy.y, width, height);

};

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
                        drawCircle();
                        glFlush();
                }
        }
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
