#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

#include "punto2D.h"

class scatter{
	private:
		int n = 5;
		punto2D **vet = new punto2D*[n];
		
	public:
		scatter(int n){
			this->n = n;
			srand(time(NULL)); //Imposto il seed
			double x = -2.2+(rand()/(double)RAND_MAX)*4.4;//Numeri random da -2.2 a 2.2
		    double y = -2.2+(rand()/(double)RAND_MAX)*4.4;//....
		    
		    for(int i=0; i<n; i++)
		    vet[i] = new punto2D(i, i);
		    
		    for(int i=0; i<floor(n/2); i++)
		    vet[i] = new punto2D(x, y);
	    }
	    
	    void stampa_scatter(){
	    	for(int i=0; i<n; i++)
	    	vet[i]->stampa();
		}
		
		punto2D *estrai (int i){
			punto2D *A = vet[i];
			vet[i] = nullptr;
			return A;
		}
		
		void inserisci(punto2D p){
			for(int i=0; i<n; i++){
				if(vet[i]==nullptr)
				*vet[i] = p;
//				vet[i]->stampa();
			}
		}
		
		int conta(){
			int count = 0;
			for(int i=0; i<n; i++){
				if(vet[i] != nullptr){
					count ++;
				}else{
					cout<<"\nL'elemento all'indice "<<i<<" e' un nullptr"<<endl;
				}
			}
			return count;
		}
		
	    punto2D *centroide(){
			double x;
			double y;
			
			for(int i=0; i<n-1; i++){
//				x = (vet[i]->get_ascissa() + vet[i+1]->get_ascissa()) / 2;
//				y = (vet[i]->get_ordinata() + vet[i+1]->get_ordinata()) / 2;
//               cout<<"Ascissa: "<<vet[i]->get_ascissa()<<endl;
//               cout<<"Ordinata: "<<vet[i]->get_ordinata()<<endl;
               vet[i]->stampa();
			}
			
			punto2D A(x, y);  //Punto medio
			A.stampa();
			punto2D* M = &A;
			return M;
		}
		    
};

int main(){
	int n = 7;

	scatter x(n);
	cout<<"x :"<<endl;
	x.stampa_scatter();
	
	scatter y(n);
	cout<<"y :"<<endl;
	y.stampa_scatter();
    
    int i=2;
    cout<<"\nIl puntatore all'elemento di indice "<<i<<" e' :"<< x.estrai(i)<<endl;

	punto2D p(3.8, 5.3);
//  x.inserisci(p);
    cout<<"\nNumero di elementi diversi da nullpointer: "<<x.conta()<<endl;
    
//  cout<<"\nIl punto medio tra tutti i punti nell'array e' :"<< x.centroide() <<endl;
    cout<<"Puntatore al medio: "<<endl;
	x.centroide();

//Esercizio 
//    int n = 100;
//    scatter e(n);
//    
//    for(int i=0; i<n; i++){
//    	punto2D *ptr = e.centroide();
//    	e.inserisci(*ptr);
//    	ptr->stampa();
//	}	
	
}