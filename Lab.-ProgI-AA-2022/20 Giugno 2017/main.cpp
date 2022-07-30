#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<typeinfo>

using namespace std;

#define N 5

class A{

    float* x;

    public:
        A(float a){
            x = new float[N];
            x[0] = a;

            for(int i=1; i<N; i++)
                x[i] = (float) sin(100 * x[i-1]);
        }

        virtual float f() = 0;

        float* getX(){return this->x;}

        virtual ostream& print(ostream& os){

            os << "\tClass " << typeid(*this).name() << "[ ";
            for(int i=0; i<N; i++)
                os << x[i] << " ";

            return os << "]" << endl;
        }
};

class B : public A{

    public: 

        B(float b) : A(b){}

        float f() override{

            float* x = getX();
            float max = x[0];

            for(int i=0; i<N; i++)
            {
                if(x[i] > max)
                    max = x[i];
            }

            return max;
        }
        
        ostream& print(ostream& os){
            A::print(os);
            return os;
        }
};

class C : public A{

    public:

        C(float c) : A(c){}

        float f() override {
            double avg = 0.0;
            float* x = getX();

            for(int i=0; i<N; i++)
                avg += x[i];
            
            return (float)avg/N;
        }

        int gte (float thr){

            int count = 0;
            float* x = getX();

            for(int i=0; i<N; i++)
            {
                if(x[i] > thr)
                    count ++;
            }

            return count;
        }

        ostream& print(ostream& os){
            A::print(os);
            return os;
        }
};

ostream& operator<< (ostream& os, A& a){return a.print(os);}

class D{

    A* a;
    B* b;
    C* c;

    public:

        D(float seed){

            if(seed > 0.5)
                a = new B(seed);
            else 
                a = new C(seed);

            b = new B(seed/2);

            c = new C (seed/3);
        }

        float m(){

            float* vet_a = a->getX();
            float* vet_b = b->getX();
            float* vet_c = c->getX();

            float sum = 0.0;
            double max;

            for(int i=0; i<N; i++)
            {
                max = vet_a[i];

                if(vet_a[i] > max)
                    max = vet_a[i];

                if(vet_b[i] > max)
                    max = vet_b[i];

                if(vet_c[i] > max)
                    max = vet_c[i];

                sum += max;
            }

            return sum;
        }

        float h (float thr){

            float report = (float) c->f()/b->f();

            if(typeid(*a) == typeid(C))
                report *= static_cast<C*>(a)->gte(thr);

            return report;
        }

        ostream& print (ostream& os){
            os << *a << *b << *c << endl;
            os << "\t\t\t\t\t\th(.7)=" << h(.7) << "\tm()=" << m() << endl;
            return os;
        }
};

ostream& operator<< (ostream& os, D& d){return d.print(os);}

int main(){

    const int DIM = 50;
    
    D* vett[DIM];
    srand(111222333);

    for(int i=0; i<DIM; i++)
        vett[i] = new D( (float) rand()/RAND_MAX );

    cout << endl;

    double avg = 0.0;
    float sum = 0.0;
    sum += vett[4]->m() + vett[5]->m();

    for(int i=0; i<DIM; i++)
    {
        cout << i << ") " << *vett[i] << endl;

        avg += vett[i]->h(.7);
    }

    cout << "\nMedia di h(.7)= " << (float)avg/DIM << endl;
    cout << "\nSomma di (vett[4].m() + vett[5].m())= " << sum << endl;

    cout << endl;
}