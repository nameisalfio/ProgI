#include <iostream>
using namespace std;

int main(){
	int a = 69;
	int b = 2;
	int &aref = a;
	int &bref = aref;
	bref = aref;
    int x = bref + aref;
    cout<<"aref "<<aref<<endl;
	cout<<"bref "<<bref<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<x<<endl;
}