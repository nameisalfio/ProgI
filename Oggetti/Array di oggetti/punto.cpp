#include<cmath>
#include<iostream>
using namespace std;
class Punto2D {
    double x, y;
    public:
        Punto2D(double _x, double _y): x(_x), y(_y) {}
        double distanzaDalCentro() {return sqrt(x*x+y*y);}
        void stampa() {cout << "("<<x<<","<<y<<")"<<endl;}
};

int main(){
	Punto2D p(2, 3);
	p.stampa();
	cout<<endl;
	
	Punto2D punti[3] = {Punto2D(2,3),Punto2D(4,5),Punto2D(7,7)};
    for (int i=0; i<3; i++)
    punti[i].stampa();
    cout<<endl;
    
    //IN MANIERA EQUIVALENTE
    Punto2D punt[3] = {{2,3},{4,5},{7,7}};
    for (int i=0; i<3; i++)
    punt[i].stampa();
    cout<<endl;
    
    
    //ALLOCAZIONE DINAMICA DI OGGETTI
    Punto2D *point[3];
    
    for(int i=0; i<3; i++)
    point[i] = new Punto2D(i,i+1);
    
    for(int i=0; i<3; i++)
    point[i]->stampa();
}