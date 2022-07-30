#include<iostream>
#include<string>
using namespace std;

/*In certi casi, può avere senso non implementare alcuni metodi nella classe di base,
 in quanto il comportamente è definito bene solo dalle classi che ereditano. 
 In questi casi, è possibile definire il metodo come “virtuale puro”*/
class Animale {
    public:
    	/*Possiamo chiedere a C++ di richiamare il metodo della classe 
		nota a runtime, indicando il metodo come virtual*/ 
        virtual void parla() = 0;
};
/*In questo caso, la classe Animal è detta una classe astratta in quanto 
presenta almeno un metodo virtuale puro. Le classi astratte non possono 
essere instanziate, pertanto la seguente riga di codice darebbe un errore:

        Animale a;            oppure          a = new Animale            */

/*Una classe base astratta che contiene solo attributi costanti 
e funzioni virtuali pure si dice interfaccia. 
La classe Animale è una interfaccia.*/

/*Un esempio di classe astratta ma non interfaccia è il seguente:
class Animale {
    protected:
        string name;
        
    public:
        virtual void parla() = 0;  //funzione virtuale pura
        string getName() {return name;}
};*/
//Questa classe non può essere instanziata, ma non è una interfaccia

class Cane: public Animale {
    public:
        void parla() override {cout << "bau"<<endl;}
};

class Gatto: public Animale {
    public:
        void parla() override {cout << "miao"<<endl;}
};

int main(){
	
	Animale *a;
	string animale = "cane";
	
	if(animale=="gatto")
	    a = new Gatto();
	else if(animale=="cane")
	    a = new Cane();
	else
	    cerr<<"Scegli tra cane o gatto"<<endl;
	
	a->parla();
}
