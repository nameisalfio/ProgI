#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class A {
	
	double* ptr;
	short len;
	
	public:
		A(short m):len(m){
			ptr = new double[len];
			for(int i=0; i<len; i++)
				ptr[i] = (double)rand()/RAND_MAX;
		}
		virtual double f(short i)=0;
		double get (short i)const{
			return ptr[i%len];
		}
		short getlen()const{
			return len;
		}
		virtual ostream& print(ostream& os){
			os<<typeid(*this).name()<<", ptr= [";
			for(int i=0; i<len; i++)
				os<<ptr[i]<<" ";
			os<<"], ";
			return os;
		}
		double operator [](int i){
			return ptr[i%len];
		}
};

class B : public A {
	
	int p;
	
	public:
		B(short m, int y):A(m){
			p=y;
		}
		virtual double f(short i)override{
			double sum=0.0;
			for(int j=0; j<=i; j++)
				sum += get(j);
			return (double)sum/p;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<" p= "<<p<<", f(3)= "<<f(3);
			return os;
		}
};

class C : public A {
	
	char x;
		
	public:
		C(short n, char c):A(n){
			x = c;
		}
		virtual double  f(short i)override{
			double sum=0.0;
			for(int j=0; j<getlen(); j++)
				sum += get(j);
			
			return (double)get(i)/sum;
		}
		string g(char c){
			string s="";
			s+=x;
			s+=c;
			return s;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<" x= "<<x<<", f(3)= "<<f(3);
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	srand(111222333);
	A* vett[DIM];
	for(int i=0; i<DIM; i++){
		short n=1 + rand()%10;
		if(rand() %2 ==0)
			vett[i]= new B(n, 1 + rand()%10);	
		else
			vett[i]= new C(n, (char)(rand()%('z'-'a'+ 1)+'a'));
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<") "<<*vett[i]<<endl;
		
	cout<<"\nPunto 2: "<<endl;
	double sum=0.0;
	string s="";
	for(int i=0; i<DIM; i++){
		sum += vett[i]->f(3);
		if(typeid(*vett[i]) == typeid(C))
			s+=static_cast<C*>(vett[i])->g('h');
	}
	cout<<"La media e' : "<<sum/DIM<<endl;
	cout<<"Concatenazione : "<<s<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	cout<<(*vett[5])[3]<<endl;
	
}