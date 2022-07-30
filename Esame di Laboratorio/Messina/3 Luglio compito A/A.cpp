#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

class A{
	
	int* arr;
	short len;
	
	public:
		A(short m, int a, int b):len(m){
			arr = new int[len];
			for(int i=0; i<len; i++)
				arr[i] = rand()%(b-a+1)+a;
		}
		virtual double func (short i) = 0;
		short getlen()const{
			return len;
		}
		virtual ostream& print(ostream& os){
			os<<typeid(*this).name()<<", arr[";
			for(int i=0; i<len; i++)
				os<<arr[i]<<" ";
			os<<"], ";
			return os;
		}
		int& operator[] (int i){
			return arr[i%len];
		}
	protected:
		double get(short i)const{
			return arr[i%len];
		}
};

class B : public A {
	
	double p;
	
	public:
		B(short m, int y, int z, double x):A(m, y, z){
			p = x;
		}
		
		
		virtual double func (short i)override{
			double min = get(0);
			double max = get(0);
			for(i=0; i<getlen(); i++){
				if(get(i) > max)
					max = get(i);
				if(get(i) < min)
					min = get(i);
			}
			return (double) min/max + p;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"p="<<p<<", func(3)="<<func(3);
			return os;
		}
		B operator++ (int){
			B aux = *this;
			p++;
			return aux;
		}
		friend B operator+ (B b1, B b2);
};

class C : public A {
	
	char t;
	
	public:
		C(short n, char c, int a, int b):A(n, a, b){
			t = c;
		}
		virtual double func (short i)override{
			double sum = 0.0;
			for(int i=0; i<getlen(); i++)
				sum += get(i);
			return sum/getlen();
		}
		string g(char c, short k){
			string s="";
			for(int i=0; i<k; i++){
				s += t;
				s += c;
			}
			return s;
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"t="<<t<<", func(3)="<<func(3);
			return os;
		}
};

ostream& operator<< (ostream& os, A&a){
	return a.print(os);
}

int main(){
	const int DIM = 50;
	srand(111222333);   
	A* vett[DIM];  
    for(int i=0; i<DIM; i++){
		short n=1+rand()%10;
		if(rand()%2==0)
	  		vett[i]= new B(n, rand()%5+1, rand()%11+10, (double) rand()/(RAND_MAX));
		else
	  		vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'), rand()%5+1, rand()%11+10);
    }
    
    cout<<"Punto 1: "<<endl;
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
    	
    cout<<"\nPunto 2: "<<endl;
    double sum = 0.0;
    for(int i=0; i<DIM; i++)
    	sum += (vett[i])->func(3);
    	
    string s="";
    int count = 0;
    for(int i=0; i<DIM; i++){
    	if(typeid(*vett[i]) == typeid(C)){
    	    s += static_cast<C*>(vett[i])->g('h',2);
    	    s += " ";
    		count++;	
		}
		if(count == 3)
			break;
	}
    cout<<"Avg: "<<sum/DIM<<endl; 
    cout<<"Concatenazione: "<<s<<endl;
    
    cout<<"\nPunto 3: "<<endl;
    (*vett[5])[3] = 7;
    cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
    (*vett[5])[3] = 1;
    cout<<"vett[5]= "<<(*vett[5])[3]<<endl;
    
    cout<<"\nPunto extra: "<<endl;
    if(typeid(*vett[5]) == typeid(B)){
    	cout<<"*vett[5]: \n"<<(*vett[5])<<endl;
    	(*static_cast<B*>(vett[5]))++;
    	//(*(B*)(vett[5]))++;
    	cout<<"Overloading: \n"<<(*vett[5])<<endl;
	}
    
}