#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<typeinfo>

using namespace std;

class A{

        double* vec;
        short len;
    
    public:
        A(short w, double a, double b):len(w){
            vec = new double[len];
            for(int i=0; i<len; i++)
                vec[i] = (b-a)*(1.0*rand()/RAND_MAX)+a;
        }
        virtual double foo(short a) = 0;
        short get_len(){
        	return len;
		};
        virtual ostream& print(ostream& os){
            os<<typeid(*this).name()<<", vec=[";
            for(int i=0; i<len; i++)
                os<<vec[i]<<" ";
            os<<"]";
            return os;
        }

    protected:
        double get(short i){
            return vec[i];
        }

};

class B : public A{

        int p;
    
    public:
        B(short m, short x, short y):A(m, (int)x, (int)y){
            p = rand() % (100*y - 10*x + 1) + 10*x;
        }
        double foo(short a)override{
            return log(prod(a, a/2));
        }
        ostream& print(ostream& os){
            A::print(os);
            os<<"p="<<p<<", foo(3)="<<foo(3);
            return os;
        }

    protected:
        double prod(short s, double v){
            int sum = 0;
            for(int i=(s % get_len()); i<get_len(); i++)
                sum += get(i);
            return sum*v;
        }
};

template<typename T>
class C : public A{

        T y;
    
    public:
        C(short n, double x, double y) : A(n, (int)x, (int)y){
            if(typeid(y) == typeid(short))
                y = n;
            else
                y = 1 + cos(pow(n, 2));
        }
        double foo(short r)override{
            return g(r);
        }
        double g(double k){
            return 2*y*(k+1);
        }
        ostream& print(ostream& os){
            A::print(os);
            os<<"y="<<y<<", foo(3)="<<foo(3);
            return os;
        }
};

ostream& operator<< (ostream&os, A& a){
	return a.print(os);
}

int main(){

    srand(111222333);
    const int DIM = 50;
    A* vett[DIM];

    for(int i=0; i<DIM; i++) {
        short n=5+rand()%5;
        switch(rand()%3) {
        case 0: 
            vett[i]= new B(n, rand()%5 + 1, rand()%10 + 5);
            break;
        case 1:
            vett[i]= new C<double>(n, rand()%5 + 1, rand()%10 + 5);
            break;
        case 2: 
            vett[i]= new C<short>(n, rand()%5 + 1, rand()%10 + 5);
        }
    }
    
    for(int i=0; i<DIM; i++)
    	cout<<i<<") "<<*vett[i]<<endl;
}