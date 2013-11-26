#include "publicfuncs.h"
#include "interface.h"
#include<fstream>
#include<string>
#include<vector>

void initWindow(void)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("my first attempt");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutMotionFunc(myMovedMouse);
    glutPassiveMotionFunc(myPassiveMotion);
}

void drawDot(GLfloat x, GLfloat y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void readDataFromFile(char fileName[],vector<int>& v)
{
    fstream inStream;
    v.clear();
    inStream.open(fileName,ios::in);
    if(inStream.fail()) 
    {
        return;
    }
    int t = 0;
    int sum1 = 0;//总折线数
    int sum2 = 0;//折线点数
    inStream >> sum1;
    v.push_back(sum1);
    for(int i = 0; i < sum1; i++)
    {
        inStream >> sum2;
        v.push_back(sum2);
        for(int j = 0; j < sum2; j++)
        {

            inStream >> t;
            v.push_back(t);
            inStream >> t;
            v.push_back(t);
        }
    }
    inStream.close();
}
void drawPolyLineFile(char fileName[])
{
    vector<int> v;
    readDataFromFile(fileName,v);
    
    int index = 0;//index < v.size()
    int t = 0;
    int sum1 = v[index++];//总折线数
    int sum2 = 0;//折线点数
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    glLineWidth(2);
    for(int i = 0; i < sum1; i++)
    {
        sum2 = v[index++];

        glBegin(GL_LINE_STRIP);
        for(int j = 0; j < sum2; j++)
        {
            glVertex2i(v[index++],v[index++]);
        }
        glEnd();
    }
    glFlush();

}
