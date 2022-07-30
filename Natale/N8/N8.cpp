/* 8.Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q.
*/

#include <iostream>
#include <string>
#define n 3

using namespace std;

bool func (string***Q, string s){
	
	bool esito = true;
	int count=0;
	int count2=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			string stringa = *(Q[i][j]);
			if(i==j){
				if(stringa.find(s) != string :: npos){
					count ++;
				}
			}else if(i+j == n-1){
				    if(stringa.find(s) != string :: npos){
					count2++;
					}
			}
		}
	}
	
    if (count2>count){
		esito = false;
	}
	
	return esito;
}

int main(){
	
	string s = ("Hello");
	
	string ** *Q = new string **[n];
	for(int i=0; i<n; i++){
		
		Q[i] = new string *[n];
		for(int j=0; j<n; j++){
			
			Q[i][j] = new string;
			
			cout<<"Inserisci stringa : "<<endl;
			cin>>*Q[i][j];
		}
	}
	
	bool esito = func (Q, s);
	cout<<"Esito : "<<esito<<endl;
   
}