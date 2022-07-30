#include <iostream>
using namespace std;

class punto2D{
	private:
		double x = 2;
		double y = 3;
		
	public: punto2D (double x, double y){
		this->x = x;
		this->y = y;
	}
	
	double get_ascissa (){
		return x;
	}
	
	double get_ordinata (){
		return y;
	}
	
	void stampa(){
		cout<<"Punto:"<<"( "<<x<<" : "<<y<<" )"<<endl;
	}
};
