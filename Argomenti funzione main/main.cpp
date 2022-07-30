#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	//argc -> argoument count
	//argv[] -> argoument vector

	int x = atoi(argv[1]);
	cout << x ;

	if(x%2)
		cout << "\nDispari";
	else
		cout << "\nPari";

	cout << endl;

}