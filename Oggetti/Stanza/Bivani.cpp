#include <iostream>
#include <string>
using namespace std;

#include "stanza.h"

class bivani {
	
	private:
		
	public: 
	    bivani(){
	    	
		}
		
		void get_stanza(stanza s1, stanza s2){
			cout<<"Nome : "<<s1.get_nome()<<endl;
			s1.calcola_superficie();
			
			cout<<"Nome : "<<s2.get_nome()<<endl;
			s2.calcola_superficie();
		}
		
		void get_bagno(bagno b){
			b.calcola_superficie();
		}
	    
};

int main(){
	
	stanza s("stanza_da_pranzo", 2.4, 1.8);
	cout<<"Nome: "<<s.get_nome()<<endl;
	s.calcola_superficie();
	
	bagno b(2.5, 3.8);
	b.calcola_superficie();
	
	stanza s1("cucina", 7.6, 3.9);	
	stanza s2("stanza_da_letto", 5.5, 2.8);
	bagno b1(4.6, 3.4);
	
	bivani x;
	x.get_stanza(s1, s2);
	x.get_bagno(b);
	cout<<"Numero cessi: "<<b.num_bagno();
}