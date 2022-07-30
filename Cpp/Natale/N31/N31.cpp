/*31.Scrivere un metodo che prenda in input una 
matrice M di puntatori a double di dimensione n × m e 
due interi a e b e restituisca un array unidimensionale 
di booleani di lunghezza 2m tale che l’elemento 
dell’array di posizione 2i contiene True se e solo se la 
media dei soli elementi della colonna i-esima di M 
compresi tra a e b(estremi inclusi) è maggiore di 
(a+b)/2. Gli elementi dell’array di indice dispari devono 
essere inizializzati a False.
NB: Si presti attenzione ai numeri mancanti!*/

#include <iostream>
#define n 3
#define m 2
using namespace std;

bool* func(double***M, int a, int b){
	bool *vet = new bool [2*m];
	for(int i=0; i<2*m; i++){
		vet[i] = false;
	}
	
	double somma;
	
	cout<<"La matrice : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<" "<<*M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int j=0; j<m; j++){
		somma=0;
		for(int i=0; i<n; i++){
			if(*M[i][j]>=a && *M[i][j]<=b){
				somma += *M[i][j];
				somma/=2;
			}
		}
		if(somma > (double)(a+b)/2)
		vet[2*j] = true;

	}
	
	return vet;
}

 int main(){
 	int a=5;
 	int b=10;
 	double***M = new double**[n];
 	for(int i=0; i<n; i++){
 		M[i] = new double *[m];
 		for(int j=0; j<m; j++){
 			M[i][j] = new double;
 			cout<<"Inserisci double"<<endl;
 			cin>>*M[i][j];
		 }
	}
 	
 	bool*vet = func(M, a, b);
 	cout<<"Il vettore : "<<endl;
 	for(int i=0; i<2*m; i++){
 		cout<<vet[i]<<" ";
	 }
 }