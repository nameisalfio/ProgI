/*Descrivere un algoritmo in notazione NLS che prende in input una matrice V di dimensioni N × M ed uno array W di
dimensione L.
L’algoritmo dovr`a calcolare, per ogni riga di V, il numero di
elementi dello array W che sono compresi tra il minimo e
il massimo valore (estremi inclusi) della riga stessa.
*/
#include <iostream>
using namespace std;

int main (){

int N,M,L; //Numero di righe e numero di colonne
int max,min,count = 0; //Massimo, minimo e contatore

cout<<"Inserisci il numero di righe della matrice: "<<endl;
cin>>N;

cout<<"Inserisci il numero di colonne della matrice: "<<endl;
cin>>M;

cout<<"Inserisci la dimensione dell'Array: "<<endl;
cin>>L;

int V[N][M];  //Matrice NxM
int W[L]; //Array DIM = L

for(int i=0; i<N; i++){ //Inserimento dei valori nella matrice
  for(int j=0; j<M; j++){
    cout<<"Inserisci un valore nella matrice V : "<<endl;
    cin>>V[i][j];
  }
}

for (int k = 0; k<L; k++){
  	cout<<"Inserisci un valore nell'array W : "<<endl;
    cin>>W[k];
}


for (int i=0; i<N; i++){  //Scorre le righe di V
  for (int j=0; j<M; j++){  //Scorre le colonne di V
   V[i][j] = max;
   V[i][j] = min;

   if(V[i][j] > max)
     max = V[i][j];
   if(V[i][j] < min)
     min = V[i][j];

      for (int k = 0; k<L; k++){ //Scorre l'array W
        if(W[k] >= min && W[k]<= max)
        count ++;
    }
  }
  cout<<"Gli elementi dell'Array W compresi tra il massimo e il minimo valore della riga "<<i<<" della matrice V sono :"<<count<<endl; 
}

return 0 ;
}