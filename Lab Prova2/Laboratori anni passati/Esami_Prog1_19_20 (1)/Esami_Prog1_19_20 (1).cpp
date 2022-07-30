#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<cmath>
#include<typeinfo>
using namespace std;

class A {

    short* vec;
    short len;

    public:
        A(short m, short a, short b):len(m){
            vec = new short[len];
            for(int i=0; i<len; i++)
            {
                int r = rand()%2;
                if(r == 0)
                    vec[i] = 1+rand()%a;
                else
                    vec[i] = rand()%(b-a+1)+a;
            }
        }

        virtual double foo (short a) = 0;

        short get_len(){
            return len;
        }

        virtual ostream& print (ostream& os){
            os<<"Class="<<typeid(*this).name()<<", vec=[";
            for(int i=0; i<len; i++)
                os<<vec[i]<<" ";
            os<<"], ";
            return os;
        }

        short operator()(int i1, int i2){
            return get(i1)*get(i2);
        }

    protected:
        int get(short i){
            return vec[i];
        }
};

class B : public A {

    double p;

    public:
        B(short m, short x, short y) : A(m, x, y){
            p = log(m+1) + (x*y);
        }

        double foo(short a){
            return prod(a)/p;
        }

        ostream& print(ostream& os){
            A::print(os);
            os<<"p="<<p<<", foo(3)="<<foo(3);
            return os;
        }

    protected:
        double prod(short s){
            int prod = p * log(s*s+1);
            short index = s%get_len();
            for(int i=0; i<index; i++)
                prod *= get(i);
            
            return prod;
        }

};

template<typename T>
class C : public A{

    T x;

    public:
        C(short n, int a, int b) : A(n, a, b){
            if(typeid(x) == typeid(bool))
            {
                int r = rand()%2;
                if(r == 0)
                    x = false;
                else
                    x = true;
            }
            else
                x = (b-a)*10;
        }

        double foo(short r){
            return g(r * rand()%10);
        }

        double g(double k){
            if(x)
                return sin(k+1);

            return cos(k+1);
        }

        ostream& print(ostream& os){
            A::print(os);
            os<<"x="<<x<<", foo(3)="<<foo(3);
            return os;
        }
};

ostream& operator<< (ostream& os, A& a){
    return a.print(os);
}

int main(){
    const int DIM = 50;
    srand(111222333);

    A* vett[DIM];
    for(int i=0; i<DIM; i++) {
		short n=5+rand()%5;
		switch(rand()%3) {
		  case 0: 
		    vett[i]= new B(n, rand()%5 + 1, rand()%10 + 5);
		    break;
		  case 1:
		    vett[i]= new C<short>(n, rand()%5 + 1, rand()%10 + 5);
		    break;
		  case 2: 
		    vett[i]= new C<bool>(n, rand()%5 + 1, rand()%10 + 5);
		}
    }

    cout<<"Punto 1: "<<endl;
    for(int i=0; i<DIM; i++)
        cout<<i<<") "<<*vett[i]<<endl;
//-----------------------------------------------------------------------
    cout<<"\nPunto 2: "<<endl;
    int max = vett[0]->foo(3);
    for(int i=0; i<DIM; i++)
    {
        if(vett[i]->foo(3) > max)
            max=vett[i]->foo(3);
    }

    double sum = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++)
    {
        if(vett[i]->foo(3) > max)
            max=vett[i]->foo(3);
        if(typeid(vett[i]) == typeid(C<short>))
        {
            sum += static_cast<C<short>*>(vett[i])->g(5);
            count++;
        }
    }
    cout<<"Max_foo(3)="<<max<<"\nAvg_g(5)="<<sum/count<<endl;
//-----------------------------------------------------------------------
    cout<<"\nPunto 3: "<<endl;
    cout<<"Vett[10](4, 8)="<< (*vett[10])(4, 8);
}