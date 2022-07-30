#include <iostream>

using namespace std;

float somma (int);
float average (float, int);

int main (){
	int n;
	cout<<"Quanti numeri vuoi inserire : "<<endl;
	cin>>n;
	
	float sum = somma(n);  //invocazione somma
	cout<<"La somma vale : "<<sum<<endl;
	
	float media = average(somma, n);  //invocazione average
	cout<<"La media vale : "<<average<<endl;
}

float somma (int n){
	float val;
	float somma=0;
	
	for(int i=0; i<n; i++){
		cout<<"Inserisci un valore : "<<endl;
		cin>>val;
		somma += val;
	}
	return somma;
}

float average (float somma, int n){
	float avg;
	sum = somma(n);
	avg = sum/n;  //invocazione somma
	return avg;
}