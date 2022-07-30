#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<typeinfo>

using namespace std;

template<typename T>
class AbstractRandomGenerator{

	protected:
		int num_values;
		int tossed;
		T accumulated_value;
		T value;
		T* values;
	
	public:

		AbstractRandomGenerator(T value, int num_values, T* input_values){
			this->num_values = num_values;
			this->value = value;
			values = new T[num_values];
			//values = input_values;

			for(int i=0; i<num_values; i++)
				this->values[i] = input_values[i];

			this->accumulated_value = value;
			tossed = 0;
		}

		virtual T toss(){
			value = values[rand() % num_values];
			tossed ++;
			accumulated_value += value;

			return value;
		}

		T getValue(){return this->value;}

		int getTossed(){return this->tossed;}

		virtual void nudge() = 0;

		virtual ostream& print(ostream& os){
			os << "Class " << typeid(*this).name() << ", values={ ";
			for(int i=0; i<num_values; i++)
				os << values[i] << " ";
			os << " }, value= " << value << ", accumulated_value= " << accumulated_value;
			return os << ", tossed= " << tossed;
		}
};

class Dice : public AbstractRandomGenerator<int>{

	int doubles;

	public:
		Dice() : AbstractRandomGenerator<int>(1, 6, new int[6]{1,2,3,4,5,6}){}

		void nudge(){
			int a = -1;
			int b = 1;

			value += rand()%(b-a+1)+a;
			int max = 0;
			int min = 0;

			for(int i=0; i<num_values; i++)
			{
				if(values[i] > max)
					max = values[i];
				if(values[i] < min)
					min = values[i];
			}

			if(getValue() > max)
				value = max;
			if(getValue() < min)
				value = min;
		}

		int toss(){
			int prev = value;

			if(AbstractRandomGenerator<int>::toss() == prev)
				doubles++;

			return value;
		}

		double getDoubleRate(){return double(doubles)/getTossed();}

		ostream& print(ostream& os){
			AbstractRandomGenerator<int>::print(os);
			return os;
		}
};

class Coin : public AbstractRandomGenerator<string>{
		int nudge_prob;

	public:
		Coin(int nudge_prob):AbstractRandomGenerator<string>("H", 2, new string[2]{"H", "T"}){
			this->nudge_prob = nudge_prob;
		}

		void nudge(){
			int r = rand()%nudge_prob;
			if(r == 0)
			{
				if(getValue() == "H")
					value = "T";
				else
					value = "H";
			}
		}

		ostream& print(ostream& os){
			AbstractRandomGenerator<string>::print(os);
			return os;
		}
};

template<typename T>
ostream& operator<< (ostream& os, AbstractRandomGenerator<T>& a){return a.print(os);}

int main(){
	
	const int DIM = 7;

	srand(424242);

	AbstractRandomGenerator<int>* vec1[DIM];
	AbstractRandomGenerator<string>* vec2[DIM];
 
	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}
 
    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

    cout << endl;

    //Punto 1
    for(int i=0; i<DIM; i++)
    {
    	cout << i+1 << ") " << *vec1[i] << endl;
    	cout << i+1 << ") " << *vec2[i] << endl;
    }

    //Punto 2
    int min_getTossed = vec2[0]->getTossed();

    for(int i=0; i<DIM; i++)
    {
    	if(vec2[i]->getTossed() < min_getTossed)
    		min_getTossed = vec2[i]->getTossed();
    }

    cout << "\nmin_getTossed = " << min_getTossed << endl;

    //Punto 3
    double max_getDoubleRate = static_cast<Dice*>(vec1[0])->getDoubleRate();

    for(int i=0; i<DIM; i++)
    {
    	if(static_cast<Dice*>(vec1[i])->getDoubleRate() > max_getDoubleRate)
    		max_getDoubleRate = static_cast<Dice*>(vec1[i])->getDoubleRate();
    }

    cout << "\nmax_getDoubleRate = " << max_getDoubleRate << endl;

    cout << endl;
}