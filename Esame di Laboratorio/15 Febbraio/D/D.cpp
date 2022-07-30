#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<typeinfo>

using namespace std;

class A{
	
	int * ptr;
	short len;
	public:
		
		A(short m, short k): len(m){
			ptr = new int[len];
			for(int i = 0; i<len; i++){
				ptr[i] = rand()%(k-1+1)+1;
			}
			
		}
		virtual double f() const = 0;
		int get(short i)const{
			return ptr[i%len];
		}
		
		short get_len()const{
			return len;
		}
		
		virtual ostream& print (ostream &os){
			os<<typeid (*this).name()<< ", ptr = [";
			for(int i = 0; i<get_len(); i++){
				os<<ptr[i]<<" ";
			}
			os<<"] ,";
			return os;
		}
		double operator[] (int i){
			return ptr[i%len];
		} 
};

class B: public A{
	
	double p;
	
	public:
		B(short m, short k,double y):A(m,k){
			p = y;
		}
		double f ()const{
			double somma = 0.0;
			for(int i = 0; i<get_len(); i++){
				if(get(i)%2 == 0)
				somma += get(i);
			}
			return (double)somma/p;
		}
		virtual ostream& print (ostream &os){
			A::print(os);
			os<<" p = "<<p<<", f() = "<<f()<<endl;
			return os;
		}		
};

class C: public A{
	
	char x;
	
	public :
		C(short n, short k,char c): A(n,k){
			x = c;
		}
		double  f ()const{
			double somma = 0.0;
			for(int i = 0; i<get_len(); i++){
				if(get(i)%2 != 0)
					somma+= get(i);
			}
			if(somma == 0){
				return 0;
			}
			else{
				return somma;
			}
		}
		string g(char c)const{
			string s = "";
			string h = "";
			s = x;
			h = c;
			s+=h;
			return s;
		}
		virtual ostream& print (ostream &os){
			A::print(os);
			os<<" x = "<<x<<", f() = "<<f()<<endl;
			return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	srand ( 111222333 );
	const int DIM = 50;
	A *vett [DIM] ;
	for ( int i =0; i<DIM; i ++){
	short n=1+rand ( )%10;
	short m = 1+rand ( )%8;
	if (rand ()%2==0)
		vett[i]= new B( n , m, rand()/(double)RAND_MAX+0.05);
	else
		vett [i]= new C( n , m, (char) (rand()%('z'-'a' + 1) + 'a'));
	}

	cout<<"PUNTO 1"<<endl;
	for(int i =0 ; i<DIM; i++){
		cout<<i<<")"<<*vett[i]<<endl;
	}
	
	cout<<"\nPUNTO 2"<<endl;
	double sum = 0.0;
	string conc = "";
	for(int i=0; i<DIM; i++){
		sum += vett[i]->f();
		if(typeid(*vett[i]) == typeid(C))
			conc += ((C*)vett[i])->g('h');
	}
	cout<<"Media : "<<sum/DIM<<endl;
	cout<<conc<<endl;
	
	cout<<"\nPUNTO 3"<<endl;
	cout<<(*vett[5])[3]<<endl;

}