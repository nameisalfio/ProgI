/* 20.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensione nm, 
una stringa s1 ed uno short k, e restituisca la 
percentuale di stringhe, tra quelle presenti nelle prime 
k colonne di S, che siano piu lunghe di s1. 
NB: si assuma k<=m. */

#include <iostream>
#include <string>
#define n 2
#define m 3

using namespace std;

float func (string***S, string s1, short k){
	int count = 0;
	float percentuale;
	
	for(int j=0; j<k; j++){
		for(int i=0; i<n; i++){
			if((*S[i][j]).length() > s1.length()){
				count ++;
			}
		}
	}
	
	percentuale = (count*100)/(n*k);
	return percentuale;
}

int main(){
	
	short k = 2;
	string s1 = "Hello";
	string ***S = new string **[n];
	for(int i=0; i<n; i++){
		S[i] = new string *[m];
		for (int j=0; j<m; j++){
			S[i][j] = new string;
			cout<<"Inserisci una stringa nella matrice : "<<endl;
			cin>>*S[i][j];
		}
	}
	
	float esito = func(S, s1, k);
	cout<<"La percentuale di colonne : "<<esito<<"%"<<endl;
	
}