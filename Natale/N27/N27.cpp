/*27.Scrivere un metodo che prenda come parametro 
formale una matrice A n×m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti).*/

#include <iostream>
#define n 3
#define m 2
using namespace std;

bool func(int***A){
	
	cout<<"Matrice di indirizzi:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			if(A[i][j] == A[i+1][j])
			return true;
		}
	}
	
	return false;
}

int main(){
	
	int***A = new int**[n];
	for(int i=0; i<n; i++){
		A[i] = new int*[m];
		for(int j=0; j<m; j++){
			A[i][j] = new int;
//			A[i][j] = nullptr;
		}
	}
	
	bool esito = func (A);
	if(esito)
	cout<<"\nVero";
	if(!esito)
	cout<<"\nFalso";
	
}