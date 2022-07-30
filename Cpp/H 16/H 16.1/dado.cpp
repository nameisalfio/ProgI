/*
Scrivere un programma in C++ che permetta di simulare
una sequenza di N lanci di una coppia di dadi, dove N è un
numero scelto dall’utente oppure una costante scelta a tempo
di compilazione. Il programma dovrà stampare le sequenze
dei due numeri (output primo dado e output secondo dado)
in due colonne separate. 
ES:
1 6
3 4
1 2
6 3
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

#define a 1
#define b 6

using namespace std;

int main (void){
	int N;
//	int a = 1,b = 6;
	unsigned int r, r1;

	cout<<"Inserire numero di lanci : "<<endl;
	cin>>N;
	
	for (int i = 0; i<N; i++){
//		unsigned int r = rand()%(b-a+1)+a genera valori randomi : a<RANDOM<b
        
        /*unsigned int r = rand()%(6-1+1)+1;
        unsigned int r1 = rand()%(6-1+1)+1;*/
        unsigned int r = rand()%(b-a+1)+a;
        unsigned int r1 = rand()%(b-a+1)+a;
        
        cout<<" "<<r<<" ";
	cout<<" "<<r1<<" "<<endl;
	}
	
	
	
	
//	for (int i=0; i<X; i++){
//  for (int j=0; j<Y; j++){
//    cout<<" "<< A[i][j] <<" ";
//  }
//cout<<endl;
//}
	
	
	
	return 0;
}