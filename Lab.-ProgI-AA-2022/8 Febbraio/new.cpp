#include<iostream>
#include<stdlib.h>
#include<typeinfo>
#include<string>
#include<math.h>

using namespace std;

class AbstractRandomVec{

	protected:
		int* vet;
		int num;

	public:
		AbstractRandomVec(int n, int min, int max):num(n){
			vet = new int[num];
			for(int i=0; i<num; i++)
				vet[i] = rand()%(max-min+1)+min;
		}

		virtual int count() = 0;
		
        int* get(int i) {
            if(i >= num) 
            	return nullptr;
            return (vet + i); // return &vet[i]
        }

        int numel(){return num;}

        float mean(){

        	float avg = 0.0;
        	for(int i=0; i<num; i++)
        		avg += vet[i];

        	return (float)avg/num;
        }

        virtual ostream& print(ostream& os){
        	os << "Class: " << typeid(*this).name() << ", num= " << num << ", vec=[ ";
        	for(int i=0; i<num; i++)
        		os << vet[i] << " ";
        	os << " ]";

        	return os;
        }


};

class TernaryVec : public AbstractRandomVec{

	public:
		TernaryVec(int n) : AbstractRandomVec{n, 0, 2}{}

		int count()override{
			int c=0;
			for(int i=0; i<num; i++)
			{
				if(vet[i]>0)
					c ++;
			}

			return c;
		}

		ostream& print(ostream& os)override{
			return AbstractRandomVec::print(os);
		}
};

class MultVec : public AbstractRandomVec{

	double midpoint;

	public:
		MultVec(int n, int min, int max, int mul) : AbstractRandomVec{n, min, max}, midpoint((float)(max+min)/2){

			for(int i=0; i<num; i++)
			{
				int r = rand() % (max-min+1)+min;
				r *= mul;

				while(!(r >= min && r <= max))
					r -= mul;			

				vet[i] = r;	
			}
		}

		int count(){
			int c=0;

			for(int i=0; i<num; i++)
			{
				if(vet[i]>midpoint)
					c ++;
			}

			return c;
		}

		int countEven(){
			int c=0;

			for(int i=0; i<num; i++)
			{
				if(vet[i]%2 == 0)
					c ++;
			}

			return c;
		}

		ostream& print(ostream& os)override{
			AbstractRandomVec::print(os);
			return os << ", midpoint= " << midpoint;
		}
};

ostream& operator<< (ostream& os, AbstractRandomVec& obj){return obj.print(os);}

int main(){

	const int DIM = 10;

	srand(424242);

	AbstractRandomVec* vett[DIM];

	for(int i=0; i<DIM; i++) {
		int n=5+rand()%5;
		int m=5+rand()%5;
		int min = rand()%10 + 5;
		int max = min + rand()%20;

		switch(rand()%2) {
			case 0: 
				vett[i]= new TernaryVec(n);
				break;
			case 1:
				vett[i]= new MultVec(n, min, max, m);
		}
	}

	cout << endl;

	//Punto 1:
	for(int i=0; i<DIM; i++)
		cout << i << ") " << *vett[i] << endl;

	//Punto 2:
	int max = vett[0]->count();
	for(int i=0; i<DIM; i++)
	{
		if(vett[i]->count() > max)
			max = vett[i]->count();
	}

	cout << "\nMax: " << max << endl;

	//Punto 3:
	double mean = 0.0;
	int c = 0;
	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vett[i]) == typeid(MultVec))
		{
			mean += static_cast<MultVec*>(vett[i])->countEven();
			c ++;
		}
	}

	cout << "\nMean: " << (float)mean/c << endl;

}