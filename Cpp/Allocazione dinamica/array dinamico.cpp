#include <iostream>

using namespace std;

int *func(int *array, int k){
	int *arr = new int [k];  //alloc. dinamica
	
	for(int i=0; i<k; i++){
	    cout<<"Inserisci un valore : "<<endl;
	    cin>>array[i];
	}
	
	for(int i=0; i<k; i++){
		arr[i] = 2*array[i];
	}
	
	return arr;
}

int main(){
	
	int k;
	cout<<"Inserisci la dimensione dell'array "<<endl;
	cin>>k;
	
	int array[k];
	int *vett = func (array, k);
	
	cout<<"Array doppio "<<endl;
	for(int i=0; i<k; i++){
		cout<<vett[i]<<" ";
	}

}