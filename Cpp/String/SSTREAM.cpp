#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
	
	//CONVERSIONE DEI NUMERI IN CARATTERI
	
	stringstream ss;  //creazione del buffer
	double g = 38.456789;
	ss<<g<<endl;  //inserimento dei caratteri nel buffer
	
	string my_number = ss.str();
	
	cout<<my_number<<endl<<endl;
	cout<<setprecision(1000)<<g<<endl;  //stampa g alla massima precisione possibile dopo la virgola
	
	cout<<"Sovrascrivi my_number : "<<endl;
	cin>>my_number;  //Sovrascrizione del buffer 
	cout<<"Adesso my_number : "<<my_number<<endl; 
	
	//CONVERSIONE DI STRINGHE IN NUMERI
	
/*	stringstream ss;  
	double y;
	ss << "28.2920";
	ss >> y;
	
	cout<<"y : "<<y<<endl;
	*/
	
}