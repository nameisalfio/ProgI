/* Scrivere un programma in C++ che permetta all'utente di costuire un array definendone la dimensione (almeno un elemento) ed inserendo gli elementi.
Il programma deve stampare a video l'array così creato . Deve stampare inoltre :
- Massimo;
- Minimo;
- Media dei valori contenuti nell'array;
- Numero di elementi pari e dispari;
*/
#include<iostream>
using namespace std;

int main (void) {

int max,min,N;

do {
cout<<"Inserisci la dimensione dell'array: "<<endl; //L'utente stabilisce la dimensione dell'array
cin>>N;
}while(N<1); //Controllo che l'array contenga almeno un elemento

int A [N];


for(int i = 0;i < N; i++){

cout<<"Inserisci un valore: "<<endl;  //L'utente inserisce i valori nell'array
cin>> A [i];

  if (i == 0){  //Assumo che il primo valore inserito corrisponda sia al massimo che al minimo
  	max = A [i];
  	min = A [i];
  }
  
  if (A [i]>max)  //Controllo del massimo e del minimo
  max = A[i];
  
  if (A [i]<min)
  min = A[i];
}

cout<<"\nValori inseriti nell'array :"<<endl;  //Visualizzo l'array 
for (int i = 0; i < N; i++)
cout<<A [i]<<endl;

cout<<"Il valore massimo e' :"<<max<<endl;  //Stampo il massimo ed il minimo
cout<<"Il valore minimo e' :"<<min<<endl;

return 0;
system ("pause");
}