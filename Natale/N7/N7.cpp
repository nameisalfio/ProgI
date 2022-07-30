/* 7.Scrivere un metodo che prenda in input un 
parametro formale matrice A di puntatori ad interi di 
dimensione nxm, due double d1 e d2 ed uno short s, e 
restituisca il numero di colonne di A nelle quali 
esistano almeno s coppie di elementi contigui 
(ES: A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il 
secondo elemento sia compreso tra d1 e d2. 

NB: Si assuma a priori che s<=n-1 e che d1 < d2. 
Si presti attenzione ai numeri "mancanti"nella matrice A.
*/

#include <iostream>
#define n 4
#define m 3

using namespace std;

void print (int ***Q){
	cout<<"Matrice: "<<endl;
	cout<<"----------------------------"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<*Q[i][j]<<" ";
		}
		cout<<endl;
	}
}

int func (int***A, double d1, double d2, short s){
	
	int count = 0;
	int numero = 0;
	print(A);

	for(int j=0; j<m; j++){
		count = 0;
		for(int i=0; i<n-1; i++){
			if(A[i][j]){
				if((double)*A[i][j]/ *A[i+1][j]>d1 && (double)*A[i][j]/ *A[i+1][j]<d2)
					count++;
			}
		}
		if(count >= s)
			numero++;
		count = 0;
	}
	return numero;
}

int main(){
	
	double d1 = 0, d2 = 1;
	short s = 3;
	
	int ***A = new int **[n];
	for(int i=0; i<n; i++){
		
		A[i] = new int *[m];
		for(int j=0; j<m; j++){
			
			A[i][j] = new int ;
			cout<<"Inserisci un valore nella matrice : "<<endl;
			cin>>*A[i][j];
		}
	}
	
	int numero = func(A, d1, d2, s);
	cout<<"Il numero di colonne e': "<<numero<<endl;
}