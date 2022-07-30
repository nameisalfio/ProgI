#include "Data.h"

Data::Data(int g, int m, int a){  //COSTRUTTORE
	giorno = g;
	mese = m;
	anno = a;
}

void Data::get_out(){
	cout<< giorno <<" / "<< mese <<" / "<< anno <<endl;
}

void Data::set_mod(int g, int m, int a){
	giorno = g;
	mese = m;
	anno = a;
} 

void val(){
	if(giorno>=1 && giorno<=31 && mese>=1 && mese<=12 && anno>=2000 && anno<=3000){
//	if(g>=1 && g<=31 && m>=1 && m<=12 && a>=2000 && a<=3000){
		cout<<"Data corretta"<<endl;
	}else{
		cout<<"Data errata"<<endl;
		return;
	}
}