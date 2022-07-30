#include <iostream>
#include <string>
using namespace std;
class Veicolo{
	private:
		string modello;
		int n_ruote;
		string tipologia;
		
	public:
		Veicolo(string modello, int n_ruote, string tipologia){
			this->modello = modello;
			this->n_ruote = n_ruote;
			this->tipologia = tipologia;
		}
		
		void nome_veicolo(){
			cout<<tipologia<<" "<<modello<<" a "<<n_ruote<<" ruote"<<endl;
		}
		
		string get_tipologia (){
			return tipologia;
		}
};