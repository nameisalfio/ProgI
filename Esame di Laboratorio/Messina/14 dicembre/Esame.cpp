#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>

using namespace std;

class A{

	protected:
		double* ptr;
		short len;
		
	public:
		A(short n):len(n){
			ptr = new double[len];
			for(int i=0; i<len; i++)
				ptr[i] = (double)rand()/RAND_MAX;
		}
		double virtual foo (short a)const = 0;
		virtual ostream& print(ostream& os){
			os<<"ptr=[";
			for(int i=0; i<len; i++)
				os<<ptr[i]<<" ";
			os<<"], ";
			return os;
		}
		double& operator[] (short i){
			return ptr[i%len];
		}
	
};

class B : public A{
	
	double alpha;
	
	public:
		B(short m, double d):A(m){
			alpha = d;
		}
		double extract(short s)const{
			double sum = 0.0;
			sum = ptr[s%len] + alpha;
			return sum/2.0; 
		}
		virtual double foo(short b) const override{
			return log(1+ extract(b));
		}
		virtual ostream& print(ostream& os)override{
			os<<"B, ";
			A::print(os);
			os<<"alpha="<<alpha<<", foo(5)="<<foo(5);
			return os;
		}
};

template <typename T>
class C : public A{
	
	T x;
	
	public:
		C(short n):A(n){
			if(typeid(x) == typeid(short))
				x = g(n);
			else
				x = log(1+n);
		}
		virtual double foo(short r) const override{
			return g(r*x);
		}
		T g(T k)const{
			return 3*k;
		}
		virtual ostream& print(ostream& os)override{
			os<<"C<"<<typeid(x).name()<<">, ";
			A::print(os);
			os<<"x="<<x<<", foo(5)="<<foo(5)<<", g(5)="<<g(5);
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	A* vett[DIM];
	srand(328832748);
	for(int i=0; i<DIM; i++){
		short n=1+rand ( )%5;
		switch ( rand ()%3) {
			case 0 : vett[i]= new B(n, n / 100.0); 
				break;
			case 1 : vett[i]= new C<double>(n); 
				break ;
			case 2 : vett[i]= new C<int>(n);
		}
	}
	
	cout<<"\nPunto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<")"<<*vett[i]<<endl; 
	
	cout<<"\nPunto 2: "<<endl;
	double max = vett[0]->foo(5);
	double sum = 0.0;
	for(int i=0; i<DIM; i++){
		if(vett[i]->foo(5) > max)
			max = vett[i]->foo(5);
		if(typeid(*vett[i]) == typeid(C<double>))
			sum += static_cast<C<double>*>(vett[i])->g(5);
	}
	cout<<"Max: "<<max<<endl;
	cout<<"Sum: "<<sum<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	(*vett[5])[3] = 7;
	cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
	(*vett[5])[3] = 5;
	cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
}