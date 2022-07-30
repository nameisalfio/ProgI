/* 12.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed uno short w, e 
restituisca in output un bool che indichi se esiste una 
riga di A in cui siano presenti almeno due stringhe 
consecutive in cui i primi w caratteri della prima 
stringa siano uguali agli ultimi w caratteri della 
seconda stringa (nello stesso ordine). */

#include <iostream>
#include <string>
#define n 2

using namespace std;

bool func (string A[n][n], short w){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){  //arrivo al penultimo elemento in modo da confrontarlo con l'ultimo elemento della riga
			if(A[i][j].substr(0,w) == A[i][j+1].substr(A[i][j+1].length()-w)){  /*Se i primi w caratteri della prima strigna sono 
			                                                                       uguali agli ultimi w caratteri della seconda    */
				return true;
			}else{
				return false;
			}
		}
	}
}

int main(){
	
	string A[n][n];
	short w = 3;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Inserisci stringa : "<<endl;
			cin>>A[i][j];
		}
	}
	
	bool esito = func(A, w);
	
	if (esito == true){
		cout<<"\nEsistono almeno due stringhe che rispettano la condizione data"<<endl;
	}else if (esito == false){
		cout<<"\nNon esistono nemmeno due stringhe che rispettano la condizione data"<<endl;
	}
}