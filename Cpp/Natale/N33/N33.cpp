/*33.Scrivere un metodo che prenda in input una 
matrice quadrata A di puntatori ad interi e restituisca 
un double calcolato come il rapporto tra la somma 
degli elementi della diagonale principale di A e la 
somma degli elementi della diagonale secondaria di A 
stessa. 
NB: Si presti attenzione ai numeri mancanti!*/

#include <iostream>
using namespace std;

double func(int***A, int n){
	float dp=0;
	float ds=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				if(A[i][j]){
					dp += *A[i][j];
				}
			}
			if(i+j==n-1){
				if(A[i][j]){
					ds += *A[i][j];
				}
			}
		}
	}
	
	cout<<"Somma dp "<<dp<<endl;
	cout<<"Somma ds "<<ds<<endl;
	return dp/ds;
}

int main(){
	int n=3;
	
	int***A = new int**[n];
	for(int i=0; i<n; i++){
		A[i] = new int*[n];
		for(int j=0; j<n; j++){
			A[i][j] = new int;
			cout<<"Inserisci intero : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	double rapporto = func(A, n);
	cout<<"Il rapporto : "<<rapporto<<endl;
}