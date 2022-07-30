/*23.Scrivere un metodo che prenda in input un 
parametro formale matrice K di double di dimensioni 
n x m e due interi a e b, e restituisca un array A di short 
di dimensione m, in cui l'elemento A[i] e calcolato 
come il numero di elementi della colonna i-esima di K 
tali che, approssimati all'intero più vicino, siano 
compresi tra a e b (inclusi).

NB: si assuma a < b.*/

#include <iostream>
#include <cmath>
#define n 3
#define m 2
using namespace std;


short *func (double **k, int a, int b){
	
	int count;
	short *vet = new short [m];
	
	for(int j=0; j<m; j++){
		count=0;
		for(int i=0; i<n; i++){  //Scorro tutti gli elementi della colonna
			if(round(k[i][j])>=a && round(k[i][j])<=b){
				count ++;
			}
		}
		vet[j]=count;
	}
	
	return vet;
}

int main(){
	int a = 3;
	int b = 7;
	
	double **k = new double *[n];
	for(int i=0; i<n; i++){
		k[i] = new double [m];
		for(int j=0; j<m; j++){
			cout<<"Inserisci double"<<endl;
			cin>>k[i][j];
		}
	}
	
	short *v = func(k, a, b);
	
	cout<<"\nIl vettore : "<<endl;
	for(int i=0; i<m; i++){
		cout<<v[i]<<" ";
	}
}