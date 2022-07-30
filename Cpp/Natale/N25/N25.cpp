/* 25.Scrivere un metodo che prenda in input una 
matrice di interi M di dimensioni nxm, uno short k ed 
un double x, e restituisca il valore booleano true se 
esiste almeno una colonna in M contenente 
esattamente k coppie di elementi adiacenti tali che il 
rapporto tra il primo elemento ed il secondo elemento 
di ogni coppia sia minore di x. 

NB: Si assuma k <= n-1 e si presti attenzione alle divisioni per zero!*/

#include <iostream>
#define n 3
#define m 2
using namespace std;

bool func(int M[n][m], short k, double x){
	int count; 
	
	for(int j=0; j<m; j++){
		count = 0;
		for(int i=0; i<n-1; i++){
			if(M[i][j] && M[i+1][j]){
				if( ( (M[i][j]/M[i+1][j]) < x)){
					count ++;  //Coppia di elem. adiacenti 
				}
			}
			if(count==k)
			return true;
		}
	}
	return false;
}

int main(){

	short k = 2;
	double x = 1;
	int M[n][m];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"Inserisci intero : "<<endl;
			cin>>M[i][j];
		}
	}
	
	bool esito = func(M, k, x);
	if(esito)
	cout<<"Esiste almeno una colonna"<<endl;
	if(!esito)
	cout<<"Non esiste nemmeno una colonna"<<endl;
}