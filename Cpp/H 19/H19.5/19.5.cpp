/* Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il numero di vocali
presenti nell' array.
*/

#include <iostream>

using namespace std;

int vocali (char *, int);  //prototipo

int vocali (char *vet, int n){  //definizione della funzione
	
	int c = 0;
	
	for(int i=0; i<n; i++){	
		cout<<"Inserisci un carattere : "<<endl;
		cin>>vet[i];
	}
	
	for(int i=0; i<n; i++){	//stampo l'array
		cout<<vet[i]<<" ";
	}
	 
	for(int i=0; i<n; i++){
		
	  if ((vet[i] == 'a' || vet[i] == 'A')||
	      (vet[i] == 'e' || vet[i] == 'E')||
	      (vet[i] == 'i' || vet[i] == 'I')||
	      (vet[i] == 'o' || vet[i] == 'O')||
	      (vet[i] == 'u' || vet[i] == 'U'))
	      
	      	c++;
		  
	    
	}
	  
	return c;
}

int main (){
	
	int n; 
	cout<<"Inserisci la dimensione del vettore : "<<endl;
	cin>>n;
	
	char vet[n];
	
	int contatore = vocali(vet, n);
	
	cout<<"\nIl numero di vocali e' : "<<contatore<<endl;  //invocazione
	
	return 0;
}


