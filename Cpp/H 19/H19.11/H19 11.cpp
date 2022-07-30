/* Definire una funzione che prende in input un array
monodimensionale di caratteri e l’indirizzo di una variabile short.

La funzione dovrà restituire un array formato da tutte le vocali
dello array in input.

La funzione scrive il valore dimensione dello array restituito nella
cella short corrispondente al puntatore in input.

Se non ci sono vocali nello array in input, la funzione restituisce
nullptr.
*/

#include<iostream>
#define DIM 100

using namespace std;

char* func (char*, short*);  //prototipo 

int main(){
	
	char vet[DIM];
	short var;
	short* ptr ;
	ptr = &var;  //assegno a "ptr" l'indirizzo della variabile "var"
	
	
	char* array = func (vet, ptr);  //invocazione
	
	
	/*cout<<"L'array di vocali : "<<endl;  //stampo l'array di sole vocali
	for(int i=0; i<var; i++){
		cout<<array[i];
	}*/
	
	cout<<"\nLa dimensione dell'array : \n"<<var<<endl;  //stampo la dimensione dell'array di sole vocali
	
	return 0;
}

char* func (char* vet, short* ptr){  //definizione
	
	int n;
	cout<<"Quanti caratteri vuoi inserire ? "<<endl;
	cin>>n;
	
	for(int i=0; i<n; i++){
	    cout<<"Inserisci un carattere nell'array : "<<endl;
	    cin>>vet[i];
    }
	
	short int counter = 0;
	char* vettore = new char [n];  //allocazione dinamica
	
		    cout<<"L'array di vocali : "<<endl;  //stampo l'array di sole vocali
	
	for (int i=0; i<n; i++){
		
		if((vet[i]=='a'||vet[i]=='A')||
		   (vet[i]=='e'||vet[i]=='E')||
		   (vet[i]=='i'||vet[i]=='I')||
		   (vet[i]=='o'||vet[i]=='O')||
		   (vet[i]=='u'||vet[i]=='U')  )
		  {
		  	vettore[i]=vet[i];
		    counter ++;
		    cout<<vettore[i]<<" ";
		  }
		  
    }
    
    //Dichiarata una variabile "var" si può operare sul suo contenuto in una funzione esterna passando il suo puntatore"ptr"
    for (int i=0; i<n; i++){

		if(counter==0){
			*ptr = 0;  //se non ho contato vocali restituisco 0
		}else{
			*ptr = counter;  //restituisco il numero di vocali
		}
    }
		return vettore;
		
		//deallocazione
		delete vettore;
		
    }