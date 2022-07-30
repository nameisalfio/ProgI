/* Scrivere un metodo che prenda in input una matrice A di stringhe di dimensioni n × m ed una matrice B di puntatori a
stringhe di dimensioni m × l. Il metodo restituisca un vettore di booleani C di dimensione l in cui cj = true se e solo se è
possibile trovare almeno una stringa, nella colonna j −esima di B (sia bkj ), la quale sia sottostringa della corrispondente stringa
presente nella riga j − esima di A (sia ajk). Si assuma n ≥ l. 
NB: si presti attenzione alle stringhe mancanti in B. */

#include <iostream>
#include <string>

#define n 3
#define m 4
#define l 2

using namespace std;

bool *func (string **A, string** *B){
	
	bool *C = new bool [l];
	
	for(int j=0; j<n; j++){
		for(int k=0; k<m; k++){
			if(A[j][k].find(*B[k][j])){
				C[j] = true;
			}else{
				C[j] = false;
			}
		}
	}
	
	return C;
}

int main (){
	
/*	string A[n][m];
	for(int j=0; j<n; j++){
		for(int k=0; k<m; k++){
			cout<<"Inserisci una stringa in A : "<<endl;
			cin>>A[j][k];
		}
	}
	*/
	
	string** A = new string *[n];
	for(int j=0; j<n; j++){
		
		A[j] = new string [m];
		for(int k=0; k<m; k++){
			cout<<"Inserisci una stringa nella matrice A : "<<endl;
			cin>>A[j][k];
		}
	}
	
	string** *B = new string**[m];
	for(int k=0; k<m; k++){
		
		B[k] = new string*[l];
		for(int j=0; j<l; j++){
			
			B[k][j] = new string ("Hello");
		}
	}
	
	bool *C = func (A, B);
	
	cout<<"Array di bool : "<<endl;
	for(int j=0; j<l; j++){
		cout<<C[j]<<" ";
	}
}