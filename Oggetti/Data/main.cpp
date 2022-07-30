/* Scrivi una classe D (data) i cui oggetti possano essere inizializzati come: d(22,08,01); 
implementare il costruttore, il metodo out() per la stampa a video, il metodo mod(gg,mm,aa) per
 consentirne la modifica e un metodo val() per consentire la validazione della data .
*/

#include <iostream>

using namespace std;

#include "Data.cpp"

int main(){
	
	Data d(18,12,21);
	cout<<"Data prima"<<endl;
	d.get_out();
	
	cout<<endl;
	
	d.set_mod(19,12,21);
	cout<<"Data dopo"<<endl;
	d.get_out();
	
	cout<<endl;
	
	
}

