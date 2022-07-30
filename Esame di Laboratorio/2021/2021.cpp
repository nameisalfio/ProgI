#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
#include<cmath>
using namespace std;

class A	
{
	double *vec;
	short len;
	
	public:
		A(short w, double a, double b): len(w){
			srand(time(0));
			vec = new double[len];
			for(int i = 0; i<len; i++){
				vec[i] = (rand()/(RAND_MAX*1.0)) *(b-a);
			}
			
		}
		
		virtual double foo(short a) = 0;
		
		short get_len(){
			return len;
		}
		
		protected:
			double get(short i){
				return vec[i%len];
			}
			
			
			public:
			virtual ostream &print(ostream &os){
				os<< typeid(*this).name() << ", vec=[";
				for(int i = 0; i<len; i++){
					os<<vec[i]<< " ";
				}
				os<<"], ";
				return os;
			}
			double& operator[](int i){
				return vec[i%len];
			}
			
		
			
};
ostream& operator<<(ostream & os, A& a){
	return a.print(os);
}

class B : public A
{
	int p;
	
	public:
		B(short m, short x, short y): A(m,x,y){
			p = rand()%(100*y-10*x+1)+10*x;
		
		}
		
		double foo(short a){
			return log(prod(a, a/2.0));
		}
		
		protected:
			double prod(short s, double v){
				double somma = 0;
				for(int i = s; i<A::get_len(); i++){
					somma+= get(i);
				}
				return v*somma;
			}
			virtual ostream &print(ostream &os){
				A::print(os);
				os<< "p="<<p<<", foo(3)"<<foo(3);
				return os;
			}
	
};

template<typename T>

class C : public A
{
	T y;
	public:
	C(short n, double x, double y): A(n,x,y){
		if(typeid(this->y) == typeid(short)){
			this->y = n;
			
		}
		else
		{
			 this->y = 1+pow(cos(n),2);
		}
	}
	double g(double k){
		return 2*y*(k+1);
	}
	double foo(short r){
		return g(r);
	}
	virtual ostream &print(ostream &os){
		A::print(os);
		os<< "y="<<y<<", foo(3)"<<foo(3);
		
		return os;
	}
	

	
};
int main(){
	const int DIM = 50;
	A* vett[DIM];
	srand(111222333);
for (int i = 0; i < DIM; i++) {
    short n = 5 + rand() % 5;
    switch (rand() % 3) {
    case 0:
        vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
        break;
    case 1:
        vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
        break;
    case 2:
        vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
    }
}
	cout<< " PUNTO 1"<<endl;
	for(int i = 0; i<DIM; i++){
		cout<<i<<")"<<*vett[i]<<endl;
	}
	
	cout<<" PUNTO 2"<<endl;
	double max = vett[0]->foo(3);
	double somma_g = 0;
	for(int i = 0; i<DIM; i++){
		if(vett[i]->foo(3 )>max) max = vett[i]->foo(3);
		if(typeid(*vett[i]) == typeid(C<double>)){
			somma_g += ((C<double>*)vett[i])->g(0.5);
		}
	}
	cout<<"max : "<<max<<endl;
	cout<<"somma: "<<somma_g<<endl;
	
	cout<<"PUNTO 3"<<endl;
	cout << "(*vett[5])[3]=" << (*vett[5])[3] << endl;
}