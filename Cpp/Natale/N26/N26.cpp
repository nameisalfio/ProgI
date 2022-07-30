/* 26.Scrivere un metodo che prenda in input una 
matrice quadrata Q di dimensioni n x n di puntatori a 
stringhe e due short m e k e restituisca il valore 
booleano true se la diagonale secondaria di Q contiene
almeno m stringhe con un numero di vocali minore o 
uguale a k. NB: Si assuma m<=n. */

#include <iostream>
#include <string>
using namespace std;

bool func(string***Q, int n, short m, short k){
	int vocali;
	int stringhe;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			vocali = 0;
			for(int k=0; k<n; k++){
				if(i+j == n-1){
					if((*Q[i][j])[k] == 'a' || (*Q[i][j])[k] == 'A' ||
				       (*Q[i][j])[k] == 'e' || (*Q[i][j])[k] == 'E' ||
			           (*Q[i][j])[k] == 'i' || (*Q[i][j])[k] == 'I' ||
				       (*Q[i][j])[k] == 'o' || (*Q[i][j])[k] == 'O' ||
				       (*Q[i][j])[k] == 'u' || (*Q[i][j])[k] == 'U'   ){
				   	    vocali++;
				    }
					if(vocali<=k)
				    stringhe++;
				}
			}
		}
	}
	
	if(stringhe >= m)
	return true;
	else
	return false;
}

int main(){
	int n=3;
	short m=2;
	short k=3;
	string ***Q = new string **[n];
	for(int i=0; i<n; i++){
		Q[i] = new string*[n];
		for(int j=0; j<n; j++){
			Q[i][j] = new string;
			cout<<"Inserisci stringa : "<<endl;
			cin>>*Q[i][j];
		}
	}
	
	bool esito = func(Q, n, m, k);
	if(esito)
	cout<<"\nVero"<<endl;
	if(!esito)
	cout<<"\nFalso"<<endl;
}