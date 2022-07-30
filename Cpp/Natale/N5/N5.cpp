/* 5.Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x. */

#include <iostream>
#define n 2
#define m 3

using namespace std;

int func (long A[n][m], long x){
	
	int index;
	int countm = 0, count = 0;

	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			cout<<"Inserisci valore nella matrice : "<<endl;
			cin>>A[i][j];
		}
	}
	
	cout<<"Matrice : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<" "<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(A[i][j] == x){
				count++;  
				if(count>countm){
					countm = count;
					index = j;
				}
			}
		}
		count = 0;
	}
	cout<<"count : "<<count<<endl;
	cout<<"countm : "<<countm<<endl;
	
return index;			
}

int main(){
	long x = 2;
	
	long A [n][m];
	
	int index = func (A, x);
	cout<<"Indice con piu' occorrenze : "<<index<<endl;
	
}