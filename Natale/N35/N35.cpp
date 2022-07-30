/*35.Scrivere un metodo che prenda in input una 
matrice Q di puntatori a int di dimensione n × m e due 
float a e b e restituisca un array di float di dimensione 
m tale che lo i-esimo elemento dello array contiene la 
media dei soli elementi della colonna i-esima compresi 
tra a e b (estremi inclusi). Nel confronto tra interi e 
numeri in virgola mobile si consideri l’arrotondamento 
di questi ultimi al numero intero più prossimo ad essi. 
NB: Si presti attenzione ai numeri mancanti!*/

#include <iostream>
#include <cmath>
using namespace std;
#define n 3
#define m 2

float* func (int***Q, float a, float b){
	int count;
	int somma;
	
	float* arr = new float [m];
	
	for(int j=0; j<m; j++){
		somma=0;
		count=0;
		for(int i=0; i<n; i++){
			if(*Q[i][j]>=round(a) && *Q[i][j]<=round(b)){
				somma += *Q[i][j];
				count++;
			}
		}
		arr[j] = somma/count;
	}
	
	return arr;
}

int main(){
	float a=1.8;
	float b=5.6;
	
	int***Q = new int**[n];
	for(int i=0; i<n; i++){
		Q[i] = new int*[m];
		for(int j=0; j<m; j++){
			Q[i][j] = new int;
			cout<<"Inserisci intero : "<<endl;
			cin>>*Q[i][j];
		}
	}
	
	float* vet = func(Q, a, b);
	
	cout<<"\nL'array : "<<endl;
	for(int i=0; i<m; i++)
	cout<<vet[i]<<" ";
}