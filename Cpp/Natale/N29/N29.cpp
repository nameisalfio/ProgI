/*29.Scrivere un metodo che prenda in input una 
matrice quadrata A di numeri interi ed un double w, e 
restituisca il valore booleano true se il rapporto tra il 
minimo ed il massimo valore della diagonale 
secondaria di A e minore o uguale a w.*/

#include <iostream>
using namespace std;
#define N 3

bool func (int**A, double w){
	int max = A[0][N-1];
	int min = A[0][N-1];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i+j == N-1){
				if(A[i][j] > max)
				max = A[i][j];
				if(A[i][j] < min)
				min = A[i][j];
			}
		}
	}
	
	cout<<"Massimo :"<<max<<endl;
	cout<<"Minimo :"<<min<<endl;
	
	if(min/max <= w)
	return true;
	else 
	return false;
}

int main(){
	
	double w = 1.5;
	
	int**A = new int*[N];
	for(int i=0; i<N; i++){
		A[i] = new int[N];
		for(int j=0; j<N; j++){
			cout<<"Inserisci intero :"<<endl;
			cin>>A[i][j];
		}
	}
	
	bool esito = func(A, w);
	if(esito)
	cout<<"True"<<endl;
	if(!esito)
	cout<<"False"<<endl;
}