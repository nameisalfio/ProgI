#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
using namespace std;

class A{
	
	short* arr;
	short len;
	
	public:
		A(short m):len(m){
			arr = new short[len];
			for(int i=0; i<len; i++){
				arr[i] = rand()%10 + 1;
			}
		}
		virtual double f (short a) = 0;
		short getLen ()const{
			return len;
		}
		ostream& print(ostream& os){
			os<<typeid(*this).name()<<", w=[";
			for(int i=0; i<len; i++)
				os<<arr[i]<<" ";
			os<<"], ";
			return os;
		}
		
	protected:
		short get(int i)const{
			return arr[i%len];
		}
};

template <typename T>
class B : public A{
	
	T x;
	
	public:
		B(short m, char c):A(m){
			if(typeid(x) == typeid(char))
				x=c;
			else 
				x="c^[m]";
		}
		double f(short a)override{
			int sum = 0;
			int c = 0;
			for(int i=get(a); i<getLen(); i++){
				sum +=  get(i);
				c++;
			}
			return (double)sum/c;
		}
		double foo(short s){
			return log(s) + sin(f(s));
		}
		ostream& print(ostream& os)override{
			A::print(os);
			os<<"p = "<<p<<", foo(3) = "<<foo(3)<<endl;
			return os;
		}
};

class C : public A{
	
	int y;
	
	public:
		C(short n, int k):A(n){
			y = k;
		}
		double f(short a)override{
			int i = rand();
			int r = get(i);
			return (double)(a+y)/r;
		}
		short g(short w){
			return sin(w+y);
		}
		ostream& print(ostream& os)override{
			A::print(os);
			os<<"x = "<<x<<", foo(3) = "<<foo(3)<<endl;
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	srand(111222333);
	A * vett[DIM];
	for(int i=0; i<DIM; i++){
		short n = 1+rand()%10;
		switch (rand ()%3){
			case 0 :
				vett[i]= new C(n , rand()%10 + 1);
				break ;
			case 1 :
				vett[i]= new B<string>(n, rand()%('z'-'a'+1)+'a');
				break ;
			case 2 :
				vett[i]= new B<char>(n, rand ()%('z'-'a'+1)+'a');
		}
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<*vet[i]<<endl;
	}
	

}