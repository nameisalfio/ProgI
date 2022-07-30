#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<typeinfo>
#include<string>
#include<cmath>

using namespace std;

class A{

        char* str;
        short len;

    public:
        short w1;
        A(short w, short t) : w1(w){
        	len = w1+t;
            str = new char[len];

            for(int i=0; i<w1; i++)
                str[i] = rand() % ('9' - '1' + 1) + '1';
            
            for(int i=w1; i<len; i++)
                str[i] = rand() % ('Z' - 'A' + 1) + 'A';
        }
        virtual double f (short a) = 0;
        virtual ostream& print(ostream& os){
            os<<typeid(*this).name()<<" [";
            for(int i=0; i<len; i++)
                os<<str[i]<<" ";
            os<<"]";
            return os;
        }
        string operator()(int i1, int i2){
            string s1 = "";
            string s2 = "";

            for(int i=0; i<w1; i++)
                s1 += str[i];
            for(int i=w1; i<len; i++)
                s2 += str[i];

            string s ="";
            s += s1[i1];
            s += s2[i2];
            return s;
        }

    protected:
        double perc(){
            int count = 0;
            for(int i=0; i<len; i++)
            {
                if(str[i] != 'a' && str[i] != 'A' &&
                   str[i] != 'e' && str[i] != 'E' &&
                   str[i] != 'i' && str[i] != 'I' &&
                   str[i] != 'o' && str[i] != 'O' &&
                   str[i] != 'u' && str[i] != 'U' )
                count++;
            }
            return (count * 100)/len;
        }
};

class B : public A {

        short p;

    public:
        B(short a, short b) : A(a, b){
            if(A::perc() < 20)
                p = rand()% (b - a + 1) + b;
            else
                p = abs((a + b)/2)+1;
        }
        double f (short a){
            return a*log(perc()/p);
        }
        ostream& print (ostream& os){
            A::print(os);
            os<<" p="<<p;
            return os;
        }
};

template <typename T>
class C : public A{

        T y;

    public:
        C(short n, double alpha, double beta) : A(n, 2*n){
            if(typeid(y) == typeid(short))
                y = n;
            else
                y = -1 * (beta-alpha)*(1.0*rand()/RAND_MAX)+alpha;
        }
        double f (short a){
            return sin(10 * y + perc())/a;
        }
        double g(double k){
            return k/f(k);
        }
        ostream& print (ostream& os){
            A::print(os);
            os<<" y="<<y;
            return os;
        }
};

ostream& operator<< (ostream& os, A& a){
    return a.print(os);
}

int main(){

    srand(11223367);
    const int DIM = 50;
    A* vec[DIM];
    for(unsigned short i=0; i<DIM; i++){
        short r = rand()%3; 
        if(r==0) // C<double>
        vec[i] = new C<double>(rand()%5+5, rand()%5+5 + rand()/(RAND_MAX*1.0), rand()%10+10 + rand()/(RAND_MAX*1.0));
        else if(r==1)
        vec[i] = new C<short>(rand()%5+5, rand()%5+5 + rand()/(RAND_MAX*1.0), rand()%10+10 + rand()/(RAND_MAX*1.0));
        else // B
        vec[i] = new B(rand()%5+5, rand()%15+10);
    }

    int count = 0;
    int num = 0;
    double max;
    for(int i=0; i<DIM; i++)
    {
        cout<<i<<") "<<*vec[i]<<endl;
        if(vec[i]->f(12) > 5)
            num++;

        if(typeid(*vec[i]) == typeid(C<double>))
        {
            max = static_cast<C<double>*>(vec[i])->g(12);
            if(static_cast<C<double>*>(vec[i])->g(12) > max)
            max = static_cast<C<double>*>(vec[i])->g(12);
        }
    }
    cout<<endl<<"Max_g(12)="<<max<<"\tNum_f(12)="<<num<<endl;
    cout<<endl<<"Vec[0](2,4)="<<(*vec[0])(2,4);
}