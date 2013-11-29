#include "publicfuncs.h"
#include "interface.h"

void initWindow(void)
{
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
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

void setWindow(GLdouble left, GLdouble bottom, GLdouble width, GLdouble height)
{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(left, left+width, bottom, bottom+height);
}

void setViewport(GLdouble left, GLdouble bottom, GLdouble width, GLdouble height)
{
        glViewport(left, bottom, width, height);
}

GLPoint funcpoints[FUNCPOINT_N];

void createFuncPoints(FUNC func, float startx, float endx)
{
        for (int i=0; i<FUNCPOINT_N; i++) {
                funcpoints[i].x=startx+(endx-startx)*i/FUNCPOINT_N;
                funcpoints[i].y=(*func)(funcpoints[i].x);
                cout<<"("<<funcpoints[i].x<<","<<funcpoints[i].y<<")"<<endl;
        }
}

void drawPolyLineFile(const char * fileName)
{

        std::ifstream inStream;
        inStream.open(fileName);        // open the file
        if(inStream.fail())
                return;
        glClear(GL_COLOR_BUFFER_BIT);
        GLint numpolys, numLines, x ,y;
        inStream >> numpolys;
        //read the number of polylines
        for(int j = 0; j < numpolys; j++) { //read each polyline
                inStream >> numLines;
                glBegin(GL_LINE_STRIP);
                //draw the next polyline
                for (int i = 0; i < numLines; i++) {
                        inStream >> x >> y;
                        //read the next x, y pair
                        glVertex2i(x, y);
                        //cout<<x<<","<<y<<endl;
                }
                glEnd();
        }
        glFlush();
        inStream.close();
}
GLPoint calViewportXYWantScreenCentre(GLdouble wl, GLdouble wb, GLdouble ww, GLdouble wh, GLdouble vw, GLdouble vh, GLdouble gw, GLdouble gh)
{
    GLdouble x = 0;
    GLdouble y = 0;
    GLPoint point;
    point.x =  (gw - vw)/2.0f + vw*(wl+wl+ww)/(2.0f*ww);

    point.y =  (gh - vh)/2.0f + vh*(wb+wb+wh)/(2.0f*wh);
    return point;
}
