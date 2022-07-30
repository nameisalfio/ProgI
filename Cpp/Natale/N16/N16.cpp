/*16.Due stringhe si dicono c-equivalenti se esse 
risultano uguali dopo aver eliminato da ambedue tutte 
le occorrenze del carattere c. Scrivere un metodo che 
prenda in input una matrice A di puntatori a stringhe 
ed un carattere c, e restituisca un boolean che indichi 
se esistono in A due stringhe c-equivalenti.
*/

#include<iostream>
#include<string>
using namespace std;
#define n 3

bool func(string***A, char c){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<*A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	string *S = new string[n*n];
	int idx=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(A[i][j]){
				for(int k=0; k<(*A[i][j]).length(); k++){
					if((*A[i][j])[k] == c)
						(*A[i][j])[k] = NULL;
				}
				S[idx++] = (*A[i][j]);
			}
		}
	}
	
	for(int i=0; i<idx-1; i++){
		for(int j=i+1; j<idx; j++){
			if(S[i] == S[j])
				return true;
		}
	}
	
	return false;

}
int main(){
	char c = 'c';
	
	string ***A = new string**[n];
	for(int i=0; i<n; i++){
		A[i]=new string *[n];
		for(int j=0; j<n; j++){
			A[i][j] = new string;
			cout<<"Stringa :"<<endl;
			cin>>*A[i][j];
		}
	}
	
	bool esito = func(A, c);
	if (esito == true){
		cout<<"\nStringhe c equiv."<<endl;
	}else{
		cout<<"\nNon c equivalenti."<<endl;
	}
}