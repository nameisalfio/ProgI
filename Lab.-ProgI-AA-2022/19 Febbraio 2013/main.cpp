#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <typeinfo>
#include <sstream>

using namespace std;

class A{

		float* x;

	public:

		A(float a){
			x = new float[10];
			x[0] = a;
			for(int i=1; i<10; i++)
				x[i] = sin(100 * x[i-1]);
		}

		virtual float f() = 0;

		float* getX(){return this->x;}

		string toString(){

			stringstream ss; 

			ss << "Class " << typeid(*this).name() << " [ ";
			for(int i=0; i<10; i++)
				ss << x[i] << ", ";
			ss << " ], f()= " << f() ;

			return ss.str();
		}
};

class B : public A{

	public:

		B(float b) : A(b){}

		float f(){

			float* vet = getX();
			float max = vet[0];

			for(int i=0; i<10; i++)
			{
				if(vet[i] > max)
					max = vet[i];
			}

			return max;
		}

		string toString(){
			stringstream ss;
			ss << A::toString();
			return ss.str();
		}
};

class C : public A{

	public:

		C(float c) : A(c){}

		float f(){

			float* vet = getX();
			float avg = 0.0;

			for(int i=0; i<10; i++)
				avg += vet[i];

			return (float)(avg/10);
		}

		int gte(float thr){

			float* vet = getX();
			int count = 0;

			for(int i=0; i<10; i++)
			{
				if(vet[i] > thr)
					count++;
			}

			return count;
		}

		string toString(){
			stringstream ss;
			ss << A::toString();
			return ss.str();
		}
};

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
			c = new C(seed/3);
		}

		float m(){

			A* p;

			if(typeid(*a) == typeid(*b))
				p = b;

			else if(typeid(*a) == typeid(*c))
				p = c;

			float val;
			float* a_vet = a->getX();
			float* p_vet = p->getX();

			for(int i=0; i<10; i++)
			{
				if(i%2 == 0)
					val += a_vet[i] > p_vet[i] ? a_vet[i] : p_vet[i];
			}

			return val;
		}

		float h(float thr){

			float val = (float)(c->f()/b->f());

			if(typeid(*a) == typeid(C))
				val *= static_cast<C*>(a)->gte(thr);

			return val;
		}

		string toString(){

			stringstream ss ;
			ss << a->toString() << endl;
			ss << b->toString() << endl;
			ss << c->toString() << endl;
			ss << "\nh(.7)= " << h(.7) << "\tm()= " << m() << endl;

			return ss.str();
		}
};

int main(){

	const int DIM = 50;
	D* vett[DIM];
/*
	ERRORE! Codice in C#

	Random r = new Random(347537586);
	for(int i=0; i<DIM; i++)
		vett[i] = new D(r.nextFloat());

*/
	srand(347537586);

	for(int i=0; i<DIM; i++)
		vett[i] = new D((float)rand());

	cout << endl ;

	//Punto 1:
	for(int i=0; i<DIM; i++)
	{
		cout << i << ") \n" << vett[i]->toString() << endl;
	}
/*
	//Punto 2:
	float avg = vett[0]->h(.7);

	for(int i=0; i<DIM; i++)
	{
		avg += vett[i]->h(.7);
	}
	cout << "\nMedia h(.7)= " << (float)(avg/DIM) << endl;

	//Punto 3:
	cout << "\nvett[4].m() + vett[5].m()= " << vett[4]->m() + vett[5]->m() << endl;
*/
	cout << endl ;
}