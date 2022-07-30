#include <iostream>
#include <string>
using namespace std;

#include "stanza.h"

class trivani{
	private:
		
	public: 
	
	    trivani(){
	    	
		}
		
		void get_stanza(stanza s1, stanza s2, stanza s3){
			cout<<"Nome :"<<s1.get_nome()<<endl;
			s1.calcola_superficie();
			
			cout<<"Nome :"<<s2.get_nome()<<endl;
			s2.calcola_superficie();
			
			cout<<"Nome :"<<s3.get_nome()<<endl;
			s3.calcola_superficie();
		}
     	
     	void get_bagno(bagno b1, bagno b2){
     		b1.calcola_superficie();
     		b2.calcola_superficie();
		}
	
	
};

int main(){
	
	stanza s1("cucina", 7.6, 3.9);	
	stanza s2("stanza_da_letto", 5.5, 2.8);
	stanza s3("stanza_da_letto", 4.6, 8);
	bagno b1(4.6, 3.4);
	bagno b2(4.5, 7);
	cout<<"Numero cessi: "<<b1.num_bagno()<<endl;
	
	trivani y;
	y.get_stanza(s1, s2, s3);
	y.get_bagno(b1, b2);
	
}