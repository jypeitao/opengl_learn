#include "interface.h"
#include "publicfuncs.h"

#define POINTS_NUM 17 
#define RADIUS 2.0f
int point_num = 17;
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
void creatGarlandPoints(GLPoint points[],int points_length,float radius)
{
    GLfloat angle = 2.0f*PI/points_length;
    for(int i = 0; i < points_length; i++)
    {
        points[i].x = radius*cos(angle*i);
        points[i].y = radius*sin(angle*i);
    }

}
void drawLine(GLPoint begin, GLPoint end)
{
    glColor3f(0,1.0,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(begin.x,begin.y);
    glVertex2f(end.x,end.y);
    glEnd();
}
void drawGarland(int N,float radius)
{
        glColor3f(0,1.0,0);
        glLineWidth(8);
        glPointSize(2);
        GLPoint points[N];
        creatGarlandPoints(points,N,radius);
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                drawLine(points[i],points[j]);
            }
        }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGarland(point_num,RADIUS);
    glFlush();
    glutSwapBuffers();
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
    if(argc > 1)
    {
        int dd = atoi(argv[1]);
        if(dd != 0)
        {
            point_num = dd;
        }
    }
    glutInit(&argc, argv);
    initWindow();
    myInit();
    glutMainLoop();
}

extern void myReshape(int width, int height) {
    //cout<<sizeof(points)<<endl;
    //creatGarlandPoints(points,4);
#define as 1.25f
    glClearColor(0.0, 0.0, 0.0, 0.0);
    setWindow(-RADIUS,-RADIUS,2*RADIUS*as,2*RADIUS);
    GLPoint xy = calViewportXYWantScreenCentre(-2,-2,4*as,4,height*as,height,width,height);
    glViewport(xy.x, xy.y, height*as,height);

};
extern void myMouse(int button, int state, int x, int y) {
        if (state == GLUT_DOWN) {
                if (button == GLUT_LEFT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                //        drawAxis();
                        glFlush();
                } else if (button == GLUT_RIGHT_BUTTON) {
                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        glClear(GL_COLOR_BUFFER_BIT);
                 //       drawCircle();
                        glFlush();
                }
        }
}

extern void myKeyboard(unsigned char key, int x, int y) {};

extern void myMovedMouse(int x, int y) {};

extern void myPassiveMotion(int x, int y) {};
extern void myMouseWheel(int button, int dir, int x, int y) {};
