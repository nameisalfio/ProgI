/* 18.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe M e due numeri short 
senza segno, k ed s, e restituisca il numero di colonne 
contenenti almeno k stringhe con un numero di lettere 
vocali minore di s.*/

#include <iostream>
using namespace std;

int func(string***M, int n, short k, short s){
	int vocali;
	int count=0;
	int colonne=0;
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
		vocali = 0;	
			for(int f=0; f<(*M[i][j]).length(); f++){
				
				if( (*M[i][j])[f] == 'a' || (*M[i][j])[f] == 'A' ||
				    (*M[i][j])[f] == 'e' || (*M[i][j])[f] == 'E' ||
				    (*M[i][j])[f] == 'i' || (*M[i][j])[f] == 'I' ||
				    (*M[i][j])[f] == 'o' || (*M[i][j])[f] == 'O' ||
				    (*M[i][j])[f] == 'u' || (*M[i][j])[f] == 'U' ){
				    	vocali++;
					}
			}
			if(vocali<s)
			count ++;
		}
		if(count>=k){
			count=0;
			colonne++;
		}
	}
	return colonne;
}

int main(){
	
	short k = 2;
	short s = 2;
	int n = 3;
	
	string ** *M = new string **[n];  
	for (int i=0; i<n; i++){
		M[i] = new string * [n];  
		for (int j=0; j<n; j++){
			M[i][j] = new string ;  
			 cout<<"Inserisci stringa: "<<endl;
             cin>>*M[i][j];
		}
	}
	
	int ncol=func(M, n, k, s);
	cout<<"Numero colonne : "<<ncol;
}