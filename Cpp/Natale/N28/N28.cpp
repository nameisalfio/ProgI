/*28.Scrivere un metodo che prenda come parametro 
formale un array A di stringhe (tutte di lunghezza 
dispari), e restituisca in output la massima lunghezza 
delle stringhe palindrome contenute in A.*/

#include <iostream>
#include <string>
#define n 2
using namespace std;

int func (string A[n]){
	int max;

	for(int k=0; k<n; k++){
		for(int i=0, j=A[k].length()-1; i<j; i++, j--){
			if((A[k])[i] != (A[k])[j]){
			   return -1;				
			}
		}
		max = A[k].length();
		if(A[k].length() > max){
			max = A[k].length();
		}
	}
    
	return max;
}

int main(){
	string A[n];
	for(int i=0; i<n; i++){
		do{
			cout<<"Inserisci stringa :"<<endl;
			cin>>A[i];
		}while(A[i].length()%2 == 0);
    }
	
    int lunghezza = func(A);
    
    if(lunghezza == -1)
    cerr<<"Stringhe non palindrome"<<endl;
    else
    cout<<"La lunghezza : "<<lunghezza;
}