#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
using namespace std;

class A {
	
	double* arr;
	short len;
	
	public:
		A(short m):len(m){
			arr = new double [len];
			for(int i=0; i<len; i++)
				arr[i] = (double)rand()/RAND_MAX;
		}
		virtual double f (short a)=0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& os){
			os<<typeid(*this).name()<<", arr=[";
			for(int i=0; i<len; i++)
				os<<arr[i]<<" ";
			os<<"], ";
			return os;
		}
		double operator()(int i1, int i2){
			double sum = 0.0;
			for(int i=0; i<getlen(); i++)
				if(i>=i1 && i<=i2)
					sum += arr[i];
			return (double)sum;
		}
		
	protected:
		double get(short i)const{
			return arr[i%len];
		}
};

class B:public A{
	
	double p;
	
	public:
		B(short m):A(m){
			double sum = 0.0;
			for(int i=0; i<getlen(); i++)
				sum += get(i);
			p = sum/getlen();
		}
		virtual double f (short a)override{
			return log(foo(a, 2*a))/p;
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", f(3)="<<f(3);
			return os;
		}
		
	protected:
		double foo(short s, int k){
			double sum = 0.0;
			for(int i=s%getlen(); i<getlen(); i++)
				sum += get(i);
			return sum*k;
		}
};

template<typename T>
class C : public A{
	
	T x;
	
	public:
		C(short n):A(n){
			if(typeid(x) == typeid(short))
				x = n;
			else
				x = log(1+pow(sin(n),2));
		}
		virtual double f (short r)override{
			return g(r);
		}
		T g (T k){
			return 2*x*(k+1);
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", f(3)="<<f(3);
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
    srand(111222333);
    A*vett[DIM];
	for(int i=0; i<DIM; i++) {
		short n=1+rand()%10;
		switch(rand()%3) {
	  		case 0: 
	    		vett[i]= new B(n);
	    		break;
	  		case 1:
	   			vett[i]= new C<double>(n);
	    		break;
	  		case 2: 
	    		vett[i]= new C<short>(n);
		}
    }
    
    cout<<"\nPunto 1: "<<endl;
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
    	
    cout<<"\nPunto 2: "<<endl;
    double max = vett[0]->f(3);
    for(int i=0; i<DIM; i++){
    	if(vett[i]->f(3) > max)
    		max = vett[i]->f(3);
	}
	double sum = 0.0; int count = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(C<double>)){
			sum += static_cast<C<double>*>(vett[i])->f(3);
			count++;
		}
	}
	cout<<"Max: "<<max<<endl;
	cout<<"Avg: "<<sum/count<<endl;
    
    cout<<"\nPunto 3: "<<endl;
    cout<<"vett[10]= "<<*vett[10]<<endl;
    cout<<"*vett[10](0, 0)= "<<(*vett[10])(0, 0)<<endl;

}