//Frame: https://www.antoninofurnari.it/downloads/lab080222_1/frame-08_02_2022.cpp
//Output: https://www.antoninofurnari.it/downloads/lab080222_1/out_win.txt

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

class AbstractRandomVec{

	protected:

		int* vec;
		int num;

	public:

		AbstractRandomVec(int n, int min, int max):num(n){

			vec = new int[num];

			for(int i=0; i<num; i++)
				vec[i] = rand()%(max-min+1)+min;
		}

		virtual int count() = 0;

		int* get(int i){

			if(vec[i])
				return &vec[i];

			return nullptr;
		}

		int numel(){return num;}

		float mean(){

			float avg = 0.0;

			for(int i=0; i<num; i++)
				avg += vec[i];

			return (float) avg/numel();
		}

		virtual ostream& print(ostream& os){

			os << "Class:" << typeid(*this).name() << ", num=" << this->num << ", vec=[" ;

			for(int i=0; i<num; i++)
				os << vec[i] << " ";

			return os << "]";
		}
};

class TernaryVec : public AbstractRandomVec{

public:

	TernaryVec(int n) : AbstractRandomVec(n , 0, 2){}

	int count(){

		int count = 0;

		for(int i=0; i<numel(); i++)
		{
			if(vec[i])
				count++;
		}

		return count;
	}

	ostream& print(ostream& os)override{
		AbstractRandomVec :: print(os);
		return os;
	}
};

class MultVec : public AbstractRandomVec{

	double midpoint;

public:

	MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max){

		for(int i=0; i<num; i++)
		{
			int r = rand() % (max-min+1)+min;
			r *= mul;

			while(!(r >= min && r <= max))
				r -= mul;			

			vec[i] = r;	
		}

		midpoint = float(max+min)/2;
	}

	int count(){

		int count = 0;

		for(int i=0; i<numel(); i++)
		{
			if(vec[i] >= midpoint)
				count++;
		}

		return count;
	}

	int countEven(){

		int count = 0;

		for(int i=0; i<numel(); i++)
		{
			if(vec[i] % 2 == 0)
				count++;
		}

		return count;

	}

	ostream& print(ostream& os)override{
		AbstractRandomVec :: print(os);
		os << ", midpoint= "<< this->midpoint << endl;

		return os;
	}

};

ostream& operator<< (ostream& os, AbstractRandomVec& a){return a.print(os);}

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

	int max = vett[0]->count();
	double avg = 0.0;
	int c = 0;

	for(int i=0; i<DIM; i++)
	{
		cout << "\n" << i << ") " << *vett[i] << endl;

		if(vett[i]->count() > max)
			max = vett[i]->count();

		if(typeid(*vett[i]) == typeid(MultVec))
		{
			avg += static_cast<MultVec*>(vett[i])->countEven();
			c++;
		}
	}

	cout << "Max count(): " << max << endl;
	cout << "Avg countEven(): " << (double)avg/c << endl;

	cout << endl;

}