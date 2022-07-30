#include<iostream>
using namespace std;

class A{
	
	int x;
	
	public:
		A(int _x){
			x = _x;
		}
		
		void f() {
			cout<<"A.f(), x= "<<x<<endl;
		}
		int getX() const {
			return x;
		}
		virtual ~A() {
			//Alt + 126
		}
};

class B : public A{
	
	float y;
	
	public:
		B(int x, float _y) : A(x){
			y = _y;
		}
		void f(){
			cout<<"override di A.f(), x= "<<getX()<<endl;
		}
		void g(){
			cout<<"B.g(), y= "<<y<<endl;
		}
};

int main(){
	
	/*Se invochiamo un metodo contenuto anche in A mediante il puntatore a B di tipo A*, 
	verrà richiamata la versione di A a meno che il metodo non sia dichiarato virtual.*/
	
	A* p = new B(10, 4.4);
	p->f();

	//Per richiamare il metodo f di B, possiamo effettuare un cast dinamico: 
	
	B* ptr = dynamic_cast<B*>(p);  //Conversione di p a tipo B*
	if(ptr)  //Se il cast è possibile
		ptr->f();
		
	//Il dynamic_cast è un cast sicuro che restituisce un nullptr se il cast non è possibile.
	
	/*Una soluzione alternativa al dinamyc_cast consiste nel combinare l’operatore typeid che 
	controlla i tipi a runtime con un cast statico: */
	
	if(typeid(*p) == typeid(B))
		static_cast<B*>(p)->f();
//	if(typeid(*p) == typeid(B))
//		((B*)p)->f();
}