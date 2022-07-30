#include <iostream>
#include <typeinfo>

using namespace std;

//Puntatori----------------------------------------------------------------------
void extremes (int v[],int n, int* max, int* min){

	*max = *v; //identico a " *max = v[0] "
	*min = *v;

	for(int i=0; i<n; i++)
	{
		if(v[i] > *max)
			*max = v[i];
		if(v[i] < *min)
			*min = v[i];
	}
}

int main(){

	cout << endl;

	//int* vet = new int[10]{1,2,3,4,5,6,7,8,9,10};
	int vet[10]{1,2,3,4,5,6,7,8,9,10};
	int max;
	int min;

	int dim = sizeof(vet)/sizeof(vet[0]);
	cout << "Dimensione: " << dim << endl;

	extremes(vet, dim, &max, &min);

	cout << "Vettore: " << endl;
	for(int i=0; i<10; i++)
		cout << vet[i] << " ";

	cout << "\tMassimo: " << max << "\tMinimo: " << min << endl;

	cout << endl;
}

//Reference ----------------------------------------------------------------------
int main(int argc, char *argv[]){

	cout << endl;

	int a = 10;
	int b = 32;

	int& aref = a;
	int& bref = b;

	cout << "aref= " << aref << "    " << "a= " << a << endl;
	cout << "bref= " << bref << "    " << "b= " << b << endl << endl;

	bref = aref; //copia lo stato dell'oggetto aref(o a) in bref(b)

	cout << "aref= " << aref << "    " << "a= " << a << endl;
	cout << "bref= " << bref << "    " << "b= " << b << endl << endl;

	bref++; //incrementa bref(e b) ma aref(e a) rimangono invariati

	cout << "aref= " << aref << "    " << "a= " << a << endl;
	cout << "bref= " << bref << "    " << "b= " << b << endl;

	cout << endl;
}