/* 11.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori ad int 
e restituisca in output un bool che indichi se la somma 
degli elementi puntati dalla diagonale sottostante la 
diagonale secondaria è divisibile per n. */

#include <iostream>
#define n 4

using namespace std;

bool func (int***A){
	
	int somma = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i+j == n){
				somma += *A[i][j];
			}
		}
	}
	if(somma % n == 0){
		return true;
	}else{
		return false;
	}
}

int main (){
	
	int***A = new int **[n];
	for(int i=0; i<n; i++){
		
		A[i] = new int *[n];
		for(int j=0; j<n; j++){
			
			A[i][j] = new int ;
			cout<<"Inserisci un valore nella matrice : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	bool esito = func(A);
	
	if(esito == 1){
		cout<<"\nLa somma e' divisibile per "<<n<<endl;
	}else{
		cout<<"\nLa somma non e' divisibile per "<<n<<endl;
	}
	
}