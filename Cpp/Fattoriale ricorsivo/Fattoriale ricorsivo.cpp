#include<iostream>
using namespace std;

int fattoriale(int n){
	if(n == 0)
		return 1;
	return
		n * fattoriale(n-1);
}

/*template <typename T>
T fattoriale(T n){
	if(round(n) == 0)
		return 1;
	return
		n * fattoriale(n-1);
}*/

int main(){

	int a;
	cout<<"Inserisci un numero : "<<endl;
	cin>>a;
	cout<<"Fattoriale di "<<a<<" = "<<fattoriale(a)<<endl;
}