#include "interface.h"
#include "publicfuncs.h"
#include <unistd.h>


static float curViewWidth=640;
static float curViewHeight=480;
static float curViewLeft=0;
static float curViewBottom=0;
static float curWindowWidth=640;
static float curWindowHeight=480;
static float curWindowLeft=0;
static float curWindowBottom=0;

void myDisplay(void)
{
        glColor3f(1.0,0.0,0.0);
        drawPolyLineFile("./dino.dat");
        glutSwapBuffers();
}

void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        setWindow(curWindowLeft,curWindowBottom,curWindowWidth,curWindowHeight);
        setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        initWindow();
        myInit();
        glutMainLoop();
}

extern void myReshape(int width, int height) {};

void AniDisp(void)
{
        curViewLeft+=1;
        setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        glutPostRedisplay(); // draws it again
        cout<<"curViewLeft="<<curViewLeft<<endl;
        usleep(50*1000);
}

extern void myMouse(int button, int state, int x, int y)
{
        if (state == GLUT_DOWN) {
                if (button == GLUT_MIDDLE_BUTTON) {
                        glutIdleFunc(AniDisp);
                } else if (button == GLUT_RIGHT_BUTTON) {
                        glutIdleFunc(NULL);
                }
        } else if (button== WHEEL_BUTTOM_UP) {
                curViewWidth*=1.01;
                curViewHeight*=1.01;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
                glutPostRedisplay(); // draws it again
        } else if (button== WHEEL_BUTTOM_DOWN) {
                curViewWidth/=1.01;
                curViewHeight/=1.01;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
                glutPostRedisplay(); // draws it again
        }
}


extern void myKeyboard(unsigned char key, int x, int y)
{
        switch(key) {
                // controls for camera
        case 'A':
        case 'a': {
                curViewLeft-=5;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'D':
        case 'd': {
                curViewLeft+=5;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'W':
        case 'w': {
                curViewBottom+=5;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'S':
        case 's': {
                curViewBottom-=5;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'M':
        case 'm': {
                curWindowBottom=curWindowBottom+curWindowHeight;
                curWindowHeight=-curWindowHeight;
                setWindow(curWindowLeft,curWindowBottom,curWindowWidth,curWindowHeight);
        }
        break;
        case 'F':
        case 'f': {
                curWindowLeft=curWindowLeft+curWindowWidth;
                curWindowWidth=-curWindowWidth;
                setWindow(curWindowLeft,curWindowBottom,curWindowWidth,curWindowHeight);
        }
        break;
        case 'I':
        case 'i': {
                curWindowWidth/=2.0;
                curWindowHeight/=2.0;
                setWindow(curWindowLeft,curWindowBottom,curWindowWidth,curWindowHeight);
        }
        break;
        case 'O':
        case 'o': {
                curWindowWidth*=2.0;
                curWindowHeight*=2.0;
                setWindow(curWindowLeft,curWindowBottom,curWindowWidth,curWindowHeight);
        }
        break;
        case 'J':
        case 'j': {
                curViewWidth/=2.0;
                curViewHeight/=2.0;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'K':
        case 'k': {
                curViewWidth*=2.0;
                curViewHeight*=2.0;
                setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        }
        break;
        case 'G':
        case 'g': {
                //for (curViewWidth=320,curViewHeight=240; curViewWidth<1200; curViewWidth*=1.01) {
        }
        break;
        }
        glutPostRedisplay(); // draws it again
}

extern void myMovedMouse(int x, int y)
{
        printf("(%d,%d)\n\r",x,y);
        curViewLeft=x;
        curViewBottom=screenHeight-y;
        setViewport(curViewLeft,curViewBottom,curViewWidth,curViewHeight);
        glutPostRedisplay(); // draws it again
};

extern void myPassiveMotion(int x, int y) {};

