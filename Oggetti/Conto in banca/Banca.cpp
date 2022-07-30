/*Si costruisca un oggetto ContoInBanca che memorizzi i seguenti dati:

- Numero di conto;

- Giacenza;

- Nome del proprietario;

E permetta di eseguire queste operazioni:

- Ottenere il nome del proprietario;

- Ottenere il numero di conto;

- Ottenere la giacenza;

- Effettuare un prelievo;

- Effettuare un versamento;

- Pagare l’imposta di bollo (pari a 34,20 €);

- Pagare le spese mensili del conto (pari a 12 €);

L’oggetto deve avere due costruttori:

- Un costruttore prende in input il nome del proprietario, il numero del conto e la 
giacenza;

- Un costruttore prende in input il nome del proprietario e il numero del conto, e 
imposta la giacenza a zero.

Costruire una funzione main che definisca e utilizzi diversi conti correnti intestati 
a diverse persone.*/

#include <iostream>
#include <string>
using namespace std;

class conto_bancario {
	private:
		double numero_conto;
		double giacenza;
		string nome;
		const double bollo = 34.20;
		const int mensile = 12;
		
	public:
		conto_bancario (double nc, double g, string n){
			numero_conto = nc;
			giacenza = g;
			nome = n;
		}
		
		conto_bancario (double nc, string n){
			numero_conto = nc;
			giacenza = 0;
			nome = n;
		}
		
		string get_nome (){
			return nome;
		}
		
		double get_numero_conto (){
			return numero_conto;
		}
		
		double get_giacenza (){
			return giacenza;
		}
		
		double prelievo (float q){
			if(giacenza!=0 && giacenza>=q)
			return giacenza-q;
			
			if(giacenza==0)
			cout<<"Sei povero come la merda"<<endl;
		}
		
		double versamento (float v){
			giacenza+=v;
			return v;
		}
		
		void imposta_bollo (){
			if(giacenza!=0 && giacenza>=bollo)
			 giacenza-=bollo;
		}
		
		void imposta_mensile (){
			if(giacenza!=0 && giacenza>=mensile)
			 giacenza-=mensile;
		}
}

int main(){
	conto_bancario f(12345678.0, 1000000.500, "Flavio");
	cout<<"Giacenza: "<<f.get_giacenza()<<endl;
	cout<<"Nome: "<<f.get_nome()<<endl;
	cout<<"Numero conto: "<<f.get_numero_conto()<<endl;
}