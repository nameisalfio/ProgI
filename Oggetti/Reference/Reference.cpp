#include <iostream>
using namespace std;

class Classe {
    int x;
    public:
        Classe() : x(0) {}
        Classe(int _x): x(_x) {}
        void setX(int _x) {x=_x;}
        int getX() const {return x;}  //Inserire const SEMPRE nei metodi getter
};

void print(const Classe &o){  //Con const mi assicuro che la funzione non modificherà mai l'oggetto "o"
	cout<<o.getX()<<endl;
}

voit print_ptr(const Classe *o){
	cout<<o->getX()<<endl;  //Posso modificare lo stato di "o"
	o->setX();
}
//Quando ho un riferimento di sola lettura è preferibile usare un reference piuttosto che un puntatore

int main(){
	
	Classe o;
	Classe &ref_o = o;
	cout<<o.getX()<<endl;
	cout<<ref_o.getX()<<endl;
	ref_o.setX(12);
    cout << ref_o.getX()<<endl;
    print(ref_o);
    print(o);
}


