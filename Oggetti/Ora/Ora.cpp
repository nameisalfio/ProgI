/*Creare una classe Ora che abbia membri dati di tipo int per ore, minuti e secondi. 
Un costruttore inizializzerà questi dati a 0, mentre un altro li inizializzerà a valori
passati al costruttore. Una funzione membro dovrà visualizzare l’ora in formato 11:59:59. 
Un’altra funzione membro sommerà l’oggetto di tipo Ora a un altro oggetto di tipo Ora preso
in input come argomento. Una funzione principale main() deve creare due oggetti 
inizializzati con valori passati al costruttore e un terzo inizializzato con zeri. 
Stampare i valori dei tre oggetti, poi sommare il secondo al primo e il secondo al terzo 
e stampare i valori del primo e del terzo.
*/

#include <iostream>
using namespace std;

class ora{
	
	public:
		int ore;
		int minuti;
		int secondi;
		
    
		ora(int ore, int minuti, int secondi){
			this->ore = ore;
			this->minuti = minuti;
			this->secondi = secondi;
		}
		
		ora(){
			ore = 0;
			minuti = 0;
			secondi = 0;
		}
		
		void get_ora (){
			if(ore>0 && ore<=12 && minuti>1 && minuti<=59 && secondi>1 && secondi<=59){
			cout<<"Sono le ore : "<<endl;
			cout<<ore<<":"<<minuti<<":"<<secondi<<endl;
		    }
		}
		
		void somma_ora (){
			ora h(3, 20, 38);
			ora f(4, 20, 34);
			cout<<"Ora sono le:"<<endl;
			cout<<f.ore + h.ore<<":"<<f.minuti + h.minuti<<":"<<f.secondi + f.secondi<<endl;
		}
};

int main (){
	ora f(3, 6, 7);
	f.get_ora();
	f.somma_ora();
	
}