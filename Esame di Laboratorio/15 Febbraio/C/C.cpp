#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
#include<cmath>
using namespace std;

class A {
	
	char* str;
	short len;
	
	public:
		A(short m) : len(m){
			str = new char[len];
			for(int i=0; i<len; i++){
				str[i] = (char)(rand()%('z'-'a'+1)+'a');
			}
		}
		virtual double elab(short a) = 0;
		short getLen()const{
			return len;
		}
		virtual ostream& print (ostream& s){
			s<<typeid(*this).name() <<" , w =  ";
			for(int i=0; i<len; i++)
				s<<str[i];
			return s;
		}
	protected:
		char get(short i)const{
			return str[i%len];
		}	
		
};

class B : public A{
	
	int p;
	
	public:
		B(short m, int x) : A(m){
			p = x;
		}
		double elab(short a){
			int somma = 0;
			short* vet = new short[getLen()];
			vet = map();
			for(int i=0; i<getLen(); i++)
				somma += vet[i];
			return somma/(double)p/a;
		}
		B operator++ (int){
			B aux = *this;
			p++;
			return aux;
			//this->p++;
		}
	protected:
		short* map(){
			short* arr = new short[getLen()]; 
			for(int i=0; i<getLen(); i++){
				if( get(i) != 'a' && get(i) != 'e' &&
				   	get(i) != 'i' && get(i) != 'o' &&
				   	get(i) != 'u')
					arr[i] = 1;
				else
					arr[i] = 0;
			}
			return arr;
		}
		
};

class C : public A{
	
	char x;
	
	public:
		C(short n, char c) : A(n)  {
			x = c;
		}
		double elab (short r){
			int count=0;
			for(int i=r%getLen(); i<getLen(); i++){
				if(get(i) >= x)
					count++;
			}
			return (double)count/getLen();
		}
		string g(char c){
			string s = "";
			s = x;
			string h = "";
			h = c;
			s += h;
			return s;
		}
		virtual ostream& print(ostream& s){
			A::print(s);
			s<<" ,";
			s<<"x= "<<x<<", elab(3) ="<<elab(3);
			return s;
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
		short n=1+rand()%10;
		if (rand()%2==0)
		vett[i]= new B(n, rand()%10 + 1);
		else
		vett[i]= new C(n ,(char)(rand()%('z'-'a' + 1) + 'a'));
	}
	
	cout<<"Punto 1"<<endl;
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<(*vett[i])<<endl;
	}
	
	cout<<"\nPunto 2"<<endl;
	double somma = 0.0;
	string conc = "";
	
	for(int i=0; i<DIM; i++){
		somma += vett[i]->elab(3);
		if(typeid(*vett[i]) == typeid(C))
			conc += ((C*)vett[i])->g('h');
	}
	cout<<"La media e' : "<<somma/DIM<<endl;
	cout<<conc<<endl;
	
	cout<<"\nPunto 3"<<endl;
	if(typeid(*vett[5]) == typeid(B)){
		(*(B*)(vett[5]))++;
		cout<<"B++ = "<<(*vett[5])<<endl;
	}
	
}