/* Scrivere un metodo che prenda in input una 
matrice quadrata Q di interi ed un 
double w, e restituisca un valore booleano true se 
esiste almeno una colonna della matrice Q tale che il 
rapporto tra la somma degli elementi della colonna 
stessa e la somma degli elementi della diagonale 
secondaria di Q sia maggiore di w. */

#include <iostream>
#define n 5

using namespace std;

bool func (int**Q, double w){
	
	bool rapporto;
	int somma_ds = 0;
	int somma_c =0;
	
	//Visualizzo la matrice
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<" "<<Q[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Visualizzo la diagonale secondaria
	cout<<"\n\nDiagonale secondaria : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((i+j)==n-1)
			cout<<" "<<Q[i][j]<<" ";
		}
	}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			somma_c = somma_c + Q[i][j];
			if((i+j)==n-1)
				somma_ds = somma_ds + Q[i][j];
		}
		cout<<"\nSomma colonna : "<<somma_c<<endl;
	    if((somma_c/somma_ds)>w){
	    	rapporto = true;
//	    	cout<<"Rapporto :"<<rapporto<<endl;
		}
		somma_c = 0;
	}
	cout<<"\nSomma diagonale secondaria : "<<somma_ds<<endl;

return rapporto;
}

int main(){
	
	double w;
	cout<<"Inserisci un double 'w' : "<<endl;
	cin>>w;
	
	int **Q = new int* [n];
	for(int i=0; i<n; i++){
		Q[i] = new int [n];
		for (int j=0; j<n; j++){
			Q[i][j] = *new int % 10;  //valori casuali minori di 10
		}
	}
		
	bool rapporto = func (Q, w);
	if (rapporto == true){
		cout<<"Esiste almeno una colonna della matrice Q che verifica la proprieta'"<<endl; 
	}else{
		cout<<"Non esiste nemmeno una colonna della matrice Q che verifica la proprieta'"<<endl;
	}
}