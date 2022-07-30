/*Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce l’indice dell’ultima
consonante che si trova nello array in input.
*/
#include <iostream>

using namespace std;

int indice (char *vet, int n);

int main (){
	
	int n;
	cout<<"Inserisci la dimensione dell'array : "<<endl;
	cin>>n;
	char vet [n];
	
	int indice_consonante = indice (vet,n);
	
	cout<<"Indice dell'ultima consonante : "<<indice_consonante<<endl;
	
}

int indice (char *vet, int n){
	
	
	for(int i=0; i<n; i++){
		cout<<"Inserisci un valore nell'array"<<endl;
		cin>>vet[i];
    }
    
	    for(int i=n-1; i>=0; i--){
			if((vet[i] != 'a' && vet[i] != 'A')&&
		       (vet[i] != 'e' && vet[i] != 'E')&&
		       (vet[i] != 'i' && vet[i] != 'I')&&
		       (vet[i] != 'o' && vet[i] != 'O')&&
		       (vet[i] != 'u' && vet[i] != 'U')){
		       	
                return i;
			   }
		}
	
	return -1;
	
}