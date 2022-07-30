/*Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il puntatore alla cella
che contiene la prima vocale dello array.
*/

#include <iostream>

using namespace std;

int cella (char *vet, int n);  //prototipo

int main (){
	
	int n;
	cout<<"Inserisci la dimensione dell'array : "<<endl;
	cin>>n;
	char vet [n];
	
    int ptr = cella (vet, n);  //invocazione
	
	cout<<"Puntatore della cella della prima vocale : "<<ptr<<endl;
	
}

int cella (char *vet, int n){  //definizione
	
  int *ptr;
	
	for(int i=0; i<n; i++){
		cout<<"Inserisci un valore nell'array : "<<endl;
		cin>>vet[i];
    }
    
    
	    for(int i=0; i<n; i++){
			if((vet[i] == 'a' || vet[i] == 'A')||
		       (vet[i] == 'e' || vet[i] == 'E')||
		       (vet[i] == 'i' || vet[i] == 'I')||
		       (vet[i] == 'o' || vet[i] == 'O')||
		       (vet[i] == 'u' || vet[i] == 'U')){
		       	
		       	ptr = &i;
		       	cout<<"INDIRIZZO : "<<ptr<<endl;
                return *ptr;
			   }
		}

	
	
	return -1;
	
}