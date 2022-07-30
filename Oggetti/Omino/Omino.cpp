#include <iostream>
#include <string>
using namespace std;

class Omino{
	private : 
	    string nome;
	    char sesso;
	    string statura;
	public : 
	    bool vestiti;
	    
	    Omino(string, char);
	    void set_statura(string);
	    string get_statura();
	    void set_vestiti(bool);
	    string get_vestiti();
	
};

Omino::Omino(string n, char s){
	nome = n;
	sesso = s;
	string genere;
	cout<<"Nome : "<<nome<<endl;
	if(s == 'M'|| s == 'm'){
		genere = "Maschile";
	}else if(s == 'F'||s=='f'){
		genere = "Femminile";
	}else{
		genere = "Non_binario";
	}
	cout<<"Sesso : "<<genere<<endl;
}

void Omino::set_statura(string st){
	statura = st;
}

string Omino::get_statura(){
	return statura;
}

void Omino::set_vestiti(bool v){
	vestiti = v;
}

string Omino::get_vestiti(){
	string vestito;
	if (vestiti)
		vestito = "Vestito";
	if (!vestiti)
	    vestito = "Nudo";
	return vestito;
}

int main(){
	string n;
	char s;
	
	cout<<"Resoconto di Alfio"<<endl;
	Omino Alfio("Alfio", 'M');
	Alfio.set_statura("Alto");
	cout<<"Statura : "<<Alfio.get_statura()<<endl;
	Alfio.set_vestiti(true);
	cout<<"Vestito : "<<Alfio.get_vestiti()<<endl;
	cout<<endl<<endl;
	cout<<"Resoconto di Flavio"<<endl;
	Omino Flavio("Flavio", 'M');
	Flavio.set_statura("Alto");
	cout<<"Statura : "<<Flavio.get_statura()<<endl;
	Flavio.set_vestiti(true);
	cout<<"Vestito : "<<Flavio.get_vestiti()<<endl;
	cout<<endl<<endl;
	cout<<"Resoconto di Nino"<<endl;
	Omino Nino("Nino", 'X');
	Nino.set_statura("Magro");
	cout<<"Statura : "<<Nino.get_statura()<<endl;
	Nino.set_vestiti(true);
	cout<<"Vestito : "<<Nino.get_vestiti()<<endl;
	
}