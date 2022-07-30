#include <iostream>
#include <string>
using namespace std;

#include "Veicolo.h"
#define N 10

class parcheggio{
	private:
		int capienza;
		int indirizzo;
		Veicolo* vet[N];
		
	public:
		parcheggio(){
			capienza = N;
			for(int i=0; i<capienza; i++){
				vet[i] = nullptr;
			}
		}
		
		int inserisci(Veicolo* v){
			for(int i=0; i<capienza; i++){
				if(vet[i] == nullptr){
				    vet[i] = v;
				    return i;
			    }
			}
			return -1;
			cerr<<"Parcheggio pieno!"<<endl;
		}
		
		Veicolo* rimuovi(int x){
			Veicolo* v = vet[x];
			vet[x] = nullptr;
			return v;
		}
		
		double get_tariffa(Veicolo x, int giorni){
			int tariffa;
			if(x.get_tipologia() == "Automobile")
			tariffa = 4.5 * giorni;
			else if(x.get_tipologia() == "Motociclo")
			tariffa = 3.5 * giorni;
			else if(x.get_tipologia() == "Furgone")
			tariffa = 5 * giorni;
			else if(x.get_tipologia() == "Mezzo_pesante")
			tariffa = 7 * giorni;
			
			return tariffa;
		}
		
		int conta_veicoli (){
			int veicoli;
			for(int i=0; i<capienza; i++){
				if(vet[i] != nullptr){
				    veicoli++;
			    }
			}
			return veicoli;
		}
		
		int conta_posti (){
			int posti;
			for(int i=0; i<capienza; i++){
				if(vet[i] == nullptr){
				    posti++;
			    }
			}
			return posti;
		}
		
		int posto_libero(){
			for(int i=0; i<capienza; i++){
				if(vet[i] == nullptr){
				    return i;
			    }
			}
			return -1;
			cerr<<"Parcheggio pieno!"<<endl;
		}
		
	    void prova(){
	    	for(int i=0; i<capienza; i++){
				cout<<"Parcheggio numero "<<i<<" "<<vet[i]<<endl;
			}
		}
};

int main(){
	parcheggio P;
	Veicolo x("PuntoEVO", 4, "Automobile");
	
	Veicolo* w = &x;
	int stallo = P.inserisci(w);
	cout<<"Il numero di stallo del primo veicolo : "<<stallo<<endl;
	cout<<"Tipologia del primo veicolo : "<<x.get_tipologia()<<endl;
	w = P.rimuovi(0);
	cout<<"Veicolo rimosso : ";
	w->nome_veicolo();
	cout<<"La tariffa da pagare : "<<P.get_tariffa(x, 3)<<endl;
	P.inserisci(w);
	cout<<"Posti disponibili : "<<P.conta_posti()<<endl;
	cout<<"Veicoli parcheggiati : "<<P.conta_veicoli()<<endl;
	stallo = P.posto_libero();
	cout<<"Il primo stallo libero : "<<stallo<<endl;
	
}