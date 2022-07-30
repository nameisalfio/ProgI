/* 17.Scrivere un metodo che prenda in input una 
matrice A di numeri interi e due double w e v, e 
restituisca il valore booleano true se esiste almeno una 
colonna di A in cui la media dei suoi elementi e 
compresa tra w e v. NB: Si assuma che w <=v. */

#include <iostream>
#define n 3

using namespace std;

bool func (int**A, double w, double v){
	int somma = 0;
	float media;
	
	cout<<"Matrice : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			somma += A[i][j];  //somma parziale
		}
		media = somma/n;
        somma = 0;
		
		if (media>=w && media<=v){
			return true;
		}
	}
	
}

int main(){
	
	double w = 0.5;
	double v = 1.2;
	
	int **A = new int *[n];
	for(int i=0; i<n; i++){
		A[i] = new int [n];
		for(int j=0; j<n; j++){
			cout<<"Inserisci valore : "<<endl;
			cin>>A[i][j];
		}
	}
	
	bool risposta = func(A, w, v);
	
	if (risposta == true ){
		cout<<"\nEsiste una colonna che rispetta la condizione data"<<endl;
	}else if (risposta == false){
		cout<<"\nNon esiste nemmeno una colonna che rispetta la condizione data"<<endl;
	}
}