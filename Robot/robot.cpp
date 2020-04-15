

/* NOT FINISHED YET BUILD ERROR */

#include <iostream>
#include <vector>

#define EPS 1e-6
#define H 0.01

struct Pos2D
{
    double x;
    double y;
    
    Pos2D(double x=0, double y=0) 
        : x(x), y(y)
    {
    }

    Pos2D& operator=(const Pos2D& target)
    {
        x=target.x;
        y=target.y;
        return *this;
    }

    Pos2D operator+(const Pos2D& target) const
    {
        return Pos2D(a.x+x, a.y+y);
    }

    bool operator==(const Pos2D& target) const
    {
        return (x == target.x && y == target.y);
    }
};

Pos2D robot;
Pos2D target;

template<typename T>
std::vector<std::vector<T>> getJacobianTranspose(){

	auto J_A = cross(rotA, robot - jointA);
	auto J_B = cross(rotB, robot - jointB);
	auto J_C = cross(rotC, robot - jointC);
	
	Matrix J;
	//J
	
	return J.transpose();
}

template<typename T>
std::vector<T> getDeltaOrientation(){
	
	auto jt = getJacobianTranspose();
	auto V = target - robot;
	auto dO = jt * V;
	return dO
	
}

template<typename T>
std::vector<T> JacobianIK(T O){
	
	while(abs(robot - target) > EPS){
		
		dO = getDeltaOrientation();
		O += dO * H;
		
	}
	
	return O;
	
}

int main() {

}
