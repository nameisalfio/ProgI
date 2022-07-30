#include "computer.h"

computer::computer(string m, float p)  //COSTRUTTORE
{
	//Nel costruttore possiamo inizializzare le variabili
	acceso = false;
	marca = m; 
	prezzo = p;
}

void computer::Accenditi()  //Dichiarazione metodo--> tipo di ritorno   nome classe :: nome metodo()
{
	if(!acceso){
		acceso = true;
		cout<<"Ora sono acceso !"<<endl;
	}else{
		cout<<"sono gia' acceso !"<<endl;
	}
}

void computer::Spegniti()
{
	if(acceso){
		acceso = false;
		cout<<"Ora sono spento !"<<endl;
	}else{
		cout<<"sono gia' spento !"<<endl;
	}
}

void computer::impostaMarca(string m)
{
	marca = m;
	
}

void computer::impostaPrezzo(float p)
{
	prezzo = p;
}

//METODI GET (PER CONVENZIONE) 
//sono metodi che hanno un valore di ritorno

string computer::getMarca()
{
	return marca;
}

float computer::getPrezzo()
{
	return prezzo;
}