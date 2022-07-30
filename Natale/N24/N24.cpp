/*24.Scrivere un metodo che prenda in input una 
matrice di stringhe S di dimensioni n m, uno short k, 
ed una stringa w. Il metodo restituisca il valore 
booleano true se esiste almeno una riga in S tale che 
la stringa w sia sottostringa di un numero di stringhe 
della riga stessa che sia minore o uguale a k. */

#include <iostream>
#include <string>
#define n 2
#define m 3
using namespace std;

bool func (string s[n][m], short k, string w){
	
	int count;
	
	for(int i=0; i<n; i++){
		count = 0;
		for(int j=0; j<m; j++){
			if(s[i][j].find(w) != string::npos){
				count ++;
			}
		}
		if(count<=k)
		return true;
	}
	
	return false;
}

int main(){
	
	int k = 2;
	string w = "hello";
	
	string s[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"Inserisci stringa"<<endl;
			cin>>s[i][j];
		}
	}
	
	bool esito = func(s, k, w);
	if(esito)
	cout<<"\nEsiste almeno una riga che rispetta il requisito"<<endl;
	if(!esito)
	cout<<"\nNon esiste nemmeno una riga che rispetta il requisito"<<endl;
}