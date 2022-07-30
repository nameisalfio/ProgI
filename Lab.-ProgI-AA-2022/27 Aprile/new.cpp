#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>

using namespace std;

class Wheel{

	int value;
	int default_value;
	int num_faces;

	public:
		Wheel(int initial_value, int num_faces):num_faces(num_faces),
		 value(initial_value), default_value(initial_value){}

		void rotate(int turns){
			this->value = (value + turns)%num_faces;
		}

		int getValue(){return this->value;}

		void reset(){this->value = default_value;}
};

class AbstractSlotMachine{

	protected:
		Wheel** wheels;
		int num_wheels;
		int prize; 
		int num_spins;
		int num_wins;

	public:
		AbstractSlotMachine(int num_wheels, int num_faces):num_wheels(num_wheels), 
		prize(0), num_spins(0), num_wins(0){

			wheels = new Wheel*[num_wheels];
			for(int i=0; i<num_wheels; i++)
				wheels[i] = new Wheel(rand()%num_faces, num_faces);
		}

		virtual int spin() = 0;

		int getPrize(){return this->prize;}

		double getWinRate(){return (double)num_wins/num_spins;}

		void reset(){

			for(int i=0; i<num_wheels; i++)
				wheels[i]->reset();
		}

		virtual ostream& print(ostream& os){
			os << "Class: " << typeid(*this).name() << ", num_wheels= " << num_wheels
			<< ",prize= " << prize << ", num_spins= " << num_spins << ", num_wins= " 
			<< num_wins << ", winRate= " << getWinRate();

			return os;
		}
};

class ThreeWheelsSlotMachine : public AbstractSlotMachine{

	int num_max;

	public:
		ThreeWheelsSlotMachine() : AbstractSlotMachine{3, 6}{}

		int spin()override{

			num_spins++;

			int vals[num_wheels];

			for(int i=0; i<num_wheels; i++)
			{
				wheels[i]->rotate(rand()%8 + 3);
				vals[i] = wheels[i]->getValue();
				prize += vals[i];
			}

			bool vincente = true;

			for(int i=0; i<num_wheels; i++)
			{
				for(int j=i+1; j<num_wheels; j++)
				{
					if(vals[i] != vals[j])
						vincente = false;
				}
			}

			if(vincente)
			{
				num_wins++;
				if(vals[0] == 5) 
				{
					num_max++;
					prize *= 2;
				}
				int aux = prize;
				prize = 0;

				return aux;
			}

			return 0;
		}

		int getNumMax(){return this->num_max;}

		ostream& print(ostream& os)override{
			AbstractSlotMachine::print(os);
			return os << ", num_max= " << num_max ;
		}
};

class TenWheelsSlotMachine : public AbstractSlotMachine{

	public:
		TenWheelsSlotMachine() : AbstractSlotMachine{5, 10}{}

		int spin()override{

			num_spins++;
			int last = 0;
			int vals[num_wheels];

			for(int i=0; i<num_wheels; i++){

				int turns = (rand()%8 + 3) + round(last/3);
				last = turns;

				wheels[i]->rotate(turns);

				vals[i] = wheels[i]->getValue();
				prize += vals[i];

			}

			bool duplicate = false;

			for(int i=0; i<num_wheels; i++)
			{
				for(int j=i+1; j<num_wheels; j++)
				{
					if(vals[i] == vals[j])
						duplicate = true;
				}
			}

			if(!duplicate){
				num_wins++;
				int aux = prize;
				prize = 0;

				return aux;
			}
			else
				return 0;
		}

		ostream& print(ostream& os)override{
			AbstractSlotMachine::print(os);
			return os;
		}
};

ostream& operator<< (ostream& os, AbstractSlotMachine& obj){return obj.print(os);}

int main(){

	srand(424242);
    const int DIM = 15;

    AbstractSlotMachine* vec [DIM];
    
    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new ThreeWheelsSlotMachine();
        } else {
            vec[i] = new TenWheelsSlotMachine();
        }
    }
    
    for(int i=0; i<DIM*100; i++) {
            vec[rand()%DIM]->spin();
            if(rand()%5==0)
            vec[rand()%DIM]->reset();
    }

    cout << endl;

    //Punto 1:
    for(int i=0; i<DIM; i++)
    	cout << i+1 << ") " << *vec[i] << endl;

    //Punto 2:
    double max = vec[0]->getWinRate();
    for(int i=0; i<DIM; i++)
	{
		if(vec[i]->getWinRate() > max)
			max = vec[i]->getWinRate();
	}
	cout << "\nMax: " << max << endl;

	//Punto 3:
	double avg = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
		{
			avg += static_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
			count ++;
		}
	}
	cout << "\nAvg: " << (double)avg/count << endl;

}