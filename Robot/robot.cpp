#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <tuple>

#define EPS 1e-6
#define TO_RAD (M_PI)/180.0
#define TO_DEG 180.0/(M_PI)

typedef std::tuple<double,double> Pose;
typedef std::tuple<double, double, double> Theta;
typedef std::tuple<double, double, double, double> Arm;

Pose forward_kinematic(Arm l, Theta theta){

double l0 = std::get<0>(l);
double l1 = std::get<1>(l);
double l2 = std::get<2>(l);
double l3 = std::get<3>(l);

double theta0 = std::get<0>(theta);
double theta1 = std::get<1>(theta);
double theta2 = std::get<2>(theta); 

double x = l1 * std::sin(theta0) + l2 * std::sin(theta0+theta1) + l3 * std::sin(theta2); 
double y = l0 + l1 * std::cos(theta0) + l2 * std::cos(theta0+theta1) + l3 * std::cos(theta2);

return {x,y};


}

int main() {

int T;
std::cin >> T;

while(T--){

    int l[4];
    double theta[3];
    double denum, num;

    for(int i = 0; i < 4; i++)
    {
        int temp;
        std::cin >> temp;
        l[i] = temp;
     }
    
    Arm arm = {l[0], l[1], l[2], l[3]};
    int x, y, phi;    
    std::cin >> x >> y >> phi;
    bool found = false;
    for(double i = -359; i < 360; i++){
	for(double j = -359; j < 360; j++){
	   double temp1 = (i*TO_RAD);
           double temp2 = (j*TO_RAD);
           double temp3 = (phi*TO_RAD);
           if(std::isnan(temp1) || std::isnan(temp2)) continue;
           Theta temp = {temp1, temp2, temp3};
           Pose res = forward_kinematic(arm, temp);
           auto X = std::get<0>(res);
           auto Y = std::get<1>(res);
           if(std::isnan(X) || std::isnan(Y)) continue;
           if((std::abs(x-X) < EPS) && (std::abs(y-Y) < EPS)){
               theta[0] = temp1;
               theta[1] = temp2;
               theta[2] = temp3 - (temp1+temp2);
               if(theta[2]*TO_DEG > 360) continue;
               else if(theta[2]*TO_DEG < -360) continue;
	       else{
                  found = true;
                  break;
               }   
           } 
	}
        if(found) break;
    }

    for(int i = 0; i < 3; i++)
        theta[i] *= TO_DEG;

    std::cout << std::setprecision(8) << theta[0] << ' ' << theta[1] << ' ' << theta[2] << std::endl;

}

}
