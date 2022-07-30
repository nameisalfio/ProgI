#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*int* fun(){  //voglio restituire un array di interi , quindi il tipo di ritorno è un puntatore ad interi

	int *x = new int [5] {1,2,3,4,5};
	return x;
}

int main(){
	int *x = fun();  //invocazione
	
	cout<<x[3];
	
	delete[] x;  //deallocazione
	x = nullptr;
	
	if(x)  //se x è vero, quindi è ancora in memoria , stampa x[3]
	cout<<x[3];
}*/

//ALLOCAZIONE DINAMICA DELLA MATRICE

/*x = 0;  //segmento DATA (globale)

int** fun(){
	
	int **v = new int *[3];
	
	for(int i=0; i<3; i++){
		v[i] = new int[4];  //alloco dinamicamente l'array interno
		
		for(int j=0; j<4; j++){
			v[i][j] = 0;
		}
	}
	
	return v;
	
}


int main(){
	
	
}
*/
/*
//RITORNO DI DUE VALORI
void minmax (int x, int y, int &min, int&max){
	min = (x<y) ? x : y ;
	max = (x>y) ? x : y ;
}

int main(){
	int x = 3;
	int y = 2;
	
	int min,max;
	
	minmax(x,y,min,max);
	
	cout<< min <<" "<< max <<endl;
}*/

/*void print_strmat(string***S, int rows, int cols){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			cout<< setw(5) << *S[i][j]<<endl;
		}
		cout<<endl;
	}
}

int main(){
	
	const int rows = 3 ;
	const int cols = 3 ;
	
	string ***S = new string**[2];
	
	for(int i=0; i<2; i++){
		S[i] = new string*[2];
		for(int j=0; j<2; j++){
			S[i][j] = new string("abc");
		}
	}
	
	print_strmat(S, 2, 2);
}
*/

//MATRICE DI PUNTATORI AD INTERI
int ***get_array (int M, int N, int P){  //compila la matrice di puntatori con valori crescenti a partire da 1
	
	int c = 1;
	
	int ***x = new int**[M];
	
		for(int i=0; i<M; i++){
			x[i] = new int * N;
			for(int j=0; j<N; j++){
				x[i][J] = new int * P;
				for(int k=0; k<P; k++){
					
					x[i][j][k] = c++;
		        }   	
		    }
		}
}

int main(){
	
	int *** R = get_array (M,N,P);
	
}


