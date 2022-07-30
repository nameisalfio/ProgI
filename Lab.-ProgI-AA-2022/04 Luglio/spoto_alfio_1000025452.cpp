#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<climits>
#include<iomanip>
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
        AbstractRandomGenerator(T value, int num_values, T* input_values):value(value), num_values(num_values){
            values = new T[num_values];
            for(int i=0; i<num_values; i++)
                values = input_values;
            
            accumulated_value = value;
            tossed = 0;
        }

       virtual T toss(){
            int r = rand()%num_values;
            value = values[r];
            tossed++;
            accumulated_value += value;

            return value;
       };

       T getValue(){return this->value;} 

       int getTossed(){return this->tossed;}

       virtual void nudge(){}

       virtual double getDoubleRate(){}

       virtual ostream& print(ostream& os){
            os << "Class " << typeid(*this).name() << ", values= { " ;
            for(int i=0; i<num_values; i++)
                os << values[i] << " ";
            
            os << " }, value= " << value << ", accumulated_value= " << accumulated_value;
            os << ", tossed= " << tossed;
            return os;
       }
};

class Dice : public AbstractRandomGenerator<int>{

    int doubles;

    public:

        Dice(): AbstractRandomGenerator<int>(1, 6, new int[6]{1,2,3,4,5,6}), doubles(0){}

        void nudge(){
            int a = -1;
            int b = 1;
            AbstractRandomGenerator<int>::value += rand()%(b-a+1)+a;

            int max = AbstractRandomGenerator<int>::values[0];
            int min = AbstractRandomGenerator<int>::values[0];
            for(int i=0; i<AbstractRandomGenerator<int>::num_values; i++)
            {
                if(AbstractRandomGenerator<int>::values[i] > max)
                    max = AbstractRandomGenerator<int>::values[i];
                
                if(AbstractRandomGenerator<int>::values[i] < min)
                    min = AbstractRandomGenerator<int>::values[i];
            }

            if(AbstractRandomGenerator<int>::value > max)
                AbstractRandomGenerator<int>::value = max;

            if(AbstractRandomGenerator<int>::value < min)
                AbstractRandomGenerator<int>::value = min;

        }

        int toss(){
            if(AbstractRandomGenerator<int> :: toss() == getValue())
                doubles ++;

            return getValue();
        }

        double getDoubleRate(){return (double)doubles/getTossed();}

        ostream& print(ostream& os){
            AbstractRandomGenerator<int> :: print(os);
            return os;
        }
};

class Coin : public AbstractRandomGenerator<string>{

    int nudge_prob;

    public:
        Coin(int nudge_prob) : AbstractRandomGenerator<string>("H", 2, new string[2]{"H","T"}), nudge_prob(nudge_prob){}

        void nudge(){
            int r = rand() % nudge_prob;
            if(r == 0)
            {
                if(getValue() == "T")
                    getValue() = "H";
                
                if(getValue() == "H")
                    getValue() = "T";
            }
        }

        ostream& print(ostream& os){
            AbstractRandomGenerator<string> :: print(os);
            return os;
        }
};

template<typename T>
ostream& operator<< (ostream& os, AbstractRandomGenerator<T>& obj){return obj.print(os);}

int main(){

    srand(424242);

    const int DIM = 7;
    
    AbstractRandomGenerator<int>* vec1 [DIM];
    AbstractRandomGenerator<string>* vec2 [DIM];

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

    int min = vec2[0]->getTossed();
    double max = vec1[0]->getDoubleRate();


    for(int i=0; i<DIM; i++)
    {
        cout << i << ") " << *vec1 [i] << endl;
        cout << i << ") " << *vec2 [i] << endl;

        if(vec2[i]->getTossed() < min)
            min = vec2[i]->getTossed();

        if(vec1[i]->getDoubleRate() > max)
            max = vec1[i]->getDoubleRate();

    }

    cout << "\nMinimo : " << min << endl;
    cout << "\nMassimo : " << max << endl;

    cout << endl;


}