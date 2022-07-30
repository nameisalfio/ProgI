#include <iostream>
#include <string>
using namespace std;

class Prodotto {
	private :
		string descrizione;
		double prezzo;
		int quantita;
	
	public :
		Prodotto() {
			descrizione = "Maglietta";
			prezzo = 10.50;
			quantita = 10;
		}
		
		string getDescrizione();
		void setDescrizione(string);
		
		double getPrezzo();
		void setPrezzo(double);
		
		int getQuantita();
		void setQuantita(int);
};

string Prodotto::getDescrizione(){
	return descrizione;
}

void Prodotto::setDescrizione(string d){
	descrizione = d;
}



double Prodotto::getPrezzo(){
	return prezzo;
}
void Prodotto::setPrezzo(double p){
	prezzo = p;
}



int Prodotto::getQuantita(){
	return quantita;
}

void Prodotto::setQuantita(int q){
	quantita = q;
}



int main(){
	
	string description;
	double price;
	int amount;
	
	Prodotto p1 ;
	cout<<"Descrizione : "<<p1.getDescrizione()<<endl;
	cout<<"Prezzo : "<<p1.getPrezzo()<<endl;
	cout<<"Quantita' : "<<p1.getQuantita()<<endl;
	cout<<endl<<endl;
	
	cout<<"Modifica descrizione : "<<endl;
	cin>> description;
	cout<<"Modifica prezzo : "<<endl;
	cin>> price;
	cout<<"Modifica quantita' : "<<endl;
	cin>> amount;
	cout<<endl<<endl;
	
	//MODIFICO GLI ATTRIBUTI PRIVATE USANDO I METODI SET
    p1.setDescrizione(description);
    p1.setPrezzo(price);
    p1.setQuantita(amount);
    
    //VISUALIZZO GLI ATTRIBUTI PRIVATE USANDO I METODI GET
    cout<<"Descrizione : "<<p1.getDescrizione()<<endl;
	cout<<"Prezzo : "<<p1.getPrezzo()<<endl;
	cout<<"Quantita' : "<<p1.getQuantita()<<endl;
}