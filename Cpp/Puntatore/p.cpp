#include <iostream>

using namespace std;

int main(){
	
	int x=5;
	
	int *ptr;
	ptr = &x;
	cout<<ptr<<endl;
	
	ptr = nullptr;
	cout<<ptr<<endl;
	
	int var = 8;
	const int* var_ptr = &var;  //puntatore di sola lettura (const int)*
	
	cout<<var_ptr<<endl;
	cout<<*var_ptr<<endl;
	
//	*var_ptr = 5;  //ERRORE non posso modificare il valore puntato da un puntatore di sola lettura (puntatori a costanti)
	
	int var2;
	int* const var2_ptr = &var2;  //puntatore costante (int)* const
	
	cout<< *var2_ptr<<endl;
	*var2_ptr = -2;
	cout<<var2<<endl;
	
//	var2_ptr = &x; //ERRORE non posso modificare l'indirizzo puntato da un puntatore costante
    
    int var3 = -9;
    const int* const var3_ptr = &var3;
    
    cout<< *var3_ptr<<endl;
//    *var3_ptr = 10;  //ERRORE non posso modificare né il valore puntato , nè la locazione di memoria a cui punto
    cout<<var3<<endl;
    
	
}