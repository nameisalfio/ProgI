/*34.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensioni n×m, 
una stringa x ed un array di double W di dimensione 
m; il metodo restituisca un array di bool R di 
dimensione m tale che l’i-esimo elemento di R sarà 
true se e solo se il rapporto tra il numero di stringhe 
della i-esima colonna di S delle quali x è sottostringa 
ed il numero n è minore o uguale dello i-esimo 
elemento di W. 
NB: Si presti attenzione alle stringhe mancanti!*/

#include <iostream>
#include <string>
using namespace std;

#define n 3
#define m 2

bool* func(string***S, string x, double w[m]){
	bool* R = new bool [m];
	int count;
	
	for(int j=0; j<m; j++){
		count=0;
		for(int i=0; i<n; i++){
			if(S[i][j]){
				if((*S[i][j]).find(x) != string::npos){
					count++;
				}
			}
		}
		if(count/n <= w[j])
		R[j] = true;
		else
		R[j] = false;
	}
	
	return R;
}

int main(){
	string***A = new string**[n];
	for(int i=0; i<n; i++){
		A[i] = new string*[n];
		for(int j=0; j<m; j++){
			A[i][j] = new string;
			cout<<"Inserisci stringa "<<endl;
			cin>>*A[i][j];
		}
	}
	
	string x = "ciao";
	
	double* w = new double[m];
	for(int i=0; i<m; i++){
		cout<<"Inserisci double: "<<endl;
		cin>>w[i];
	}
	
	bool *vet = new bool[m];
	vet = func(A, x, w);
	
	cout<<"\nIl vettore : "<<endl;
	for(int i=0; i<m; i++){
		cout<<vet[i]<<" ";
	}
}