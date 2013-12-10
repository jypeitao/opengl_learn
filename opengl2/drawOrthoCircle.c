#include "interface.h"
#include "publicfuncs.h"
#include <float.h>

#define POINTS_NUM 200
GLPoint points[POINTS_NUM];
float initial = 0.1f;
float factor = 0.7f;
int current_pos = 0;
float calculateY(float x)
{
    return 4*factor*x*(1-x);

}
GLPoint calculateNextPoint(const GLPoint& current)
{
    GLPoint next;
    float t = calculateY(current.x);
    if(fabs(current.y - t) < FLT_EPSILON)
    {
        next.y = current.y;
        next.x =  next.y;
    }
    else
    {
        next.x = current.x;
        next.y =  calculateY(next.x);
    }
   // cout<<next.x<<"*"<<next.y<<endl;
    return next;
}
void drawAxis(void)
{
        glColor3f(1.0, 0, 0);
        glLineWidth(8);
        glBegin(GL_LINES);
        glVertex2i(-10,0);
        glVertex2i(10,0);
        glVertex2i(0,10);
        glVertex2i(0,-10);
        glEnd();
}

void drawCircle(const GLPoint& origin,float radius)
{
        glColor3f(0,1.0,0);
        //glLineWidth(8);
        //glPointSize(2);
        glBegin(GL_POINTS);
   //      for (float t=0; t<2*PI; t+=0.001) {
   //             float x=radius*cos(t) + origin.x;
   //             float y=radius*sin(t) + origin.y;
   //             glVertex2f(x,y);
   //     }
        
        for (float t=0; t<2*PI; t+=0.01) {
                float x=radius*cos(t) + origin.x;
                float y=radius*sin(t) + origin.y;
                //cout<<x*x+y*y<<endl;
                glVertex2f(x,y);
        }
        glEnd();
}
void drawXCircle()
{
    //float n = 1.0f;
        for (float n = 2.0f; n < 5.0f; n+=1) {
            GLPoint p;
            p.x = n;
            p.y = 0.0f;
            float r = sqrt(n*n - 1);
            drawCircle(p,r);
            p.x = -p.x;
            drawCircle(p,r);
        }
}

void drawYCircle()
{
    //float n = 1.0f;
        for (float n = 2.0f; n < 5.0f; n+=1) {
            GLPoint p;
            p.x = 0.0f;
            p.y = n;
            float r = sqrt(n*n - 1);
            drawCircle(p,r);
            p.y = -p.y;
            drawCircle(p,r);
        }
}
void drawArc()
{
    glColor3f(1.0,0,0);
    glPointSize(1);
    glBegin(GL_POINTS);
    float f = 1.0f/1000;
    for(int i = 0;i<1000;i++)
    {

        float x = f*i;
        float y = calculateY(x);

        glVertex2f(x,y);
    }
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);
    glVertex2f(1.0f,1.0f);
    glEnd();

}
void drawParabola()
{

    glColor3f(0,1.0,0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
//    cout<<current_pos<<endl;
    for(int i = 0;i<current_pos;i++)
        glVertex2f(points[i].x,points[i].y);
    glEnd();
}

extern void timerProc(int id);  
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
//    drawArc();
 //   drawParabola();
    GLPoint o;
    o.x = 0.0f;
    o.y = 0.0f;
    float r  = 0.5f;
    drawXCircle();
    drawYCircle();
    //drawAxis();
    glFlush();
    glutSwapBuffers();
//    glutPostRedisplay();
    if(current_pos < POINTS_NUM)
    { glutTimerFunc(1000,timerProc,1); 
    }
}

void timerProc(int id)  
{  
    current_pos++;
    if(current_pos >= POINTS_NUM)
    {
        current_pos = 0;
    }
    myDisplay();
}  
void idle_func(void)
{

    current_pos++;
    if(current_pos >= POINTS_NUM)
    {
        current_pos = 0;
    }
  glutPostRedisplay();//  myDisplay();
}
void myInit()
{
    GLPoint p0;
    p0.x = initial;
    p0.y = 0.0f;

    GLPoint current = p0;

    points[0] = p0;
    GLPoint next; 
    for(int i = 1;i< POINTS_NUM;i++) {
        next = calculateNextPoint(current);
        current = next;
        points[i] = current;
    }

    //glutIdleFunc(idle_func);
//        glClearColor(0.0, 0.0, 0.0, 0.0);
//        setWindow(-4,-4,8*screenWidth/screenHeight,8);
//        GLPoint xy = calViewportXYWantScreenCentre(-4,-4,8*screenWidth/screenHeight,8,screenWidth,screenHeight,screenWidth,screenHeight);
//        glViewport(xy.x, xy.y, screenWidth, screenHeight);
}


int main(int argc, char **argv)
{
    if(argc > 1)
    {
        float dd = atof(argv[1]);
        cout<<dd<<endl;
        if(dd > 0.0f && dd < 1.0f)
        {
            factor = dd;
        }
    }
    if(argc > 2)
    {
        float dd = atof(argv[2]);
        cout<<dd<<endl;
        if(dd > 0.0f && dd < 1.0f)
        {
            initial = dd;
        }
    }
    if(argc == 1)
    {
        cout<<"输入参数试试（0.0f - 1.0f）"<<endl;
    }
     if(argc == 2)
    {
        cout<<"还可再带一个参数！"<<endl;
    }
   // if(argc > 2)
   // {
   //     int dd = atoi(argv[2]);
   //     if(dd != 0)
   //     {
   //         point_num = dd;
   //     }
   // }
 
 
        glutInit(&argc, argv);
        initWindow();
        myInit();
        glutMainLoop();
}

extern void myReshape(int width, int height) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    setWindow(-10.0f,-10.0f,20.0f*width/height,20);
    GLPoint xy = calViewportXYWantScreenCentre(0,0,1*width/height,1,width,height,width,height);
    glViewport(0, 0, width, height);

};

extern void myMouse(int button, int state, int x, int y)
{
  //      if (state == GLUT_DOWN) {
  //              if (button == GLUT_LEFT_BUTTON) {
  //                      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  //                      glClear(GL_COLOR_BUFFER_BIT);
  //                      drawAxis();
  //                      glFlush();
  //              } else if (button == GLUT_RIGHT_BUTTON) {
  //                      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  //                      glClear(GL_COLOR_BUFFER_BIT);
  //                      drawCircle();
  //                      glFlush();
  //              }
  //      }
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
