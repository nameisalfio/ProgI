#include <iostream>
#include <string>
using namespace std;

class Persona{
	private: 
		string nome;
		string cognome;
		
	public:
		Persona(string _nome, string _cognome) : nome(_nome), cognome(_cognome){
		};
		
		string get_nome()const{
			return nome;
		}
		
		string get_cognome()const{
			return cognome;
		}
		
		friend ostream& operator<< (ostream& , Persona& );
};

	ostream& operator<< (ostream& s, Persona& p){
		s<<p.nome<<" "<<p.cognome<<endl;
		return s;
	}