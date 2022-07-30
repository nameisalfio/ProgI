/* Progettare e implementare una classe Carta che rappresenti una carta da gioco. 
Ogni carta deve avere un seme e un valore. Definire dunque una classe Mazzo che 
rappresenti un mazzo di 40 carte. Il mazzo deve permettere di estrarre casualmente 
una carta, contare il numero di carte rimanenti e rimescolare le carte. 
Scrivere un programma che permetta di giocare contro il computer al gioco “sette e mezzo”. */

#include <iostream>
#include <ctime>
using namespace std;
#define N 40

#include "Carta.h"
class Mazzo{
	private:
		Carta *deck[N];
		static int card;
	public:
		
	Mazzo(){
		srand(time(NULL)); //Seed
		string seme;
    	
    	int i=0;
    	for(int s=1; s<=4; s++){
    		for(int valore=1; valore<=10; valore++){
	    		if(s == 1)
			    seme = "Denari";
				if(s == 2)
				seme = "Spade";
				if(s == 3)
				seme = "Mazze";
				if(s == 4)
				seme = "Coppe";
				deck[i++] = new Carta(valore, seme); //Costruisce le carte
			}
		}
	}
		
	Carta* estrai(){
	
		if(conta_carte()==0)
		return nullptr;
		
		int i;
		Carta* p = nullptr; //Clear
		do{
		    i = rand()%N;
			p = deck[i];
		}while(p == nullptr);  //Esce quando la cond. è falsa
		
		deck[i] = nullptr;  //Segna la carta come pescata
		return p;
	}
	
	int conta_carte(){
		int count=0;
		for(int i=0; i<N; i++)
			if(deck[i])
			count++;
	
		return count;
	}
	
	int carte_rimanenti(){
		return card--;
	}
	
	void mescola(){
    	
	}
};

int Mazzo::card=40;

int main(){
	
	Mazzo d;
	
    Carta* c;
    for(int i=0; i<45; i++){
        c = d.estrai();
        cout<<"\nCarte rimanenti : "<<d.carte_rimanenti()<<endl;
	    if(c){
	    	cout<<"\nCarta numero "<<(i+1)<<": ";
			c->rivela();
		}else
		    cout<<"\nCarte esaurite "<<endl;
	}
	
	d.mescola();
	
	/*for(int i=0; i<5; i++){
        c = d.estrai();
        cout<<"\nCarte rimanenti : "<<d.carte_rimanenti()<<endl;
	    if(c){
	    	cout<<"\nCarta numero "<<(i+1)<<": ";
			c->rivela();
		}else
		    cout<<"\nCarte esaurite "<<endl;
	}*/
}