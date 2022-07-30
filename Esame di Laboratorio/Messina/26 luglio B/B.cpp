#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>
using namespace std;

class A{
	
	int* vec;
	short len;
	
	public:
		A(short m, int a, int b):len(m){
			vec = new int[m];
			for (int i=0; i<len; i++)
				vec[i] = rand()%(b-a+1)+a;
		}
		virtual double foo(short a) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print(ostream& os){
			os<<typeid(*this).name()<<", vec=[ ";
			for(int i=0; i<len; i++)
				os<<vec[i]<<" ";
			os<<"], ";
			return os;
		}
		int operator()(int i1, int i2){
			int sum = 0;
			for(int i=0; i<len; i++){
				if(i>=i1 && i<=i2)
					sum += vec[i];
			}
			return sum;
		}
	
	protected:
		int get(short i)const{
			return vec[i%len];
		}
};

class B:public A{
	
	int p;
	
	public:
		B(short m, int x, int y):A(m, x, y){
			int r = rand()%getlen();
			p = get(r);
		}
		virtual double foo(short a)override{
			return (double)prod(a)/p;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", foo(3)="<<foo(3);
			return os;
		}
	protected:
		int prod(short s){
			int prod ;
			for(int i=(s%getlen()); i<getlen(); i++){
				prod *= get(i);
			}
			return prod;
		}
		
};

template<typename T>
class C:public A{
	
	T x;
	
	public:
		C(short n, int a, int b):A(n, a, b){
			if(typeid(x) == typeid(short))
				x = n;
			else
				x = log(1 + pow(sin(n), 2));
		}
		virtual double foo(short r)override{
			return g(r);
		}
		T g( T k){
			return 2 * x * (k+1);
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", foo(3)="<<foo(3);
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){

	const int DIM = 50;
	srand(111222333);
    A *vett[DIM];
    for(int i=0; i<DIM; i++) {
		short n=1+rand()%10;
		switch(rand()%3) {
	  		case 0: 
	    		vett[i]= new B(n, rand()%5 + 1, rand()%10 + 5);
	    		break;
	  		case 1:
	    		vett[i]= new C<double>(n, rand()%5 + 1, rand()%10 + 5);
	    		break;
	  		case 2: 
	    		vett[i]= new C<short>(n, rand()%5 + 1, rand()%10 + 5);
		}
    }
    
    cout<<"\nPunto 1: "<<endl;
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
    
    cout<<"\nPunto 2: "<<endl;
    int max = vett[0]->foo(3);
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
    cout<<"Max: "<<max<<"\tAvg: "<<sum/count<<endl;
    
    cout<<"\nPunto 3: "<<endl;
    cout<<"vett[10]: S"<<*vett[10]<<endl;
    cout<<"*vett[10](2,4): "<<(*vett[10])(4,8)<<endl;

}