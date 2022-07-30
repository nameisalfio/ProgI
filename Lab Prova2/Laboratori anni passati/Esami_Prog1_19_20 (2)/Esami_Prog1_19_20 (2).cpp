#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<typeinfo>
using namespace std;

class A{

    int* v;
    short len;

    public:

    A(short k, short n):len(k){
        v = new int[len];
        for(int i=0; i<len; i++)
            v[i] = rand()%n;
    }
    virtual double doit(short a) = 0;
    virtual ostream& print (ostream& os){
        os<<typeid(*this).name()<<" v=[";
        for(int i=0; i<len; i++)
            os<<v[i]<<" ";
        os<<"]";
        return os;
    }

    protected:

    double mat(short i){
        int S = 0;
        for(int a = 0; a<i; a++)
            S += v[a];
        return sin(S);
    }
};

class B : public A{

    int p;

    public:

    B(short k, short n, int p):A(k, n){
        this->p = p;
    }
    bool test(short i){
        if(A::mat(i) > 0)
            return true;
        return false;
    }
    double doit(short a){
        return A::mat(a) * log(p * rand()%100);
    }
    ostream& print (ostream& os){
        A::print(os);
        os<<"p="<<p<<", doit(3)="<<doit(3);
        return os;
    }
    B operator++ (int){  //Postfisso con Dummy parameter
        B aux = *this; 
        p++; 
        return aux; 
    }

};

class C : public A{

    double x;

    public:

        C(short k, short n, double c):A(k, n){
            this->x = c;
        }
        double doit(short r){
            return x * A::mat(r+1);
        }
        int g(int c){
            double r = rand()/RAND_MAX;
            return round(x + c*r);
        }
        ostream& print (ostream& os){
        A::print(os);
        os<<"x="<<x<<", doit(3)="<<doit(3);
        return os;
    }
};

ostream& operator<< (ostream& os, A& a){
    return a.print(os);
}

int main(){

    srand(111222333);
    const int DIM = 50;
    A* vett[DIM];
    for(int i=0; i<DIM; i++) {
        short n=1+rand()%10;
        short k = 1+rand()%10; 
        if(rand()%2==0)
            vett[i]= new B(k,n, (int)rand()%10 + 1);
        else
            vett[i]= new C (k,n, (double) (rand()%10 + 1));
    }

    double max = vett[0]->doit(3);
    double sum = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++)
    {
        cout<<i<<") "<<*vett[i]<<endl;
        if(vett[i]->doit(3) > max)
            max = vett[i]->doit(3);
        if(typeid(*vett[i]) == typeid(C))
        {
            sum += static_cast<C*>(vett[i])->g(5);
            count++;
        }
    }
    cout<<endl<<"Max_doit(3)="<<max<<"\nAvg_g(5)="<<sum/count<<endl;

    if(typeid(*vett[0]) == typeid(B)){
    	cout<<"*vett[0]: \n"<<(*vett[0])<<endl;
    	(*static_cast<B*>(vett[0]))++;
    	cout<<"Overloading: \n"<<(*vett[0])<<endl;
    }
}
