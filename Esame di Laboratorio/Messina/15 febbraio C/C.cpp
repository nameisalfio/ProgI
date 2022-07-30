#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class A{
	char* str;
	short len;
	public:
		A(short m):len(m){
			str = new char[len];
			for(int i=0; i<len; i++)
				str[i] = rand()%('z'-'a'+1)+'a';
		}
		virtual double elab (short a)const = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& os){
			os<<typeid(*this).name()<<", str= ";
			for(int i=0; i<len; i++)
				os<<str[i];
			os<<", ";
			return os;
		}
	protected:
		char get(short i)const{
			return str[i%len];
		}
};

class B : public A{
	int p;
	public:
		B(short m, int x):A(m){
			p = x;
		}
		virtual double elab (short a)const override{
			short *vec = new short;
			int sum = 0;
			vec = map();
			for(int i=0; i<getlen(); i++)
				sum += vec[i];
			return (double)sum/p;
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", elab(3)="<<elab(3);
			return os;
		}
		B operator++ (int){ //dummy parameter
			B aux = *this;
			p++;
			return aux;
		}
	protected:
		short* map()const{
			short* vet = new short;
			for(int i=0; i<getlen(); i++){
				if(get(i) != 'a' && get(i) != 'e' &&
				   get(i) != 'i' && get(i) != 'o' &&
				   get(i) != 'u')
					vet[i] = 1;
				else
					vet[i] = 0;	   
			}
			return vet;
		}
};

class C : public A{
	char x;
	public:
		C(short n, char c):A(n){
			x = c;
		}
		virtual double elab (short r)const override{
			int count = 0;
			for(int i=(r%getlen()); i<getlen(); i++){
				if(get(i) >= x)
					count++;
			}
			return (double)count/getlen();
		}
		string g (char c) const{
			string s="";
			s += x;
			s += c;
			return s;
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", elab(3)="<<elab(3);
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
		if(rand()%2==0)
	  		vett[i]= new B(n, rand()%10 + 1);
		else
	  		vett[i]= new C(n, (char)(rand()%('z' - 'a' + 1) + 'a'));
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<") "<<*vett[i]<<endl;
		
	cout<<"\nPunto 2: "<<endl;
	double sum = 0.0;
	string s = "";
	for(int i=0; i<DIM; i++){
		sum += vett[i]->elab(3);
		if(typeid(*vett[i]) == typeid(C))
		s += static_cast<C*>(vett[i])->g('h');
	}
	cout<<"Avg: "<<sum/DIM<<", "<<s<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	if(typeid(*vett[0])==typeid(B)){
		cout<<"0) :"<<*vett[0]<<endl;
		(*static_cast<B*>(vett[0]))++;
		cout<<"0) :"<<*vett[0]<<endl;	
	}
}