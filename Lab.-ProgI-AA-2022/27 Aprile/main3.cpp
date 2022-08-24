#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>

using namespace std;

class Wheel{

	int value;
	int default_value;
	int num_faces;

public:
	Wheel(int initial_value, int num_faces):num_faces(num_faces), value(initial_value), default_value(initial_value){}

	void rotate(int turns){value = (value + turns)%num_faces;}

	int getValue(){return value;}

	void reset(){value = default_value;}
};

class AbstractSlotMachine{

protected:
	Wheel** wheels;
	int num_wheels;
	int prize;
	int num_spins;
	int num_wins;

public:
	AbstractSlotMachine(int num_wheels, int num_faces):num_wheels(num_wheels), prize(0), num_spins(0), num_wins(0){
		wheels = new Wheel*[num_wheels];
		for(int i=0; i<num_wheels; i++){
			wheels[i] = new Wheel(rand()%num_faces, num_faces);
		}
	}

	virtual int spin()=0;

	int getPrize(){return prize;}

	double getWinRate(){return(double)num_wins/num_spins;}

	void reset(){
		for(int i=0; i<num_wheels; i++){
			if(wheels[i]){
				wheels[i]->reset();
			}
		}
	}

	virtual ostream& print(ostream& os){
		os << "Class=" << typeid(*this).name() << ", num_wheels= " << this->num_wheels;
		os << ", prize= " << this->prize << ", num_spins= " << this->num_spins;
		os << ", num_wins= " << this->num_wins << ", winrate= " << this->getWinRate() ;

		return os;	
	}
};

class ThreeWheelsSlotMachine : public AbstractSlotMachine{

	int num_max;

public:
	ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6){}

	int spin(){
		num_spins++;

		int vals[num_wheels];

		for(int i=0; i<num_wheels; i++){
			wheels[i]->rotate(3 + rand()%8);
			vals[i] = wheels[i]->getValue();
			prize += vals[i];
		}

		bool winning = true;
		for(int i=0; i<num_wheels; i++){
			for(int j=i+1; j<num_wheels; j++){
				if(vals[i] != vals[j])
					winning = false;
			}
		}

		if(winning){		
			num_wins++;

			if(vals[0] == 5){			//il massimo valore per una Wheel è num_faces-1 (5)
				prize *= 2;
				num_max++;
			}

			int aux = prize;
			prize = 0;
			return aux;
		}

		return 0;
	}

	int getNumMax(){return num_max;}

	ostream& print(ostream& os){
		AbstractSlotMachine::print(os);
		return os << ", num_max= " << num_max;
	}
};

class TenWheelsSlotMachine : public AbstractSlotMachine{

public:
	TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}

	int spin(){
		num_spins++;
		int vals[num_wheels];
		int prev = 0;

		for(int i=0; i<num_wheels; i++){

			int turns = (3 + rand()%8) + round(prev/3);
			prev = turns;

			wheels[i]->rotate(turns);
			vals[i] = wheels[i]->getValue();
			prize += vals[i];
		}

		bool winning = true;
		for(int i=0; i<num_wheels; i++){
			for(int j=i+1; j<num_wheels; j++){
				if(vals[i] == vals[j])
					winning = false;
			}
		}

		if(winning){
			num_wins ++;
			int aux = prize;
			prize = 0;

			return aux;
		}
		return 0;
	}

};

ostream& operator<< (ostream& os, AbstractSlotMachine& ref){return ref.print(os);}

int main(){

	srand(424242);

	const int DIM = 15;

	AbstractSlotMachine* vec[DIM];
	 
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
	for(int i=0; i<DIM; i++){
		cout << i+1 << *vec[i] << endl;
	}

	//Punto 2:
	double max = vec[0]->getWinRate();
	for(int i=0; i<DIM; i++){
		if(vec[i]->getWinRate() > max)
			max = vec[i]->getWinRate();
	}
	cout << "\nMax: " << max << endl;

	//Punto 3:
	double sum = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
			sum += static_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
			count ++;
		}
	}
	cout << "\nAvg: " << (double)sum/count << endl;

}