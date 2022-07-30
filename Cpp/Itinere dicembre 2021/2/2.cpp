/* Scrivere un metodo in C++ che prenda in input una matrice A di puntatori a stringhe
e un array B di caratteri. Il metodo operi sulle colonne di indice dispari di A depurandole 
dalle vocali eventualmente presenti in B. */

#include<iostream>
#include<string>
using namespace std;
#define n 2
#define m 3
#define l 4

void depura(string***A, char*B){
	
	string s;
	for(int i=0; i<l; i++){
		if( B[i] == 'a' ||
			B[i] == 'e' ||
			B[i] == 'i' ||
			B[i] == 'o' ||
			B[i] == 'u' ) s += B[i];
	}
	if(s.length() == 0)
		return;
		
	for(int j=1; j<m; j++){
		for(int i=0; i<n; i++){
			if(A[i][j]){
				for(int q=0; q<(*A[i][j]).length(); q++){
					for(int k=0; k<s.length(); k++){
						if( (*A[i][j])[q] == s[k] )
							(*A[i][j]).erase((*A[i][j]).find(s[k]),1);	
					}
				}
			}
		}
	}	
}

int main(){
	
	string***S = new string**[n];
	for(int i=0; i<n; i++){
		S[i] = new string*[m];
		for(int j=0; j<m; j++){
			S[i][j] = new string;
			*S[i][j] = "Ciao";
		}
	}
	
	char*B = new char [l];
	for(int i=0; i<l; i++){
		cout<<"Inserisci carattere "<<endl;
		cin>>B[i];
	}
	
	depura(S, B); 
	
	cout<<"La matrice depurata "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<*S[i][j]<<" ";
		}
		cout<<endl;
	}
}
