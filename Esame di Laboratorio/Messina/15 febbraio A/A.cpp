#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

class A {
	private:
		double* w;
		short len;
	public:
		A(short m):len(m){
			w = new double[len];
			for(int i=0; i<len; i++)
				w[i] = (double)rand()/RAND_MAX;
		}
		virtual double foo(short a) const = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& os){
			os<<") "<<typeid(*this).name()<<", w=[";
			for(int i=0; i<len; i++)
				os<<w[i]<<" ";
			os<<"], ";
			return os;
		}
		double& operator[] (short i){
			return w[i%len];
		}
	protected:
		double get(short i)const{
			return w[i%len];
		}
};

class B:public A{
	private:
		int p;
	public:
		B(short m, int x):A(m){
			p = x;
		}
		virtual double foo(short a) const{
			return sum(a)/p;
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", foo(3)="<<foo(3);
			return os;
		}
	protected:
		double sum(short s)const{
			double sum=0.0;
			for(int i=s%getlen(); i<getlen(); i++)
				sum += get(i);
			return sum;
		}
};

template <typename T>
class C:public A{
	private:
		T x;
	public:
		C(short n):A(n){
			if(typeid(x) == typeid(short))
				x = n;
			else
				x = log(1+ pow(sin(n), 2));
		}
		virtual double foo(short r) const{
			return g(r);
		}
		T g(T k)const{
			return 2*x*(k+1);
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", foo(3)="<<foo(3);
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
	return os;
}

int main(){
	
	const int DIM = 50;
	A* vett[DIM];
	srand (111222333);

	for (int i=0; i<DIM; i++){
		short n=1+rand()%10;
		switch (rand()%3) {
			case 0 :
				vett[i]= new B(n, rand()%10 + 1);
				break ;
			case 1 :
				vett[i]= new C<double>(n);
				break;
			case 2 :
				vett[i]= new C<short>(n);
		}
	}
	
	cout<<"\nPunto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<*vett[i]<<endl;
		
	cout<<"\nPunto 2: "<<endl;
	double max = vett[0]->foo(3);
	double sum = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++){
		if(vett[i]->foo(3) > max)
			max = vett[i]->foo(3);
		if(typeid(*vett[i]) == typeid(C<double>)){
			sum += static_cast<C<double>*>(vett[i])->g(5);
			count++;
		}
	}
	cout<<"Max: "<<max<<endl<<"Avg: "<<sum/count<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	(*vett[0])[5] = 3;
	cout<<"(*vett[0])[5]: "<<(*vett[0])[5]<<endl;
	(*vett[0])[5] = 7;
	cout<<"(*vett[0])[5]: "<<(*vett[0])[5]<<endl;
	
	
}