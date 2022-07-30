#include<iostream>

using namespace std;

int somma (int, int);  //prototipo

int main (){
	
	int a,b,c;
	
	cout<<"Inserisci a : "<<endl;
	cin>>a;
	cout<<"Inserisci b : "<<endl;
	cin>>b;
	cout<<"Inserisci c : "<<endl;
	cin>>c;

    cout<<"La somma vale : "<<somma (a, b)<<endl;  //invocazione inserendo i parametri della funzione main
    cout<<"La somma vale : "<<somma (a, c)<<endl; 
    cout<<"La somma vale : "<<somma (b, c)<<endl; 
	
	return 0;
}

int somma (int n1, int n2){  //definizione
	
	int s = n1 + n2;
	
	return s;
}