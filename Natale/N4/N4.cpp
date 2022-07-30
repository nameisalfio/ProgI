/* 4.Scrivere un metodo che prenda in input una matrice 
di puntatori a stringhe P di dimensioni nxm, due short a 
e b, ed una stringa s. Il metodo restituisca il valore 
booleano true se esiste almeno una colonna in P tale 
che la stringa s sia sottostringa di un numero 
compreso tra a e b (inclusi) di stringhe della colonna 
stessa. PS: Si assuma 0 < a b < n */

#include<iostream>
#include<string>
#define n 3
#define m 2

using namespace std; 

bool func (string*** P, short a, short b, string s){  //Definizione della funzione
	
	a = 1;
	b = 2;
	s = "He";
	int count = 0;
	bool risp = false;
	
	string*** A = new string **[n];
	
	for(int i=0; i<n; i++){
		A[i] = new string *[m];
		
		for(int j=0; j<m; j++){
			A[i][j] = new string ("Hello");
		}
	}
	
    for(int j=0; j<m; j++){
	    for(int i=0; i<n; i++){
	    	if((*A[i][j]).find(s,0) != string::npos){  //Se la stringa s è presente in *A[i][j]
			    risp = true;
		    }
	    }
    }
    
delete [] A;  //Deallocazione
    
return risp;

}

int main(){
	
    string ***P = new string **[n];
	for(int i=0; i<n; i++){
		
		P[i] = new string *[m];
		for(int j=0; j<m; j++){
			
			P[i][j] = new string;
		}
	}
	
	short int a,b;
	string s;
	bool risp;
	
	risp = func (P, a, b, s);  //Invocazione della funzione
	
	if (risp == true){
		cout<<"Esiste"<<endl;
	}else{
		cout<<"Non esiste"<<endl;
	}	
	
	return 0;
}