#include<iostream>
#include<string>
using namespace std;

class A{
  int x; 
  
  public:
    A(int _x){
      x = _x; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    int getX() { return x;} 
};

class B: public A{
  float y; 

  public:
    B(int x, float _y) : A(x) {y=_y;}
    void f() {cout << "override di A.f(), x="<< getX() <<endl;}
    void g() {cout << "B.g(), y=" << y << endl;}
};

int main(){
	B b(2, 3.2);
	b.f();
	b.g();
	cout<<"\n------------\n"<<endl;
	A *ptra = new A(10);
	B *ptrb = new B(20, 4.4);
	ptrb->g();
	ptra->f();
	ptra = ptrb; //Posso far puntare un oggetto di classe madre ad un oggetto di classe figlia
	/*Anche se ptra punta ad un oggetto di tipo B verrà richiamata l'implementazione
    di f contenuta in A, ma con lo stato di B*/
	ptra->f();  //Infatti stampa A.f() ma con la x di B
	A a1(3);
	B b1(5, 3.8);
	A &refa = a1;
	B &refb = b1;
	refb.g();
	refa.f();  
	//Queste caratteristiche di Reference e puntatori permettono il Polimorfismo
	//------->
}