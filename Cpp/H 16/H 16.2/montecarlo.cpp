/*Codificare in C++ un programma per il metodo montecarlo
per il calcolo (approssimato) del numero π sulla base che si
basi sull’esempio E16.1.
NB: Il numero di campionamenti deve essere scelto
dall’utente a tempo di esecuzione.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

int main (){
	
//	cout<<M_PI; //STAMPA PI GRECO
 int n; //numero di campionamenti
 int x,y;
 bool att = 0 ;  
 int a = -1;
 int b = 1;
 
 cout<<"Inserisci il numero di campionamenti : "<<endl;
 cin>>n;
 
 for(int i = 0; i<n; i++){
 
 x = rand()%(b-a+1)+a;
 y = rand()%(b-a+1)+a;
 
 	cout<<" "<<x<<" ";
 	cout<<" "<<y<<" "<<endl;
 }
 
 
	
	
	return 0;
}