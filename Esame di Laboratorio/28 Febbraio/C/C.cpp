#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class A{
	
	char* base;
	short len;
	
	public:
		A(short m): len(m){
			base = new char[len];
			for(int i=0; i<len; i++){
				base[i] = rand()%('z' - 'a' + 1)+'a';
			}
		}
		virtual string extract(short x) = 0;
		short getlen()const{
			return len;
		}
		
	virtual ostream& print(ostream& os){
		os<<typeid(*this).name()<<" : base = [";
		for(int i=0; i<len; i++)
			os<<base[i];
		os<<"], ";
		return os;
	}
		
	protected:
		char get(short i)const{
			return base[i%len];
		}
};

class B : public A {
	
	string str;
	double k;
	
	public:
		B(short m, double p):A(m){
			for(int i=0; i<getlen(); i++){
				if(get(i) != 'a' &&  get(i) != 'e' &&
				   get(i) != 'i' &&  get(i) != 'o' &&
				   get(i) != 'u')
				str += get(i);
			}
			k=p;
		}
		string extract(short x)override{
			string r="";
			int p = rand();
			for(int i=0; i<x; i++)
				r += get(p);
			return r;
		}
		double foo(short s){
			return sin(k+s)/log(s+1);
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"str= "<<str<<", k= "<<k<<", extract(3)= "<<extract(3);
			return os;
		}
		
};

class C : public A {
	
	int y;
	
	public:
		C(short n, int k):A(n){
			y=k;
		}
		string extract(short x)override{
			string s="";
			short count = 0;
			for(int i=0; i<getlen(); i++){
				if(get(i) != 'a' &&  get(i) != 'e' &&
				   get(i) != 'i' &&  get(i) != 'o' &&
				   get(i) != 'u'){
				   	s += get(i);
				   	count++;
				   	if(count == x)
				   		break;
				   }
			}
			return s;
		}
		short g(short w){
			return sin(w+y);
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"y= "<<y<<", extract(3)= "<<extract(3);
			return os;
		}
		C operator++ (int){
			C aux = *this;
			y++;
			return aux;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	A * vett[DIM];
	for(int i=0; i<DIM; i ++){
		short n=10+rand()%10;
		switch(rand ()%2){
			case 0 :
				vett[i] = new C(n , rand()%20 + 1);
				break ;
			case 1 :
				vett[i] = new B(n, rand()/(double)RAND_MAX);
				break ;
		}
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<(*vett[i])<<endl;
	}
	
	cout<<"\nPunto 2: "<<endl;
	double sum = 0.0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(B))
			sum += static_cast<B*>(vett[i])->foo(5);
		if(typeid(*vett[i]) == typeid(C))
			sum += static_cast<C*>(vett[i])->g(5);
	}
	
	cout<<"La media e' : "<<sum/DIM<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	C c(3, 5);
	cout<<"Prima : "<<c<<endl;
	c++;
	cout<<"Dopo : "<<c<<endl;

}