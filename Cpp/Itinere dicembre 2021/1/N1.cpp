/* Scrivere un metodo in C++ che prenda in input come parametri formali una matrice 
di puntatori ad interi M di dimensioni nxm, un double z ed uno short k (si assuma k<n).
Il metodo restituisca il numero di colonne che contengono almeno k elementi contigui
la cui media aritmetica sia minore o uguale a z. */

#include <iostream>
using namespace std;
#define n 4
#define m 3

int fun(int ***M,  double z, short k){
	int col = 0;
	double s = 0;
	int count = 0;
	for(int j = 0; j<m; j++){
		for(int i = 0; i<n; i++){
			if(M[i][j]){
				s+=(*M[i][j]);
				s /= 2;
				count++;
				if(count>=k && s<=z){
					col++;
					break;
				}
			}else{
				count = 0;
				s = 0;
			}
		}	
	}
	
return col;
}


int main(){
	
	double z = 10;
	
	short k = 2;
	
	int***M = new int **[n];
	for(int i=0; i<n; i++){
		M[i] = new int *[m];
		for(int j=0; j<m; j++){
			M[i][j] = new int;
			cout<<"Inserisci un valore nella matrice "<<endl;
			cin>>*M[i][j];
		}
	}
	
	int ncol = fun(M, z, k);
	cout<<"Il numero di colonne che soddisfano il requisito e' "<<ncol<<endl;
	
}
