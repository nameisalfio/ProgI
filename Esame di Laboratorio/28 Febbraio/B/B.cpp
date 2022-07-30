#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

class A {
	
	char* ptr;
	short len;
	
	public: 
		A(short m, char c):len(m){
			ptr = new char[len];
			for(int i=0; i<len; i++){
				ptr[i] = rand()%(c - 'a' +1)+'a';
			}
		}
		virtual string elab(short a, char c) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print (ostream& os){
			os<<" ptr = [";
			for(int i=0; i<len; i++)
				os<<ptr[i]<<" ";
			os<<"], ";
			return os;
		}
		char operator[] (int i){
			return ptr[i%len];
		}

	protected:
		char get(int i){
			return ptr[i%len];
		}
};

class B : public A{
	
	double x;
	
	public:
		B(short m, double y, char c):A(m, c){
			x=y;
		}
		double foo(short s){	
			return (double)sin(x+s)/log(x+s);
		}
		string elab(short a, char c)override{
			string s= "";
			for(int i=0; i<getlen(); i++){
				if(abs(get(i)-c) <= a)  //abs(-32) = 32
					s += get(i);
				cout<<get(i)-c;
			}
			return s;
		}
		ostream& print(ostream& os)override{
			os<<"B";
			A::print(os);
			os<<"x = "<<x<<" elab(5, z) = "<<elab(5, 'z');
			return os;
		}
};

template <typename T>
class C : public A{
	T y;
	
	public: 
		C(short n, short k, char c):A(n, c){
			if(typeid(y) == typeid(short))
				y = round(100*k);
			else
				y = k;
		}
		string elab(short a, char c)override{
			string s = "";
			if(getlen()>=a){
				for(int i=0; i<a; i++)
					s += c;
			}else{
				for(int i=0; i<getlen(); i++)
					s += get(i);
			}
			return s;
		}
		double g(short w){
			return (double)sin(w+y);
		}
		ostream& print(ostream& os)override{
			if(typeid(*this) == typeid(C<double>))
				os<<"C<double";
			if(typeid(*this) == typeid(C<short>))
				os<<"C<short>";
			A::print(os);
			os<<"y = "<<y<<" elab(5, z) = "<<elab(5, 'z');
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
	for (int i=0; i<DIM; i++) {
		short n=1+rand()%10;
		switch(rand()%3){
			case 0 :
				vett[i] = new B(n, (double) rand()/RAND_MAX, rand ()%('z' - 'a' + 1)+'a');
				break ;
			case 1 :
				vett[i] = new C<double>(n , (double) rand()/RAND_MAX, rand ()%('z' - 'a' + 1)+'a');
				break ;
			case 2 :
				vett[i] = new C<short>(n , (double) rand()/RAND_MAX, rand ()%('z' - 'a' + 1)+'a');
		}
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<*vett[i]<<endl;
	}
	
	cout<<"\nPunto 2: "<<endl;
	double sum = 0.0;
	double somma = 0.0;
	int count = 0;
	int cont = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(B)){
			sum += static_cast<B*>(vett[i])->foo(5);
			//sum += ((B*)(vett[i])->foo(5);
			count ++;
		}
		if(typeid(*vett[i]) == typeid(C<short>)){
			somma += static_cast<C<short>*>(vett[i])->g(5);
			cont++;
		}
	}
	cout<<"La media per B : "<<sum/count<<endl;
	cout<<"La media per C : "<<somma/cont<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	cout<<(*vett[3])[5]<<endl;

}