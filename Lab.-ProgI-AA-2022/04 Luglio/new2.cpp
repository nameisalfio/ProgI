#include<iostream>
#include<stdlib.h>
#include<string.h>
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
            {
                values[i] = input_values[i];
            }
            accumulated_value = value;
            tossed = 0;
        }

    //Possibile(non doverosa) ridefinizione del metodo nelle classi derivate
        virtual T toss(){

            value = values[rand()%num_values];
            tossed++;
            accumulated_value += value;

            return value;
        }

        T getValue(){return this->value;}

        int getTossed(){return this->tossed;}

    //Rende AbstractRandomGenerator una classe astratta
    //Se non ridefinita nelle derivate le rende astratte(non sarà possibile istanziarle)
        virtual void nudge() = 0;

    //Possibile(non doverosa) ridefinizione del metodo nelle classi derivate
        virtual ostream& print(ostream& os){

            os << "Class " << typeid(*this).name() << ", values= { ";
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

        Dice() : AbstractRandomGenerator<int>{1, 6, new int[]{1, 2, 3, 4, 5, 6}},doubles(0){}

        //Override
        void nudge(){
            
            value += (rand()%3)-1;

            if(value > 6){
                value = 6;
            }else if(value < 1){
                value = 1;
            }
        }

        //Override
        int toss(){

            int last = value;
            if(last == AbstractRandomGenerator<int>::toss())
                doubles++;
            
            return value;
        }

        double getDoubleRate(){return (double)doubles/tossed;}
};

class Coin : public AbstractRandomGenerator<string>{

    int nudge_prob;

    public:

        Coin(int nudge_prob) : AbstractRandomGenerator{"H", 2, new string[]{"H", "T"}}, 
        nudge_prob(nudge_prob){}

        //Overriding
        void nudge(){

            if(rand()%nudge_prob == 0){

                if(value == "H")
                    value = "T";

                else if(value == "T")
                    value = "H";
            }
        }
};

template<typename T>
ostream& operator<< (ostream& os, AbstractRandomGenerator<T>& obj){return obj.print(os);}

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
    
    //Punto 1:
    for(int i=0; i<DIM; i++)
    {
    	cout << i+1 << ") " << *vec1[i] << endl;
    	cout << i+1 << ") " << *vec2[i] << endl;
    }

    //Punto 2:
    int min = vec2[0]->getTossed();
    for(int i=0; i<DIM; i++)
    {
    	if(vec2[i]->getTossed() < min)
            min = vec2[i]->getTossed();
    }

    cout << "\nMin: " << min << endl;

    //Punto 3:
    double max = static_cast<Dice*>(vec1[0])->getDoubleRate();
    for(int i=0; i<DIM; i++)
    {
    	if(static_cast<Dice*>(vec1[i])->getDoubleRate() > max)
    		max = static_cast<Dice*>(vec1[i])->getDoubleRate();
    }
    cout << "\nMax: " << max << endl;

    cout << endl;  
}