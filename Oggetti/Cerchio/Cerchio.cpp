/*Si costruisca una classe Cerchio che metta a disposizione 
 metodi per calcolare il perimetro e l’area.
 Si costruisca una classe Rectangle che metta a disposizione metodi
 per calcolare perimetro e area. Si modifichi la classe Cicle (si veda 
 l’esercizio precedente) inserendo un metodo encloses che prende in input un 
 oggetto di classe Rectangle e restituisce true se il rettanglo è completamente 
 contenuto all’interno del cerchio.*/

#include <iostream>
#include "rettangolo.h"
using namespace std;

class cerchio {
	private:
		double raggio;
		const double pi=3.14;
		
	public:
		cerchio (double r){
			raggio = r;
		}
		
		double perimetro(){
			return 2*pi*raggio;
		}
		//p=2*p*r
		
		double area(){
			return raggio*raggio*pi;
		}
		//a=r*r*p
		
		bool encloses(rettangolo x){
			cerchio c(5.8);
			
			if(c.area()>=x.area())
			return true;
			else
			return false;
		}
};

int main(){
	
	cout<<"Cerchio"<<endl;
	cerchio c(3.8);
	cout<<"Area:"<<c.area()<<endl;
	cout<<"Perimetro:"<<c.perimetro()<<endl;
	
	cout<<endl;
	
	cout<<"Rettangolo"<<endl;
	rettangolo x(2.4, 2.8);
	cout<<"Area:"<<x.area()<<endl;
	cout<<"Perimetro:"<<x.perimetro()<<endl<<endl;
	
	if(c.encloses(x))
	cout<<"Rettangolo completamente incluso"<<endl;
	else
	cout<<"Rettangolo non incluso"<<endl;
}