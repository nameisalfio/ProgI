/*
Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte l’ordine degli
elementi all’interno dello array. 

ES: input: [1 2 3 4 5] --> risultato dell'elaborazione: [5 4 3 2 1]
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

unsigned int* inversione (unsigned int[] , int);  //prototipo della funzione

int main(){
	
	int n;
	
	cout<<"Inserisci la dimensione degli array : "<<endl;
	cin>>n;

	unsigned int vet [n];
	unsigned int vet2 [n];
	unsigned int vet3 [n];
	
	unsigned int* vet_ptr = inversione (vet, n);  //invocazione della funzione
	
		cout<<"Primo vettore invertito : "<<endl;
    for(int i=0; i<n; i++){  //stampo il primo vettore invertito
    	cout<<*(vet_ptr+i)<<" ";
	}
	cout<<endl;
	
	unsigned int* vet_ptr2 = inversione (vet2, n);  //invocazione della funzione

	cout<<"Secondo vettore invertito : "<<endl;
    for(int i=0; i<n; i++){  //stampo il secondo vettore invertito
    	cout<<*(vet_ptr2+i)<<" ";
	}
	cout<<endl;
	
	unsigned int* vet_ptr3 = inversione (vet3, n);  //invocazione della funzione

	cout<<"Terzo vettore invertito : "<<endl;
    for(int i=0; i<n; i++){  //stampo il terzo vettore invertito
    	cout<<*(vet_ptr3+i)<<" ";
	}
	cout<<endl;
    
    system("pause");
	return 0;
}


unsigned int* inversione (unsigned int* vet, int n){  //definizione della funzione
	
    unsigned int* vettore = new unsigned int[n];  //allocazione dinamica di un array
	int temp;
		
	cout<<endl;	
	for(int i=0; i<n; i++){
		cout<<"Inserisci un elemento nel vettore : "<<endl;
		cin>>vet[i];
	}
		
		cout<<"\nVettore inserito : "<<endl;  //visualizzo il vettore inserito dall'utente
	for(int i=0; i<n; i++){
		cout<<vet[i]<<" ";
	}
	cout<<endl;
	
	int k=0;
	for(int j=n-1; j>k ; j--){   //scambio gli elementi dell'array                              
		temp = vet[k] ;       
		vet[k] = vet[j];
		vet[j] = temp;
        k++;
		}

    for(int i=0; i<n; i++){  /*assegno il vettore modificato a quello allocato dinaminamente
                               in modo da poterlo esportare nella funzione chiamante*/
		vettore[i] = vet[i]; 
    }
    
	return vettore; 
	delete vettore ;  //deallocazione della memoria 

    }