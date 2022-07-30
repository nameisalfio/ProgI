/*
Scrivere un programma in C++ nel quale si chiede all’utente un
numero qualunque p. Successivamente:
• Se il numero p è minore di 1, stampare un messaggio di errore.
• Se il numero p è maggiore o uguale a 1, arrotondare il numero
stesso allo intero più vicino e allocare un array di quella
dimensione.
• Inizializzare lo array con valori a piacere per tre volte
mediante un ciclo:
I) con il costrutto for; 
II) con il costrutto while;
III) con il costrutto do-while.
• Stampare tutti i valori dell'array con un ciclo usando un
costrutto a scelta 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main (){

float p;

cout<<"Inserisci un numero qualunque : "<<endl;
cin>>p;

if (p<1){
cerr<<"Errore!!! Inserire un numero maggiore di 1 per continuare..."<<endl;  //Messaggio di errore
cout<<"Inserisci il numero: "<<endl;  //Possibilità di inserire un nuovo valore in p
cin>>p;
}
if (p>=1){
p = round(p);  //approssimo p come di consuetudine
cout<<"Da adesso si terra' in considerazione il numero cosi' approssimato : "<<p<<endl;  //mostro all'utente il valore approssimato del numero inserito

int x = p; //variabile di tipo intero usata per la descrizione della dimensione dell'array

int A[x];  //dichiaro l'array di dimensione x = p (approssimato)

  for (int i=0; i<x; i++){
  	cout<<"Inserisci un valore nell'array : "<<endl;  //scrivo i valorri nell'array con un ciclo for
  	cin>>A[i];
  } 
  
  /*int i=0;
  while (i<p){
  	cout<<"Inserisci un valore nell'array : "<<endl;  //Scrivo i valori nell'array con un ciclo while
  	cin>>A[i];
  	i++;
  }*/
  
  /*int i=0;
  do {
  	cout<<"Inserisci un valore nell'array : "<<endl;  //Scrivo i valori nell'array con un ciclo do-while
  	cin>>A[i];
  	i++;
  }while (i<p);*/
  
  cout<<"Array : "<<endl;  
  
  for (int i=0; i<x; i++){  //Stampo l'array
  	cout<<A[i]<<endl;
  }
  
}

return 0;

}
