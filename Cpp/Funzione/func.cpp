#include<iostream>
 using namespace std;
 
 int somma(int x, int y){  //funzione somma
 	int somma=x+y;
 	return somma;
 }
 
 void print(string s){  //funzione print
 	cout<<s;
 }
 
 int pow(int base, int esponente ){  //funzione pow
 	
 	int potenza = 1 ;
 	for (int i=0; i<esponente; i++){
 		potenza *= base; //
	 }
	return potenza;
 }
 
 int main(){  //funzione main 
 	
 	int x;
    x = somma(2,8);  //invocazione di somma
 	cout<<"La somma di 2 e 8 vale: "<<x<<endl;
 	
 	print("\nGMF = Gran Maestro Farinella\n\n"); //invocazione di print
	
	int base, esponente;
	
 	cout<<"Inserisci la base : "<<endl;
 	cin>>base;
 	cout<<"Inserisci l'esponente : "<<endl;
 	cin>>esponente;
 	
 	int potenza = pow (base, esponente);  //invocazione di pow
	cout<<"La potenza vale : "<<potenza<<endl;
 	
 	
 }