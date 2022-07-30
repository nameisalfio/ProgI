#include <iostream>
#include <string>

using namespace std;

#include "computer.cpp"  //includo la classe

int main() {
	
	cout<<"Resoconto di c : \n"<<endl;
	computer c("ASUS", 729.69);
	c.Accenditi(); //Invocazione del metodo
/*	c.impostaMarca("ASUS");
	c.impostaPrezzo(729.69);  */
	cout<<"Marca : "<<c.getMarca()<<endl;
	cout<<"Prezzo : "<<c.getPrezzo()<<endl;
	cout<<endl;
	
	cout<<"Resoconto di x : \n"<<endl;
	computer x("HP", 300.79);
	
//	x.marca = "Nuova Marca";
//	x.prezzo = 800;
	
	x.Accenditi();
	cout<<"Marca : "<<x.getMarca()<<endl;
	cout<<"Prezzo : "<<x.getPrezzo()<<endl;
    cout<<endl;
    
}