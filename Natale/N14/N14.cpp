/* 14.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed un intero k, e 
restituisca in output una copia di A in cui tutte le 
stringhe della colonna k-esima siano state epurate 
dalle lettere non italiane. */

#include <iostream>
#include <string>
#define n 3

using namespace std;

string **func (string**A, int k){
	
	cout<<"\nMatrice inserita : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	string **B = new string *[n];
	for(int i=0; i<n; i++){
		B[i] = new string [n];
		for(int j=0; j<n; j++){
			B[i][j] == A[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<B[i][j].length();j++){
			if((B[i][k])[j] == 'j'||
			   (B[i][k])[j] == 'k'||
			   (B[i][k])[j] == 'w'||
			   (B[i][k])[j] == 'x'||
			   (B[i][k])[j] == 'y'  ){
			   	(B[i][k])[j] = NULL;
			   }
		}
	}
	return B;
}

int main (){
	
	int k = 1;
	
	string **A = new string *[n];
	for(int i=0; i<n; i++){
		A[i] = new string [n];
		for(int j=0; j<n; j++){
			cout<<"Inserisci una stringa : "<<endl;
			cin>>A[i][j];
		}
	}
	
	string **C = func (A, k);
	
	cout<<"\nMatrice modificata : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
}