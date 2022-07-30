#include <iostream>
#define n 5
using namespace std;

int**func (int v[n]){
	int**vet = new int *[n];
	for(int i=0; i<n; i++){
		vet[i] = new int;
		*vet[i] = 2 * v[i];
	}
return vet;

}

int main(){

int v[n];
for(int i=0; i<n; i++){
	cout<<"Inserisci un elemento nell'array : "<<endl;
	cin>>v[i];
}

int**vet = func(v);

cout<<"L'array doppio : "<<endl;
for(int i=0; i<n; i++){
	cout<<*vet[i]<<" ";
}
	
}