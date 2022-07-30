#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>
using namespace std;

class A{
	
	char* str;
	short len;
	
	public:
		
		A(short m, string source):len(m){
			str = new char[len];
			short r;
			for(int i=0; i<len; i++){
				r = rand()%(source.length());
				str[i] = source[r]; 
			}
		}
		virtual char func(short i) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& os){
			os<<typeid(*this).name()<<", str=";
			for(int i=0; i<len; i++)
				os<<str[i];
			os<<", ";
			return os;
		}
		string operator()(int i1, int i2){
			string s = "";
			for(int i=0; i<len; i++){
				if(i>=i1 && i<=i2)
					s += str[i];
			}
			return 	s;
		}
	protected:
		char get(short i)const{
			return str[i%len];
		}
		
};

class B : public A{
	
	short p;
	
	public:
		B(short m, string source):A(m, source){
			int count;
			for(int i=0; i<getlen(); i++){
				if(get(i) == 'a' || get(i) == 'e' ||
				   get(i) == 'i' || get(i) == 'o' ||
				   get(i) == 'u')
				count++;	
			}
			p = 1+count;
		}
		virtual char func(short i)override{
			for(int x=i; x<getlen(); x++){
				if(get(x) != 'a' || get(x) != 'e' ||
				   get(x) != 'i' || get(x) != 'o' ||
				   get(x) != 'u')
				   return get(i);
			}
			return 'X';
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", func(3)="<<func(3);
			return os;
		}
};

class C : public A{
	
	char x;
	
	public:
		C(short n, string source, char y):A(n, source){
			x = y;
		}
		virtual char func(short i)override{
			for(int x=i; x<getlen(); x++){
				if(get(x) > x)
					return get(x);
			}
			return x;
		}
		string g (char c){
			string s = "";
			s += x;
			for(int i=0; i<getlen(); i++)
				s += get(i);
			s += c;
			return s;
		}
		virtual ostream& print (ostream& os)override{
			A::print(os);
			os<<"x="<<x<<", func(3)="<<func(3);
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
    
    string S="supercalifragilistichespiralidoso";

    for(int i=0; i<DIM; i++){
		short n=3+rand()%10;
		if(rand()%2==0)
	  		vett[i]= new B(n, S);
		else
	  		vett[i]= new C(n, S, (char) (rand()%('z'-'a'+1)+'a'));
    }
    
    cout<<"\nPunto 1: "<<endl;
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
    	
    cout<<"\nPunto 2: "<<endl;
    string s = "";
    for(int i=0; i<DIM; i++){
    	if(typeid(*vett[i]) == typeid(C))
    		s += static_cast<C*>(vett[i])->g('h');
	}
    cout<<"Concat= "<<s<<endl;
    
    cout<<"\nPunto 3: "<<endl;
	cout<<"*vett[5]: "<<*vett[5]<<endl;
    cout<<"vett[5](1, 3): "<<(*vett[5])(1, 3)<<endl;
}