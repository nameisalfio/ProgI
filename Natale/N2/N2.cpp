/*2. Due stringhe si dicono sorelle se hanno lo stesso 
numero di vocali. Scrivere un metodo che prenda in 
input una matrice A di puntatori a stringhe, e 
restituisca un boolean che indichi se esiste una 
colonna di A in cui sono puntate almeno due stringhe 
sorelle.*/

#include <iostream>
#include <string>
using namespace std;
#define n 3

bool funzione (string***A){
	
	int count=0;
	int count2=0;
	
	for(int j=0; j<n; j++){
		count=0;
		for(int i=0; i<n-1; i++){
			count2=0;
			if(A[i][j]){ //Se esiste la stringa
				for(int k=0; k<(*A[i][j]).length(); k++){
					if((*A[i][j])[k] == 'a' || (*A[i][j])[k] == 'e' ||
					   (*A[i][j])[k] == 'i' || (*A[i][j])[k] == 'o' ||
					   (*A[i][j])[k] == 'u'){
					   	count++;
					}
					for(int p=i; p<n; p++){
						if((*A[i+1][j])[k] == 'a' || (*A[i+1][j])[k] == 'e' ||
						   (*A[i+1][j])[k] == 'i' || (*A[i+2][j])[k] == 'o' ||
						   (*A[i+1][j])[k] == 'u'){
						    count2++;
					    }
					}
				    if(count == count2)
						return true;
				}
				
			}
		}
	}
	return false;
}

int main(){	

    string ***A = new string **[n];
    for(int i=0; i<n; i++){
    	A[i] = new string *[n];
    	for(int j=0; j<n; j++){
    		A[i][j] = new string;
    		cout<<"Inserisci stringa: "<<endl;
    		cin>>*A[i][j];
//			*A[i][j] = "Tino";
		}
	}
    
	bool esito = funzione(A);
	if(esito)
		cout<<"Esiste "<<endl;
    if(!esito)
		cout<<"Non esiste"<<endl;

}
