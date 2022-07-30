#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
using namespace std;

//<Astract>
class A{
	
	short len;
	
	protected:
		double *w;
	
	public:
		A(short m) : len(m) {
			srand (time(NULL));
			w = new double[len];
			for(int i=0; i<len; i++){
				w[i] = (double)rand()/RAND_MAX;
			}
		}
		virtual double foo(short a) {  //Funzione virtuale pura
			return 0;
		}  
		short get_len()const{
			return len;
		}
		
	protected:
		double get(short i)const{
			return w[i%len];
		}
	
	public:
		virtual ostream& print(ostream & s){
			s<<"w = [ ";
			for(int i=0; i<len; i++)
				s<<w[i]<<" ";
			s<<" ] ";
			return s;
		}
		
		double operator[] (int a){
			return w[a%len];
		}
};

class B : public A{
	
	int p;
	
	public:
		B(short m, int x) : A(m) {
			p = x;
		}
		double foo(short a) override {
			return sum(a)/p;
		}
		
	protected:
		double sum (short s){
			double somma;
			for(int i=get(s); i<get_len(); i++){
				somma += w[i];
			}
			return somma;
		}
	
	public:
		ostream& print (ostream& s){  //Overriding
			A::print(s);
			s<<"p = "<<p;
			return s;
	    }
};

template <typename T>
class C : public A {
	
	T x;
	
	public:
		C(short n) : A(n){
			if(typeid(x) == typeid(short)){
				x = n;
			}else {
				x = log (1+pow(sin(n), 2));
			}
		}
		double foo(short r){
			return g(r);
		}
		T g (T k){
			return (2*x*(k+1));
		}
	
	public: 
		ostream& print (ostream& s){  //Overriding
			A::print(s);
			s<<"x = "<<x;
			return s;
		}
};

ostream& operator<< (ostream& s, A& a){
	return a.print(s);
}

int main(){
	
	const int DIM = 50;
	srand (111222333);
	A* vett[DIM];
	for (int i=0; i<DIM; i++) {
		short n = 1+rand() % 10;
		switch (rand () % 3) {
			case 0 :
				vett [i]= new B(n, rand()%10 + 1);
				break;
			case 1 : 
				vett [i]= new C<double>(n);
				break;
			case 2 :
				vett [i]= new C<short>(n);
		}
	}
	
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<typeid(*vett[i]).name()<<" "<<*vett[i]<<",  foo(3) = "<<(*vett[i]).foo(3)<<endl;
		//30)1CIsE, w=[0.766171 0.725601 0.900516 0.814684 0.889074 0.799782 0.387099 0.141197 0.358242 ], x=9, foo(3)=72
	}
	
	double max = vett[0]->foo(3);
	double sum = 0.0;
	for(int i=0; i<DIM; i++){
		if(vett[i]->foo(3) > max)
			max = vett[i]->foo(3);
		if(typeid(*vett[i]) == typeid(C<double>))
			sum += (static_cast<C<double>*>(vett[i]))->g(5);
	}
	cout<<"Il massimo e' : "<<max<<endl;
	cout<<"La somma e' : " <<sum<<endl;
	cout<<"(*vett[5])[3] : "<<(*vett[5])[3]<<endl;
	
}
