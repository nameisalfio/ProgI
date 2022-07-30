#include <iostream>

using namespace std;

    unsigned int *funzione ( unsigned int *vett, int n){  //definizione della funzione
    	
	unsigned int *vet2 = new unsigned int[n];  //allocazione dinamica di un altro vettore
	
	for(int i = 0; i<n; i++){
		cout<<"Inserisci un valore nell'array : "<<endl;
		cin>>vett[i];
		vet2[i] = vett[i];
	}
	unsigned int *max = vet2, *min = vet2;
	
	for(int i = 0; i<n; i++){
		if(vet2[i]<*min){
			min =&(vett[i]);  //trovato un nuovo minimo, assegno l'indirizzo del nuovo minimo a min
		}
		if(vet2[i]>*max){
			max = &(vett[i]);  //trovato un nuovo massimo, assegno l'indirizzo del nuovo massimo a max
		}
		
	}
	int tmp =*max;  //scambio le posizioni del massimo e del minimo
		*max =*min;
		*min =tmp;
		return vet2;

}

int main(){
	int n;
	cout<<"Inserisci n : "<<endl;
	cin>>n;
	unsigned int vett[n];  //vettore di interi positivi
	
	unsigned int *func = funzione(vett, n); //invocazione della funzione
	
	for(int i =0 ;i<n; i++){  //stampo il vettore
		cout<<func[i];
	}
}