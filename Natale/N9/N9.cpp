/* 9.Scrivere un metodo che prenda in input un 
parametro formale matrice A di interi di dimensioni 
nxn ed un double w, e restituisca un valore booleano 
true se esiste almeno una colonna della matrice A per 
cui il rapporto tra la somma degli elementi della 
colonna stessa e la somma degli elementi della 
diagonale principale di A sia maggiore di w.
*/

#include <iostream>
#define n 3

using namespace std;

bool func (int **A, double w){
	
	bool esito = false;
	int sommad = 0;
	int sommac = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				sommad += A[i][j];
			}
		}
	}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			sommac += A[i][j];
			if(sommac/sommad >= w){
				esito = true;
			}
		}
		sommac = 0;
	}
	return esito;
}

int main(){
	double w = 3.3;
	
	int **A = new int *[n];
	for(int i=0; i<n; i++){
		A[i] = new int [n];
		for(int j=0; j<n; j++){
			cout<<"Inserisci un valore nella matrice : "<<endl;
			cin>>A[i][j];
		}
	}
	
	bool esito = func (A, w);
	
	cout<<"Esito : "<<esito<<endl;
}