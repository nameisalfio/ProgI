/*Scrivere un metodo che prenda in input un parametro formale 
matrice M di dimensioni n × m di puntatori a stringhe, e che
restituisca true se esiste almeno una colonna in M che abbia
un egual numero di stringhe palindrome di una delle righe di M.*/

#include <iostream>
#include <string>
using namespace std;
#define n 3
#define m 2

bool func(string***M){
	int col;
	int rig;
	bool palindromec = true;
	bool palindromer = true;
	
	cout<<"La matrice : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<" "<<*M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int y=0; y<m; y++){
		col=0;
		for(int x=0; x<n; x++){
				for(int i=0, j=(*M[x][y]).length()-1; i<j; i++, j--){
					if((*M[x][y])[i] != (*M[x][y])[j])
						palindromec = false;	
				}
			if(palindromec)
			col++;
		}	
	}
	
	for(int x = 0; x<n; x++){
		rig = 0;
		for(int y = 0; y<m; y++){
			for(int i=0, j=(*M[x][y]).length()-1; i<j; i++, j--){
					if((*M[x][y])[i] != (*M[x][y])[j])
						palindromer = false;
				}
				if(palindromer)
					rig++;
		}
	}
	
	if(col == rig)
	return true;
	else 
	return false;
	}
	


int main(){


	string ***M = new string **[n];
	for(int i = 0; i<n; i++){
		M[i] = new string*[m];
		for(int j = 0; j<m; j++){
			M[i][j] = new string;
			cout<<"Inserisci stringa: "<<endl;
			cin>>*M[i][j];
//			*M[i][j] = "ANNA";
		}
	}
	
	bool esito = func(M);
		if (esito)
		cout<<"\nEsiste";
		if(!esito)
		cout<<"\nNon esiste";
}
