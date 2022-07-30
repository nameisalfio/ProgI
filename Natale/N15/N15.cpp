/* 15.Scrivere un metodo che prenda in input tre matrici 
A, B e C di boolean con le stesse dimensioni, e 
restituisca un boolean che indichi se una diagonale in 
A, soprastante la diagonale principale, è presente 
anche in B e C (nella stessa posizione e con la stessa 
sequenza di valori!).*/

#include <iostream>
using namespace std;
#define n 3

bool func(bool**A, bool**B, bool**C){
	
	cout<<"Matrice A : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<" "<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Matrice B : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<" "<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Matrice C : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<" "<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int o=1; o<n; o++){
		for(int i=0; i<n-o; i++){
			if(!(A[i][i+o] == B[i][i+o] == C[i][i+o]))
				return false;
		}
	}
	
	return true;
	
}

main(){
	
	bool**A = new bool *[n];
	for(int i=0; i<n; i++){
		A[i] = new bool [n];
		for(int j=0; j<n; j++){
//			cout<<"Inserisci dei bool nella matrice A: "<<endl;
//			cin>>A[i][j];
            A[i][j] = 1;
		}
	}
	cout<<endl;
	bool**B = new bool *[n];
	for(int i=0; i<n; i++){
		B[i] = new bool [n];
		for(int j=0; j<n; j++){
//			cout<<"Inserisci dei bool nella matrice B: "<<endl;
//			cin>>B[i][j];
			B[i][j] = 1;
		}
	}
	cout<<endl;
	bool**C = new bool *[n];
	for(int i=0; i<n; i++){
		C[i] = new bool [n];
		for(int j=0; j<n; j++){
//			cout<<"Inserisci dei bool nella matrice C: "<<endl;
//			cin>>C[i][j];
			C[i][j] = 1;
		}
	}
	
	bool esito = func (A, B, C);
	
	if (esito == true){
		cout<<"\nI valori coincidono"<<endl;
	}else{
		cout<<"\nI valori non coincidono"<<endl;
	}
}