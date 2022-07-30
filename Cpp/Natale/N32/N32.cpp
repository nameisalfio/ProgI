/*32.Scrivere un metodo che prenda in input una 
matrice quadrata di puntatori a stringhe e due caratteri 
c1 e c2. Calcolare O1 come numero di occorrenze del 
carattere c1 che figurano nella diagonale principale. 
Calcolare O2 come numero di occorrenze del carattere 
c2 che che figurano nella secondaria. Restituire il 
rapporto O1/O2. 
NB: si faccia attenzione alle stringhe mancante*/

#include <iostream>
#include <string>
using namespace std;
#define n 3

double func(string***M, char c1, char c2){
	int o1=0, o2=0;
	
	for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		if(M[i][j]){
    			if(j==i){
    				if((*M[i][j]).find(c1)!=string::npos)
    				o1++;
    		    }
	    		if(i+j==n-1){
	    			if((*M[i][j]).find(c2)!=string::npos)
	    			o2++;
				}
			}
		}
	}
	
	return (double)o1/o2;
}

int main(){
	char c1='c';
	char c2='o';
	
	string***A = new string**[n];
	for(int i=0; i<n; i++){
		A[i] = new string*[n];
		for(int j=0; j<n; j++){
			A[i][j] = new string;
			cout<<"Inserisci stringa : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	double rapporto = func(A, c1, c2);
	cout<<"Il rapporto : "<<rapporto<<endl;
}