/* 10.Scrivere un metodo che prenda in input tre 
parametri formali: una matrice di puntatori a stringhe 
A di dimensioni nxm, uno short k ed una stringa s. Il 
metodo restituisca un array di bool di dimensione n in 
cui il singolo elemento di indice i assume valore true se 
la stringa s è sottostringa di almeno k stringhe della 
riga i-esima della matrice A. */

#include <iostream>
#include <string>
#define n 3
#define m 3

using namespace std;

bool *func (string***A, short k, string s){

	bool*vet = new bool [n];
	int count = 0;
	
	cout<<"La matrice inserita : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<*A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((*A[i][j]).find(s) != string :: npos){
				count ++;
			}
		}
		if(count >= k){
			vet[i] = true;
		}else{
			vet[i] = false;
		}
		count = 0;
	}
	return vet;
}

int main(){
	
	short k = 2;
	
	string s = "Hello";
	
	string***A = new string **[n];
	for(int i=0; i<n; i++){
		
		A[i] = new string *[m];
		for(int j=0; j<m; j++){
			A[i][j] = new string;
			cout<<"Inserisci un elemento nella matrice : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	bool *vet = func(A, k, s);
	cout<<"L'array di bool : "<<endl;
	for(int i=0; i<n; i++){
		cout<<vet[i]<<" ";
	}
	
	delete []vet;
}