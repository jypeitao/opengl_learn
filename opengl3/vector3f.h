#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__

#include <math.h>
class Vector3f {
public:
	float x,y,z;

	Vector3f() {}

	Vector3f(const Vector3f &a) : x(a.x), y(a.y), z(a.z) {}

	Vector3f(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	Vector3f &operator =(const Vector3f &a) {
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	bool operator ==(const Vector3f &a) const {
		return x==a.x && y==a.y && z==a.z;
	}

	bool operator !=(const Vector3f &a) const {
		return x!=a.x || y!=a.y || z!=a.z;
	}

	void zero() { x = y = z = 0.0f; }

	Vector3f operator -() const { return Vector3f(-x,-y,-z); }

	Vector3f operator +(const Vector3f &a) const {
		return Vector3f(x + a.x, y + a.y, z + a.z);
	}

	Vector3f operator -(const Vector3f &a) const {
		return Vector3f(x - a.x, y - a.y, z - a.z);
	}

	Vector3f operator *(float a) const {
		return Vector3f(x*a, y*a, z*a);
	}

	Vector3f operator /(float a) const {
		float	oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
		return Vector3f(x*oneOverA, y*oneOverA, z*oneOverA);
	}

	Vector3f &operator +=(const Vector3f &a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}

	Vector3f &operator -=(const Vector3f &a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	Vector3f &operator *=(float a) {
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3f &operator /=(float a) {
		float	oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) { // check for divide-by-zero
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	float operator *(const Vector3f &a) const {
		return x*a.x + y*a.y + z*a.z;
	}
    
    void printSelf()
    {
       // cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
    void update(float x,float y,float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
};



inline float vectorMag(const Vector3f &a) {
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}


inline Vector3f crossProduct(const Vector3f &a, const Vector3f &b) {
	return Vector3f(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}

inline float vectorAngle(const Vector3f &a, const Vector3f &b) {
    double cs = a*b/(vectorMag(a)*vectorMag(b));
	float angle =  180*acos(cs)/M_PI; 
}

inline Vector3f operator *(float k, const Vector3f &v) {
	return Vector3f(k*v.x, k*v.y, k*v.z);
}

inline float distance(const Vector3f &a, const Vector3f &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

inline float distanceSquared(const Vector3f &a, const Vector3f &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return dx*dx + dy*dy + dz*dz;
}

extern const Vector3f kZeroVector;
#endif // #ifndef __VECTOR3_H_INCLUDED__
