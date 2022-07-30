#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Persona{
	private:
		
		//Attributi
		string nome;
		string cognome;
		int eta;
		
	public:
		
		//Metodi
		Persona(string nome, string cognome, int eta){ //Costruttore
		    this->nome = nome;
			this->cognome = cognome;
			this->eta = eta;	
		}
		
		void saluta(){
			srand(time(NULL));
			int r = rand()%3;
			
			if(r==0)
			cout<<"Buongiorno"<<endl;
			if(r==1)
			cout<<"Buonasera"<<endl;
			if(r==2)
			cout<<"Ciao"<<endl;
		}
		
		void dici_nome(){
			cout<<"Mi chiamo "<<nome<<" "<<cognome<<endl;
		}
		
		void dici_eta(){
			cout<<"La mia eta' e' "<<eta<<endl;
		}
		
		void invecchia(){
			eta++;
		}
		
		void saluta_persona(Persona m, Persona a){
			if(m.eta > a.eta)
			cout<<"Buongiorno ";
			else
			cout<<"Ciao ";
			cout<<m.nome<<" "<<m.cognome<<", piacere di conoscerti"<<endl;
		}
		
		void set_nome(string nome){
			this->nome = nome;
		}
		
		string get_nome(){
			return nome;
		}
		
		void set_cognome(string cognome){
			this->cognome = cognome;
		}
		
		string get_cognome(){
			return cognome;
		}
		
		void set_eta(int eta){
			this->eta = eta;
		}
		
		int get_eta(){
			return eta;
		}
};

int main(){
	Persona p("Alfio", "Spoto", 20);
	p.saluta();
	p.dici_nome();
	p.dici_eta();
    
    Persona x("Mattia", "Maccarrone", 21);
    cout<<endl;
    p.saluta_persona(x, p);
    
    for(int i=0; i<10; i++){
		p.invecchia();
	}
    cout<<"Dopo dieci anni ...."<<endl;
    p.dici_eta();
    
    //Imposto il metodo setter per modificare un attributo private
    p.set_nome("Giorgio");
    //Uso il metodo getter per visualizzare il contenuto
    cout<<"Adesso mi chiamo "<<p.get_nome()<<endl;
    p.set_cognome("Trombetta");
    cout<<"Adesso il mio cognome e' "<<p.get_cognome()<<endl;
    p.set_eta(40);
    cout<<"Adesso la mia eta' e' "<<p.get_eta()<<endl;
    
    for(int i=0; i<10; i++){
		p.invecchia();
	}
    cout<<"Dopo altri dieci anni ...."<<endl;
    cout<<"Adesso la mia eta' e' "<<p.get_eta()<<endl;

}