
#include <iostream>
#include <string>

using namespace std;

int main (){
	
	int x = 5;
	
	int *x_ptr = &x;
	int **x_ptr_ptr = &x_ptr;
	
	cout<<" x : "<<x<<endl<<endl;
	cout<<" x_ptr : "<<x_ptr<<endl<<endl;
	cout<<" x_ptr_ptr : "<<x_ptr_ptr<<endl<<endl;
	cout<<" *x_ptr : "<<*x_ptr<<endl<<endl;
	cout<<" *x_ptr_ptr : "<<*x_ptr_ptr<<endl<<endl;

	return 0;
	
}