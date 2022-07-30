#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
#include<string>
#include<cmath>

using namespace std;

class A{
	
	int x;
	
	public: 
		A(int m):x(m){}
		virtual double v(int a) = 0;
		
		virtual ostream& print (ostream& os){
			os<<typeid(*this).name()<<" , x = "<<x<<", ";
			return os;
		}
		
		virtual int operator[] (int i) = 0;
}; 

class B : public A{
	
	int* ptr;
	int l;
	
	public:
		B(int z, int y) : A(z){
			l=y;
			ptr = new int[l];
			for(int i=0; i<l; i++){
				ptr[i] = (rand()%100)+1;
			}
		}
		double v(int a){
			return (double) l*1000/(sum(a)+1);
		}
		virtual ostream& print(ostream& os)override{
			A::print(os);
			os<<"ptr = [ ";
			for (int i=0; i<l; i++)
				os<<ptr[i]<<" ";
			os<<"], v(50) = "<<v(50);
			return os;
		}
		int operator[](int i)override{
			return ptr[i%l];
		}
		
	protected:
		int sum (int t){
			int sum = 0;
			for(int i=0; i<l; i++){
				if(ptr[i] <= t)
					sum += ptr[i];
			}
			return sum;
		}
};

template <typename T>
class C : public A{
	
	T k;
	
	public: 
	
	C(int n):A(n){
		if(typeid (k) == typeid (int))
			k=2*n;
		else
			k=log(1+pow(sin(n),2));
	}
	double v (int r){
		return g(r);
	}
	T g (T w){
		return k*(w+1);
	}
	ostream& print(ostream& os)override{
		A::print(os);
		os<<"k = "<<k<<", v(50) = "<<v(50);
		return os;
	}
	virtual int operator[] (int i) {
		return 0;
	}
	

};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
	
	const int DIM=50;
	
	srand (111222333);
	A *vett[DIM];
	for (int i=0; i<DIM; i++) {
	int n=1+rand ( )%10;
		switch (rand ()%3){
			case 0 :
				vett [i]= new B(n , rand()%10 + 1);
				break ;
			case 1 :
				vett [i]= new C<int>(n);
				break ;
			case 2 :
				vett [i]= new C<double>(n);
		}
	}
	
	cout<<"Punto 1: "<<endl;
	for(int i=0; i<DIM; i++){
		cout<<i<<") "<<(*vett[i])<<endl;
	}
	
	cout<<"\nPunto 2: "<<endl;
	int max = vett[0]->v(50);
	int min = vett[0]->v(50);
	double sum = 0.0;
	int count = 0;
	
	for(int i=0; i<DIM; i++){
		if(vett[i]->v(50) > max)
			max = vett[i]->v(50);
		if(vett[i]->v(50) < min)
			min = vett[i]->v(50);
		if(typeid(*vett[i]) == typeid(C<double>)){
			sum += ((C<double>*)vett[i])->g(5);
			count++;	
		}

	}
	cout<<"Max = "<<max<<endl;
	cout<<"Min = "<<min<<endl;
	cout<<"Media = "<<sum/count<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	if(typeid(*vett[2]) == typeid(B))
		cout<<(*vett[2])[5]<<endl;
}