/*Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il puntatore alla cella
che contiene la prima vocale dello array.
*/

#include <iostream>

using namespace std;

char *func(char* vet, int n);

int main (){
	int n ;
	cout<<"Inserisci la lunghezza dell'array: "<<endl;
	cin>>n;
	char vet[n];
	
	char*p= func(vet, n);
	
	cout<<"Il puntatore alla cella che contiene la prima vocale : "<<p<<endl;
}

char *func (char* vet, int n){  //definizione della funzione
	
	char *ptr = new char[n];  //allocazione dinamica
	
	for (int i=0; i<n; i++){
		cout<<"Inserisci un carattere : "<<endl;
		cin>>vet[i];
		ptr = &vet[i]; //punto alla cella con la prima vocale
		cout<<"ptr : "<<ptr<<endl;
		  
		  if ((*ptr =='a')||(*ptr =='e')||(*ptr =='i')||(*ptr =='o')||(*ptr =='u')){
		  	return ptr;
		  }
	}
	
}