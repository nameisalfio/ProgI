#include<iostream>
#include<string>
using namespace std;

/*bool triangolare_superiore(int **M, int n){
	
	for(int i=0; i<n; i++){
		for(int j=0; j=i; j++){
			if(i!=j){
				if(M[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool triangolare_inferiore(int **M, int n){
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i!=j){
				if(M[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}*/

bool triangolare_superiore(int **M, int n){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i>j){
				if(M[i][j] == 0)
					return true;
			}
		}
	}
	return false;
}

bool triangolare_inferiore(int **M, int n){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j){
				if(M[i][j] == 0)
					return true;
			}
		}
	}
	return false;
}

int main(){
	int n = 3;
	
	int**a = new int*[n];
	for(int i=0; i<n; i++){
		a[i] = new int[n];
		for(int j=0; j<n; j++){
//			cout<<"Inserisci intero "<<endl;
//			cin>>a[i][j];
            a[i][j] = 0;
		}
	}
	cout<<"\n--------"<<endl;
	cout<<"La matrice : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	bool esito = triangolare_superiore(a, n);
	if(esito)
	cout<<"\nLa matrice e' triangolare superiore "<<endl;
	else
	cout<<"\nLa matrice non e' triangolare superiore "<<endl;
	
	bool esito2 = triangolare_inferiore(a, n);
	if(esito2)
	cout<<"\nLa matrice e' triangolare inferiore "<<endl;
	else
	cout<<"\nLa matrice non e' triangolare inferiore "<<endl;
	
	if(esito && esito2)
	cout<<"\nLa matrice e' triangolare superiore e inferiore "<<endl;
	
}