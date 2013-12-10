#include <iostream> 
#include "interface.h"
using namespace std;
void cal_and_show()
{

}
int main()
{
    float x,y,z;


    cout<<"*****************************************************"<<endl;
    cout<<"  Vector normalizationi:                "<<endl;

    Vector3f v;
    
    v.update(1,-2,0.5);
    v.normalize();
    cout<<"       (1,-2,0.5) -> ("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;

    v.update(8,6,0);
    v.normalize();
    cout<<"       (8,6) -> ("<<v.x<<","<<v.y<<")"<<endl;

    v.update(4,3,0);
    v.normalize();
    cout<<"       (4,3) -> ("<<v.x<<","<<v.y<<")"<<endl;

    cout<<endl;
    cout<<"  angle[0,360):                "<<endl;
    Vector3f a,b;
    a.update(2,3,0);
    //a.normalize();
    b.update(-3,1,0);
    //b.normalize();
    cout<<"       (2,3) (-3,1) = "<<vectorAngle(a,b)<<endl;

    a.update(1,3,-2);
    b.update(3,3,1);
    cout<<"       (1,3,-2) (3,3,1) = "<<vectorAngle(a,b)<<endl;


    cout<<"*****************************************************"<<endl;
    return 0;
}
