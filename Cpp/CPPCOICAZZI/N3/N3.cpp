/*Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice
di stringhe S di dimensioni n×m, un array di caratteri C che contiene elementi distinti,
ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa è maggiore di w*/

#include<iostream>
#include<string>
using namespace std;
#define n 3
#define m 2

bool func (string**S, char C[4], float w){
	int count;
	int caratteri;
	double perc;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int x=0; x<4; x++){
				for(int k=0; k<S[i][j].length(); k++){
					if((S[i][j])[k] == C[x])
					count++;
				}
				caratteri++;  //Numero di caratteri nell'intera riga
		    }
		    cout<<"Caratteri : "<<caratteri<<endl;
		    perc = (count*100)/caratteri;
		    cout<<"Percentuale : "<<perc<<" % "<<endl;
		    if(perc > w)
		    return true;
		    count = 0;
		}
	}
	
	return false;
}

int main(){
	
	float w = 40.5;
	char C[] = {'c', 'i', 'a', 'o'};
	
	string** S = new string*[n];
	for(int i=0; i<n; i++){
		S[i] = new string[m];
		for(int j=0; j<m; j++){
//			cout<<"Inserisci stringa : "<<endl;
//			cin>>S[i][j];
            S[i][j] = "Zzzz";
		}
	}
	
	bool esito = func(S, C, w);
	
	if(esito)
	cout<<"\nEsiste";
	if(!esito)
	cout<<"\nNon esiste";
}