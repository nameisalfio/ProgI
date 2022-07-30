#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class A{
	
	int* ptr;
	short len;
	
	public:
		A(short m, short k):len(m){
			ptr = new int[len];
			for(int i=0; i<len; i++)
				ptr[i] = rand() % (k-1+1)+1;
		}
		virtual double f()const = 0;
		int get(short i)const{
			return ptr[i%len];
		}
		short getlen()const{
			return len;
		}
	virtual ostream& print(ostream& os){
		os<<typeid(*this).name()<<", ptr=[";
		for(int i=0; i<len; i++)
			os<<ptr[i];
		os<<"], ";
		return os;
	}
	int& operator[] (short i){
		return ptr[i%len];
	}
};

class B : public A{
	
	double p;
	
	public:
		B(short m, short k, double y):A(m, k){
			p = y;
		}
		virtual double f()const override{
			double sum = 0.0;
			for(int i=0; i<getlen(); i++){
				if(get(i) % 2 == 0)
					sum += get(i);
			}
			return sum/p;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", f()="<<f();
			return os;
		}
};

class C : public A{
	
	char x;
	
	public:
		C(short n, short k, char c):A(n, k){
			x = c;
		}
		virtual double f()const override{
			double sum = 0.0;
			int count = 0;
			for(int i=0; i<getlen(); i++){
				if(get(i) % 2 != 0){
					sum += get(i);
					count++;	
				}
			}
			if(count != 0)
				return sum/count;
			else
				return 0;
		}
		string g(char c)const{
			string s = "";
			s += x;
			s += c;
			return s;
		}
	virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", f()="<<f();
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){  //overloading
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	srand(111222333);
    A *vett[DIM];

    for(int i=0; i<DIM; i++){
		short n=1+rand()%10;
		short m = 1+rand()%8;
		if(rand()%2==0)
	  		vett[i]= new B(n, m, rand()/(double) RAND_MAX+0.05);
		else
	  		vett[i]= new C(n, m, (char) (rand()%('z' - 'a' + 1) + 'a'));
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<") "<<*vett[i]<<endl;
		
	cout<<"\nPunto 2: "<<endl;
	double sum = 0.0;
	string s = "";
	for(int i=0; i<DIM; i++){
		sum += vett[i]->f();
		if(typeid(*vett[i]) == typeid(C))
			s += static_cast<C*>(vett[i])->g('h');
	}
	cout<<"Avg: "<<sum/DIM<<"\t"<<s<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	(*vett[5])[3] = 7;
	cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
	(*vett[5])[3] = 3;
	cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
}