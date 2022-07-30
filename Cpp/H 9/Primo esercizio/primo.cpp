/*Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × N.
L’algoritmo dovrà calcolare e stampare la media aritmetica
dei valori differenza calcolati tra ogni valore della diagonale principale e il corrispondente valore della diagonale
secondaria. 
*/

#include <iostream>
using namespace std;

#define DIM 4

int main (void){

int N = DIM;
int V[N][N];

int count = 0,dif;  //contatore , differenza
float aver; //media

for(int i=0; i<N; i++){
	for (int j=0; j<N; j++){
		cout<<"Inserisci un valore nella matrice V : "<<endl;
		cin>>V[i][j];
	}
}
	
for(int i=0; i<N; i++){
	for (int j=0; j<N; j++){
		cout<< V[i][j];
		cout<<endl;
	}
  }

for(int i=0; i<N; i++){
   for( int j=N; j>0; j--){
     dif = V[i][i] - V[i][j];
     count = count + dif;
   }
}
aver = count/N;

cout<<"La media vale : "<<aver;

return 0;
system ("pause");
}