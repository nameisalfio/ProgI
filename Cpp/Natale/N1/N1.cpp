/* 1.Un santone induista si trova nella regione indiana del 
Rajasthan, quest'ultima simulata con una matrice 
quadrata di boolean in cui il valore true indica la 
presenza di un libro sacro.
 
Scrivere un metodo che prenda in input una matrice di boolean 
e restituisca il numero di libri raccolti dal santone che, partendo dal 
centro della regione, esegue un movimento casuale 
unitario alla volta in una delle quattro direzioni prima 
che egli sia traviato dalle usanze oltre colonne. */

#include <iostream>
#include <cstdlib>
#define N 5

using namespace std;

int funzione(bool (mat)[N][N]){  
	
	int r, count = 0;
	
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout<<"Inserisci bool: ";  //INSERIMENTO DI 25 VALORI BOOL "0"/"1"
			cin>>mat[i][j];
		}
	}
	
	int i=(N-1)/2 ;
	int j=(N-1)/2 ; 
	
	cout<<"\nMovimenti consentiti : \n'0'-->Alto\n'1'-->Destra\n'2'-->Basso\n'3'-->Sinistra"<<endl<<endl;

	while(i >= 0 && i<N && j>= 0 && j<N){
		
		cout<<"Inserisci il movimento: ";
		cin>>r;

		if(r == 0){
			i--;
		}
		if(r == 1){
			j++;
		}
		if(r ==2){
			i++;
		}
		if(r ==3) {
			j--;
		}
		if(mat[i][j] == true){
			count++;
		}
    }
    return count;
}
	
int main(){
	
	bool mat[N][N];
	
	int libri = funzione(mat);
	cerr<<"Traviato dalle usanze oltre colonne!!!"<<endl;
	cout<<"Libri trovati : "<<libri<<endl; 
	
	return 0;
}	