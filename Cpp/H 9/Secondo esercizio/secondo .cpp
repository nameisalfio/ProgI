/*Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × M
ed un numero p.
L’algoritmo dovrà calcolare e stampare le medie aritmetiche
di tutti i valori minori o uguali a p per le sole righe di
V che hanno indice dispari.*/

#include <iostream>
using namespace std;

int main (){

int N,M; //Numero di righe e numero di colonne
int p, count = 0, sum;
float aver;  //Media aritmetica

cout<<"Inserisci il numero di righe della matrice: "<<endl;
cin>>N;

cout<<"Inserisci il numero di colonne della matrice: "<<endl;
cin>>M;

cout<<"Inserisci il valore di p: "<<endl;
cin>>p;

int V[N][M];  //Matrice NxM

for(int i=0; i<N; i++){ //Inserimento dei valori nella matrice
  for(int j=0; j<M; j++){
    cout<<"Inserisci un valore nella matrice V : "<<endl;
    cin>>V[i][j];
  }
}


for(int i=0; i<N; i++){
  for(int j=0; j<M; j++){

    if(i%2!=0){
      if(V[i][j]<=p){
        sum = sum + V[i][j];
        count ++;
      }
    }

  }
}

aver = sum/count;
cout<<"La media dei valori vale :"<<aver<<endl;

return 0;

}