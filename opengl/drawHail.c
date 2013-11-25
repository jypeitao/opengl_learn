#include "interface.h"
#include "publicfuncs.h"
long long mInitY = 1000;
long long mBigX = 0;
long long mBigY = 0;
double scaleX = 1.0f;
double scaleY = 1.0f;
long long calculateValue(long long x)
{
    long long ret = x >> 1;
    if(x & 0x01)
    {
        ret = 3*x + 1;
    }
    return ret;
}
void sequence(long long s0)
{
    long long t = s0;
    while(t!=1)
    {
        t = calculateValue(t);
        cout<<t<<endl;
    }
}
void calculateMaxValue(long long y0,long long &bigX,long long &bigY) 
{
    bigX = bigY = 0;
    long long t = y0;
    do
    {
        t = calculateValue(t);
        if(t > bigY)
        {
            bigY = t;
        }
        bigX++;
    }while(t!=1);
    cout<<"bigX = "<<bigX<<" bigY = "<<bigY<<endl;
}
void calculateScale(double &sx,double &sy)
{
//    cout<<"mBigX = "<<mBigX<<endl;
//    cout<<"mBigY = "<<mBigY<<endl;
//    cout<<"height = "<<screenHeight<<endl;
    sx = (double)(screenWidth - 10) / mBigX;
    sy = (double)(screenHeight - 10) / mBigY;
//    cout<<"sy = "<<sy<<endl;

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

void drawHail(void)
{
    glColor3f(1.0, 0, 0);
 //   glLineWidth(2);
    glBegin(GL_POINTS);
    long long t = mInitY;
    int x = 0;
    do
    {
        t = calculateValue(t);
        x++;
        glVertex2f(x*scaleX,t*scaleY);

    cout<<x<<"#"<<t<<endl;
   //     cout<<x*scaleX<<"#"<<t*scaleY<<endl;
    }while(t!=1);
    glEnd();
}
void drawSin(void)
{
    glColor3f(0,1.0,0);
    glLineWidth(2);
//    glBegin(GL_POINTS);
    glBegin(GL_LINES);
    int N=50;
    for (float i=0;i<2*PI;i=i+1/PI)
    {
	float x=sin(15*i);
	float y=sin(i);
	glVertex2f(x,y);
    }
    glEnd();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawHail();
    glFlush();
}

void myInit()
{
    calculateMaxValue(mInitY,mBigX,mBigY);
    calculateScale(scaleX,scaleY);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, screenWidth, 0, screenHeight, 5, 115);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
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
//    if (state == GLUT_DOWN)
//    {   
//        if (button == GLUT_LEFT_BUTTON)
//        {   
//            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//            glClear(GL_COLOR_BUFFER_BIT);
//	    drawAxis();
//            glFlush();
//        }   
//        else if (button == GLUT_RIGHT_BUTTON)
//        {   
//            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//            glClear(GL_COLOR_BUFFER_BIT);
//	    drawSin();
//            glFlush();
//        }   
//    }   
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
