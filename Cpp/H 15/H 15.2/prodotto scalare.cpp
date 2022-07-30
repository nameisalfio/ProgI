/*
Scrivere un programma in C++ nel quale si chiede all’utente di
inserire due numeri N ed M entrambi maggiori di 1.
Successivamente:
• operare i soliti controlli ed eventuali arrotondamenti sui
numeri inseriti dallo utente;
• inizializzare la matrice con numeri a piacere in virgola mobile;
• calcolare e stampare il prodotto di uno scalare scelto a piacere
(es: 3.542) con la matrice

• definire una ulteriore matrice quadrata avente la dimensione
della più grande matrice quadrata che è possibile ricavare
dalla matrice esistente. 
ES: per una matrice 8x9 le dimensioni
della nuova matrice saranno 8x8;
• riempire la nuova matrice con i corrispondnti elementi della
prima matrice.

*/

#include <iostream>
#include <cmath>
using namespace std;

int main (){

int X,Y,K;  //parametri interi usati per l'inserimento di N ed M (entrambi float) come parametri della matrice (numero righe e numero colonne)
float N,M;  //numeri maggiori di 1 inseriti dall'utente
float a;  //scalare
//float A[X][Y];  
//float B[X][Y]; 
//float Q[K][K];

do{  //controllo che il primo numero sia positivo
cout<<"Inserisci il primo numero (positivo) : "<<endl;
cin>>N;
}while(N<=0);

do{  //controllo che il secondo numero sia positivo
cout<<"Inserisci il secondo numero (positivo) : "<<endl;
cin>>M;
}while(M<=0);

if (N<1){
cerr<<"Errore nel primo valore!!! Inserire un numero maggiore di 1 per continuare..."<<endl;  //Messaggio di errore
cout<<"Inserisci il numero correttamente: "<<endl;  //Possibilità di inserire un nuovo valore in N
cin>>N;
}

if (M<1){
cerr<<"Errore nel secondo valore!!! Inserire un numero maggiore di 1 per continuare..."<<endl;  //Messaggio di errore
cout<<"Inserisci il numero correttamente: "<<endl;  //Possibilità di inserire un nuovo valore in M
cin>>M;
}

if (N>=1){
N = round(N);  //approssimo N come di consuetudine
cout<<"Da adesso si terra' in considerazione il primo numero cosi' approssimato : "<<N<<endl;  //mostro all'utente il valore approssimato del numero inserito
X = N; //variabile di tipo intero usata per la descrizione della dimensione delle righe della matrice

  if (M>=1){
  M = round(M);  //approssimo M come di consuetudine
  cout<<"Da adesso si terra' in considerazione il secondo numero cosi' approssimato : "<<M<<endl;  //mostro all'utente il valore approssimato del numero inserito
  Y = M; //variabile di tipo intero usata per la descrizione della dimensione delle colonne della matrice
  
  float A[X][Y];  //matrice di dimensioni NxM

for (int i=0; i<X; i++){  //compilazione della matrice
  for (int j=0; j<Y; j++){
    cout<<endl<<"Inserisci un valore nella matrice : "<<endl;
    cin>>A[i][j];
  }
}

cout<<endl<<"Matrice di "<< N <<" righe e "<< M <<" colonne : "<<endl;  //stampo la matrice appena compilata

for (int i=0; i<X; i++){
  for (int j=0; j<Y; j++){
    cout<<" "<< A[i][j] <<" ";
  }
cout<<endl;
}

  }
}

cout<<endl<<"Inserisci lo scalare : "<<endl;  //chiedo l'inserimento dello scalare
cin>>a;

cout<<endl<<"Prodotto scalare di "<<a<<" per la matrice : "<<endl;  //stampo il prodotto dello scalare per la matrice

float A[X][Y];  //matrice di dimensioni NxM
float B[X][Y];  //matrice del prodotto scalare a per A[X][Y]

for (int i=0; i<X; i++){
  for (int j=0; j<Y; j++){
  	B[i][j] = a * A[i][j];
    cout<<" "<< B[i][j] <<" ";
  }
cout<<endl;
}

K = (X > Y ? Y : X);  //operatore condizionale che assegna a K il valore minore tra X e Y

float Q[K][K];  //matrice quadrata di ordine massimo in A[X][Y]

for (int i=0; i<K; i++){
	for (int j=0; j<K; j++){
	  Q[i][j] = A[i][j];
	}
}

cout<<endl<<"La matrice quadrata di ordine massimo in A e' una "<<K<<" per "<<K<<" : "<<endl; //stampo la matrice quadrata specificandone le dimensioni (l'ordine)

for (int i=0; i<K; i++){
	for (int j=0; j<K; j++){
	  cout<<" "<< Q[i][j] <<" ";
	}
	cout<<endl;
}

return 0;

}