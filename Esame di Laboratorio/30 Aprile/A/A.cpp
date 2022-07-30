#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
using namespace std;

class A {
	
	char* str;
	short len;
	
	public:
		A(short m, string source):len(m){;
			str = new char[len];
			short j;
			for(int i=0; i<len; i++){
				j = rand() % source.length();
				str[i] = source[j];
			}
		}
		virtual char func (short i) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print(ostream& os){
			os<<typeid(*this).name()<<", str = ";
			for(int i=0; i<len; i++){
				os<<str[i];
			}
			os<<", ";
			return os;
		}
		string operator() (int i1, int i2){
			string s="";
			for(int i=0; i<len; i++){
				if(i>=i1 && i<=i2)
					s += get(i);
			}	 
			return s;
		}
		
	protected:
		char get(short i)const{
			return str[i%len];
		}
};

class B : public A {
	
	short p;
	
	public:
		B(short m, string source):A(m, source){
			int count = 0;
			for(int i=0; i<getlen(); i++){
				if(get(i) == 'a' || get(i) == 'e' ||
				   get(i) == 'i' || get(i) == 'o' ||
				   get(i) == 'u')
				   count ++;
			}
			p = count + 1;
		}
		virtual char func (short i)override{
			for(int a=i; a<getlen(); a++){
				if(get(a) != 'a' && get(a) != 'e' &&
				   get(a) != 'i' && get(a) != 'o' &&
				   get(a) != 'u' )
				   return get(a);
			}
			return 'X';
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"p= "<<p<<", func(3)= "<<func(3);
			return os;
		}
};
	
class C : public A {
	
	char x;
	
	public:
		C(short n, string source, char y):A(n, source){
			x = y;
		}
		virtual char func(short i)override{
			for(int a=i; a<getlen(); a++){
				if(get(a) > x)
					return get(a);
			}
			return x;
		}
		string g(char c){
			string s="";  // x + str + c
			s += x;
			for(int i=0; i<getlen(); i++)
				s += get(i);
			s+=c;
			return s;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"x= "<<x<<", func(3)= "<<func(3);
			return os;
		}
	
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	srand (111222333);
	A * vett[DIM];
	string S = "supercalifragilistichespiralidoso";
	for (int i=0; i<DIM; i ++){
		short n = 3 + rand()%10;
		if (rand() % 2 == 0) //RTTI (Run Time Type Identification)
			vett[i]= new B(n, S);
		else
			vett[i]= new C(n, S , (char)(rand() % ('z' - 'a' + 1)+'a'));
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<") "<<*vett[i]<<endl;
		
	cout<<"\nPunto 2: "<<endl;
	string s="";
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(C)){
			s += static_cast<C*>(vett[i])->g('h');
			s += " ";
		}
	}
	cout<<"Concatenazione: \n"<<s<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	cout<<"Stringa :"<< *vett[0]<<endl;
	cout<<"Overloading (2, 6) :"<<(*vett[0])(2, 6)<<endl;

}