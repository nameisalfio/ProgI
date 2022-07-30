#include <iostream>

using namespace std;

int* somma (int *&n1, int *&n2);  //prototipo della funzione somma

int main() {
	
	int v = 10;
	int *p ;
	p = &v;
	
	cout<<p+1;
	
	
	int mat [2][2];
	
	mat [0][0] = 10;
	mat [0][1] = 12;
	mat [1][0] = 40;
	mat [1][1] = 42;
	
	cout<<"Matrice : \n"<<endl;
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<" "<<mat [i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\nElementi della matrice : "<<endl;
	
	cout<<"\nRiga 0 elem. 0 (adress mem.) : "<<mat[0]<<endl;
	cout<<"Riga 0 elem. 1 (adress mem.) : "<<mat[0]+1<<endl;  //algebra dei puntatori : punto all'elemento successivo a "mat[0]"
    cout<<"Riga 1 elem. 0 (adress mem.) : "<<mat[1]<<endl;
	cout<<"Riga 1 elem. 1 (adress mem.) : "<<mat[1]+1<<endl;  //algebra dei puntatori : punto all'elemento successivo a "mat[1]"
	
	cout<<"\nRiga 0 elem. 0  : "<<*mat[0]<<endl;
	cout<<"Riga 0 elem. 1  : "<<*(mat[0]+1)<<endl;  //algebra dei puntatori : punto all'elemento successivo a "mat[0]"
    cout<<"Riga 1 elem. 0  : "<<*mat[1]<<endl;
	cout<<"Riga 1 elem. 1  : "<<*(mat[1]+1)<<endl;  //algebra dei puntatori : punto all'elemento successivo a "mat[1]"
	
	cout<<"\n"<<mat[1] - mat[0]<<endl;  //numero di elementi che separano la prima dalla seconda riga
	cout<<"\n"<<(mat[1] - mat[0]) * sizeof(int) <<endl;  //spazio in byte che separa la prima riga dalla seconda
	
	int v2 = 50;
	int *p2;
	p2 = &v2;
	cout<<"p : "<<*p<<endl;
	cout<<"p2 : "<<*p2<<endl;
	
	int *ris = somma(p, p2); //ris è un puntatore ad intero. Si usa l'asterisco nell'assegnamento perchè lo si è dichiarato nella stessa riga
	                         
							 /*Posso passare p e p2 come delle normali variabili, quindi senza "&" , grazie alla sintassi
	                           usata alla riga 63, nonostante sia un passaggio di valori PER INDIRIZZO.
							   Di norma la sintassi sarebbe:
							                                int *ris = somma(&p, &p2);
							   */
							   
	cout<<"\nSomma di p e p2 : "<<*ris<<endl;  //stampo il valore che si trova all'indirizzo ris
	
	
	return 0;
	
}

int* somma (int *&n1, int *&n2){  //n1 ed n2 sono indirizzi : si premette il simbolo "*" per ricavare il valore contenuto nell'indirizzo
	
	int *v;
	v = new int;  //assegno a v un nuovo indirizzo dato dal sistema e non dal programmatore o dall'utente
	*v = (*n1 + *n2);  //la somma dei valori viene messa in *v (variabile temporanea)
	
	return v;  //restituisce il puntatore della variabile v

}