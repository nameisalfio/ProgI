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
			string v ="";
			string c ="";
			for(int i=0; i<source.length(); i++){
				if(source[i] == 'a' || source[i] == 'e' ||
		   			source[i] == 'i' || source[i] == 'o' ||
		   			source[i] == 'u')
			 			v += source[i];
				else
					c += source[i];
			}
			for(int i=0; i<v.length(); i++)
				str[i] = v[i];
				
			for(int i=v.length(), j=0; j<c.length(); i++, j++)
				str[i] = c[j];
			
		}
		virtual string func(short k) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& s){
			s<<typeid(*this).name()<<", str=";
			for(int i=0; i<len; i++)
				s<<str[i];
			s<<", ";
			return s;
		}
		string operator() (int i1, int i2){
			string s = "";
			for(int i=0; i<getlen(); i++){
				if(i>i1 && i<i2)
					s += str[i];
			}
			return s;
		}
	protected:
		char get (short i)const{
			return str[i%len];
		}
};

class B : public A{
	
	short q;
	public:
		B(short m, string source):A(m, source){
			q = 1 + (rand() % getlen());
		}
		virtual string func(short k)override{
			string s = "";
			short c = 0;
			for(int i=getlen()-1; i>=0; i++){
				s += get(i);
				c++;
				if(c == k)
					break;
			}
			return s;
		}
		virtual ostream& print (ostream& s)override{
			A::print(s);
			s<<"q="<<q<<", func(3)="<<func(3);
			return s;
		}
		
};

class C : public A{
	
	char y;
	
	public:
		
		C(short n, string source, char y):A(n, source){
			this->y = y;
		}
		virtual string func(short k)override{
			string s ="";
			for(int i=k; i<getlen(); i++)  //a partire da k
				s += get(i);
				
			string w = s;
			for(int i=w.length()-1, j=0; i>=0, j<w.length(); i--, j++)  //inverto l'ordine
				w[j] = s[i];
			return w;
		}
		string g(char c){
			string q ="";
			q += y;
			for(int i=0; i<getlen(); i++)
				q += get(i);
			q += c;
			return q;
		}
		virtual ostream& print (ostream& s)override{
				A::print(s);
				s<<"y="<<y<<", func(3)="<<func(3);
				return s;
			}
	
};

ostream& operator<< (ostream& s, A& a){
	return a.print(s);
}

int main(){
	
	const int DIM = 50;
	A* vett[DIM];
	srand(111222333);    
    string S;
	short fa = 3;
	for(int i=0; i<DIM; i++){
		short n=10+rand()%10;
		S=""; 
		for(int k = 0; k< 20; k++)
	  		S+=rand()%('z'-'a'+1)+'a'; 
			if(rand()%2==0)
				vett[i]= new B(n, S);
			else
	  			vett[i]= new C(n, S, (char) (rand()%('z'-'a'+1)+'a'));
    }
    
    cout<<"Punto 1: "<<endl;
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
    	
    cout<<"\nPunto 2: "<<endl;
    string s ="";
    for(int i=0; i<DIM; i++){
    	if(typeid(*vett[i]) == typeid(C))
    		s = static_cast<C*>(vett[i])->g('X');
	}
	cout<<"Stringa: "<<s<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	cout<<"*vett[5]: "<<*vett[5]<<endl;
    cout<<"vett[5](1, 3): "<<(*vett[5])(1, 3)<<endl;
    
}