/*22.Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. 

NB: Si assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero.*/

#include <iostream>
#include <string>

using namespace std;

bool func (string**Q, int n){
	
	string max, min;
	int countmax=0, countmin=0;
	
	max=Q[0][0];
	min=Q[0][0];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				if(Q[i][j].length()>max.length()){
					max = Q[i][j];
				}
				if(Q[i][j].length()<min.length()){
					min = Q[i][j];
				}
			}
		}
	}
	
	for(int i=0; i<max.length(); i++){
		if(max[i] == 'a'|| max[i] == 'e'||max[i] == 'i'|| max[i] == 'o'|| max[i] == 'u'){
			countmax++;
		}
	}
	
	for(int i=0; i<min.length(); i++){
		if(min[i] == 'a'|| min[i] == 'e'||min[i] == 'i'|| min[i] == 'o'|| min[i] == 'u'){
			countmin++;
		}
	}
	
	if(countmax>countmin)
	return true;
	if(countmax<countmin)
	return false;
	
}

int main(){
	int n = 2;
	
	string **Q = new string *[n]; 
	for(int i=0; i<n; i++){
		Q[i] = new string [n];
		for(int j=0; j<n; j++){
			cout<<"Inserisci stringa"<<endl;
			cin>>Q[i][j];
		}
	}
	
	bool esito = func(Q, n);
	if (esito)
	cout<<"\nNella stringa piu' lunga ci sono piu' vocali"<<endl;
	if (!esito)
	cout<<"\nNella stringa piu' corta ci sono piu' vocali"<<endl;
}