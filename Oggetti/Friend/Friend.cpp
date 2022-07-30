#include<iostream>
#include<cmath>
using namespace std;

class Point2D {
    private:
        double x, y;
    public:
        Point2D() : x(0), y(0) {}
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() const {return x;}
        double getY() const {return y;}
        void setX(double _x) {x= _x;}
        void setY(double _y) {y= _y;}
        friend void normalize(Point2D &p);
};
 
void normalize(Point2D &p) {
   double mod = sqrt(p.x*p.x + p.y*p.y);
   p.x/=mod;
   p.y/=mod;
}

/*void normalize(Point2D &p) {
//    double mod = sqrt(p.x*p.x + p.y*p.y);
   double mod = sqrt(p.getX()*p.getX() + p.getY()*p.getY());
//    p.x/=mod;
//    p.y/=mod;
    p.setX(p.getX()/mod);
    p.setY(p.getY()/mod);
}*/

int main(){
	Point2D p1(2.2,4.3);
cout << "("<< p1.getX() << ", " << p1.getY() << ")"<< endl;

normalize(p1);
cout << "("<< p1.getX() << ", " << p1.getY() << ")"<< endl;
}