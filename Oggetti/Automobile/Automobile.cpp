#include<iostream>
#include<string>
using namespace std;

#include "Persona.h"

class Automobile{
	private:
		string modello;
		Persona &proprietario;
	    
	public:
		Automobile(string modello, Persona& p) : proprietario(p){
			this->modello = modello;
		}
		
		void stampa (){
			cout<<"Automobile di "<<proprietario<<endl;
		}
		
		void set_proprietario (Persona& p){
			proprietario = p;
		}
		
};

int main(){
	
    Persona p1("Mario", "Rossi");
    Persona p2("Giuseppe", "Verdi");
    
    Automobile a1("Automobile1", p1);
    Automobile a2("Automobile2", p1);
    Automobile a3("Automobile3", p2);
    
    a2.stampa();
    a2.set_proprietario(p2);
    a2.stampa();
}