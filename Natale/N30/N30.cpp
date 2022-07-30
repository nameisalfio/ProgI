/*30.Scrivere un metodo che prenda in input una 
matrice di stringhe A e due numeri short senza segno, 
k ed s, e restituisca il valore booleano true se esiste 
almeno una riga di A contenente almeno k stringhe 
ognuna contenente un numero di lettere maiuscole 
minore di s.*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
#define n 2
#define m 3

bool func(string**A, unsigned short k, unsigned short s){
	int count, count2;
	
	for(int i=0; i<n; i++){
		count2=0;
		for(int j=0; j<m; j++){
			count=0;
			for(int k=0; k<(A[i][j]).length(); k++){
				if(isupper((A[i][j])[k])){
					count++;
				}
			}
		if(count<s)
		count2++;	
		}
		if(count2 >= k)
		return true;
	}
	return false;
}

int main(){
	
	unsigned short k=2, s=4;
	
	string**A = new string*[n];
	for(int i=0; i<n; i++){
		A[i] = new string [m];
		for(int j=0; j<m; j++){
			cout<<"Inserisci stringa "<<endl;
			cin>>A[i][j];
		}
	}
	
	bool esito = func(A, k, s);
	if(esito)
	cout<<"\nTrue"<<endl;
	if(!esito)
	cout<<"\nFalse"<<endl;
}
