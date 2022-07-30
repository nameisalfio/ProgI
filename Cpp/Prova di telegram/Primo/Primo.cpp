/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S di dimensioni n × n di puntatori a interi
senza segno, un double w ed uno short k (si assuma k < n). Il metodo restituisca il valore booleano true se esistono almeno k
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi della colonna stessa sia minore o uguale a
w. 
NB: si presti attenzione ai numeri mancanti. */

#include <iostream>
#define n 3 

using namespace std;

bool func (unsigned int ** *S, double w, short int k ){
	int somma, col;
	float media;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			somma += *S[i][j];
		}
		media = somma/n;
		if(media <= w){
			col++;
		}
	}
	
	if(col >= k){
		return true;
	}else{
		return false;
	}
}

int main (){
	
	double w = 3.3;
	short k = 2; 
	
	unsigned int ** *S = new unsigned int **[n];
	
	for(int i=0; i<n ; i++){	
		S[i] = new unsigned int *[n];
		
		for(int j=0; j<n; j++){
			S[i][j] = new unsigned int;
			
			cout<<"Inserisci un intero senza segno : "<<endl;
			cin>>*S[i][j];
		}
	
	}
	
		bool esito = func (S, w, k);
	
		if(esito == true){
			cout<<"\nEsistono "<<k<<" colonne in S che soddisfano il requisito richiesto";
		}else{
			cout<<"\nNon esiste nemmeno una colonna in S che soddisfa il requisito richiesto";
		}
}