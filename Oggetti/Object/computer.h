#ifndef COMPUTER_H
#define COMPUTER_H

class computer {
	
	private :
		
		//ATTRIBUTI
		string marca;
		float prezzo;
		bool acceso;
		
	public :
		
		//ATTRIBUTI
//		string marca;
//		float prezzo;
//		bool acceso;
		
		//METODI
		computer(string m, float p); //costruttore
		void Accenditi();
		void Spegniti();
		void impostaMarca(string m);
		void impostaPrezzo(float p);
		float getPrezzo();
		string getMarca();
	
};

#endif

