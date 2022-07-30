#include <iostream>
#include <string>
using namespace std;

#include "bagno.h"

class stanza{
	private: 
	    string nome;
	    double n;
	    double m;
	    
	public:
		stanza(string nome, double n, double m){
			this->nome = nome;
			this->n = n;
			this->m = m;
		}
		
		string get_nome(){
			return nome;
		}
		
		void calcola_superficie(){
			cout<<"La superficie della stanza e' :"<<n*m<<endl;
		}
};
