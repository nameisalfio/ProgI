/* 13.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori a char 
e restituisca in output un bool che indichi se esiste una 
colonna in A identica alla diagonale principale di A. */

#include <iostream>
#define n 3
using namespace std;

bool func (char***A){
	bool esito;
	int count = 0;
	
	cout<<"Matrice inserita : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<*A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\nDiagonale principale : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
			    cout<<*A[i][j]<<" ";	
			}
		}
	}

	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(*A[i][i] == *A[i][j]){
				count ++;
			}
			if(count == n){
		        esito = true;
	        }else{
		        esito = false;
        	}
		}
		count = 0;
	}
		
	cout<<"\nEsito : "<<esito<<endl;
	return esito ;
}

int main(){
	
	char***A = new char **[n];
	for(int i=0; i<n; i++){
		
		A[i] = new char *[n];
		for(int j=0; j<n; j++){
			
			A[i][j] = new char ;
			cout<<"Inserisci un carattere : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	bool esito = func (A);
	if(esito){
		cout<<"\nC'e' una colonna identica alla diagonale principale"<<endl;
	}else{
		cout<<"\nNon c'e' una colonna identica alla diagonale principale"<<endl;
	}
}