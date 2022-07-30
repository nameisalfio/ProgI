#include<iostream>
using namespace std;
class Animale {
    protected:
        string nome;
    public:
        Animale(string n) : nome(n) {}
        string getNome() {return nome;}
};

class Parlante {
    public:
        virtual void parla() = 0;
};

class Quadrupede {
    public:
        virtual void corri() {cout << "run run run!"<<endl;}
    
};

class Gatto : public Animale, public Parlante, public Quadrupede {
    public:
        Gatto(string n="wha") : Animale(n) {}
        void parla() {
            cout << "miao!"<< endl;
        }
};

int main(){

	Gatto g("figaro");
	cout << g.getNome()<<endl;
	g.parla();
	g.corri();
}