#include<iostream>

using namespace std;

int main(){

	int vet[5]{2,4,6,8,10};

	int* ptr = vet;

	//Valore del primo elemento
	cout << "\n*vet: " << *vet << endl;
	cout << "\nvet[0]: " << vet[0] << endl;
	cout << "\n*ptr: " << *ptr << endl;

	//Indirizzo in memoria del primo elemento
	cout << "\nvet: " << vet << endl;
	cout << "\n&vet: " << &vet << endl;
	cout << "\n&vet[0]: " << &vet[0] << endl;
	cout << "\nptr: " << ptr << endl;

	//Accesso al 4 elemento
	cout << "\nvet[3]: " << vet[3] << endl;
	cout << "\n*(vet+3): " << *(vet+3) << endl;

	int mat[3][3];

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			mat[i][j] = i+j;
	}

	cout << "\nPrima stampa: " << endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	cout << "\nSeconda stampa: " << endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout << *(*mat+i)+j << " ";
		cout << endl;
	}

	cout << endl;
}