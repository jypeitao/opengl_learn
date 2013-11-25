#include "interface.h"
#include "publicfuncs.h"
int hailListX0 = 400;
extern void hailListDisplay();
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
    glBegin(GL_POINTS);
    int N=500;
    for (int i=0;i<N;i++)
    {
	float x=2*PI*i/(N-1)-PI;
	float y=sin(x);
	glVertex2f(x,y);
    }
    glEnd();
}

void drawNew(void)
{
    glTranslatef(-10,0,0);
    glColor3f(0,1.0,0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    int N=5000;
    for (int i=0;i<N;i++)
    {
        float radian = 2*PI*i/(N-1);
        float x = 10 + sin(15*radian);
        float y=sin(radian);
        glVertex2f(x,y);
    }
    glEnd();
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawAxis();
    //drawNew();
    hailListDisplay();
    glFlush();
}
void hailListInit() {
 glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(1.0f,0.0f,0.0f);
 glPointSize(4.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-640.0,640.0,-480.0,480.0);
}

//迭代函数
int hailListf(int x) {
 if (x%2 == 0)
  return x/2;
 else
  return 3*x+1;
}

void hailListDisplay() {
 //第一次迭代，算出kBiggest和yBiggest
 int kBiggest = 0,yBiggest = 1,y0 = hailListX0;
 while ((y0 = hailListf(y0)) != 1) {
  if (y0 > yBiggest)
   yBiggest = y0;
  kBiggest++;
 }
 y0 = hailListX0;
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
 for (int k = 0;k <= kBiggest;k++) {
  //printf("%d\t%d\n",k,y0);
  glVertex2i(k*1.0/kBiggest*600,y0*1.0/yBiggest*450);
  y0 = hailListf(y0);
 }
 glEnd();
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
    //myInit();
hailListInit();
    glutMainLoop();
}

extern void myReshape(int width, int height) {};

extern void myMouse(int button, int state, int x, int y) 
{
    if (state == GLUT_DOWN)
    {   
        if (button == GLUT_LEFT_BUTTON)
        {   
            //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            //glClear(GL_COLOR_BUFFER_BIT);
	   // drawAxis();
            //glFlush();
        }   
        else if (button == GLUT_RIGHT_BUTTON)
        {   
           // glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            //glClear(GL_COLOR_BUFFER_BIT);
	    //drawSin();
            //glFlush();
        }   
    }   
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
