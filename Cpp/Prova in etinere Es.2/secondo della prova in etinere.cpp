/* Scrivere   un   metodo   che   prenda   in   input   una   matrice  V  di   stringhe  contenente   
verbi   italiani all’infinito, e restituisca la percentuale dei verbi della prima coniugazione.*/ 

#include <iostream>
#include <string>
#define n 3
#define m 2

using namespace std;

double func (string**V){
	
	int count = 0;
	string coniug;
	double percentuale ;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			coniug = V[i][j].substr(V[i][j].length()-3,3);
			if (coniug == "are"){
				count ++;
			}
		}
	}
	
	percentuale = (count * 100)/(n*m);
	return percentuale;
	
}

int main ()
{
	
	string **V = new string* [n];  //alloco dinamicamente l'array esterno
	
	for(int i=0; i<n; i++){
		V[i] = new string [m];  //alloco dinamicamente l'array interno come di consuetudine
		
		for(int j=0; j<m; j++){
			cout<<"Inserisci un verbo italiano all'infinito : "<<endl;
		    cin>> V[i][j] ;
		}
	}   
	
	double percentuale = func (V);
	cout<<"\nIl "<<percentuale<<" % dei verbi inseriti , sono verbi della prima coniugazione"<<endl;

}