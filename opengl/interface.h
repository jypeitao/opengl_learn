#ifndef INTERFACE_H
#define INTERFACE_H
#define LINUX
#ifdef LINUX
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else 
#include <GLUT/glut.h>
#endif
#include <math.h>
#include <iostream>

using namespace std;
extern void myDisplay(void);
extern void myReshape(int width, int height);
extern void myMouse(int button, int state, int x, int y);
extern void myMovedMouse(int x, int y);
extern void myPassiveMotion(int x, int y);
extern void myKeyboard(unsigned char key, int x, int y);
extern void myInit(void);
extern void drawDot(GLint x, GLint y);

struct GLPoint
{
    GLfloat x, y;
};

struct GLintPoint
{
    GLint x, y;
};

class Point3 {
public:
    float x,y,z;
    void asString()
    {
        std::cout<<"x="<<x<<" y="<<y<<" z="<<z<<std::endl;
    }
    void set(float dx, float dy, float dz) {
        x=dx;
        y=dy;
        z=dz;
    }
    void set(Point3 &p) {
        x=p.x;
        y=p.y;
        z=p.z;
    }
    Point3(float xx, float yy, float zz) {
        x=xx;
        y=yy;
        z=zz;
    }
    Point3() {
        x=y=z=0;
    }
    void build4tuple(float v[])
    {
        v[0]=x;
        v[1]=y;
        v[2]=z;
        v[3]=1.0f;
    }
};

class Vector3 {
public:
    float x,y,z;
    void asString()
    {
        cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
    }
    void set(float dx, float dy, float dz) {
        x=dx;
        y=dy;
        z=dz;
    }
    void set(Vector3 &v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    void flip() {
        x=-x;
        y=-y;
        z=-z;
    }
    void setDiff(Point3&a, Point3 &b)
    {
        x=a.x-b.x;
        y=a.y-b.y;
        z=a.z-b.z;
    }
    void normalize()
    {
        x=x/sqrt((x*x+y*y+z*z));
        y=y/sqrt((x*x+y*y+z*z));
        z=z/sqrt((x*x+y*y+z*z));
    };
    Vector3(float xx, float yy, float zz)
    {
        x=xx;
        y=yy;
        z=zz;
    }
    Vector3(Vector3 &v)
    {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    Vector3() {
        x=y=z=0;
    }
    Vector3& cross(Vector3 b)
    {
        Vector3 ret;
        ret.x=y*b.z-z*b.y;
        ret.y=z*b.x-x*b.z;
        ret.z=x*b.y-y*b.x;
        return ret;
    };
    float dot(Vector3 b)
    {
        float ret;
        ret=x*b.x+y*b.y+z*b.z;
        return ret;
    };
};

typedef struct GLPoint GLPOINT;
typedef struct GLintPoint GLINTPOINT;

static const int screenWidth = 640;
static const int screenHeight = 480;
static const double PI=3.14159265;
#endif 
