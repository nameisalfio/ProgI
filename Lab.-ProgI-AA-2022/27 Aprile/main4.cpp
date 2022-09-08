//Frame: https://pastebin.com/MXN4kwkx
//Output: https://pastebin.com/mZBCf0s5

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Wheel{
	int value;
	int default_value;
	int num_faces;
public:
	Wheel(int initial_value, int num_faces):num_faces(num_faces){
		value = initial_value;
		default_value = initial_value;
	}
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
	AbstractSlotMachine(int num_wheels, int num_faces):num_wheels(num_wheels), prize(0), num_wins(0), num_spins(0){
		wheels = new Wheel*[num_wheels];
		for(int i=0; i<num_wheels; i++)
			wheels[i] = new Wheel{rand()%num_faces, num_faces};
	}
	virtual int spin()=0;
	int getPrize(){return prize;}
	double getWinRate(){return (double)num_wins/num_spins;}
	void reset(){
		for(int i=0; i<num_wheels; i++)
			wheels[i]->reset();
	}
	virtual ostream& print(ostream& os){
		os << "Class: " << typeid(*this).name() << ", num_wheels= " << num_wheels;
        os << ", prize= " << prize << ", num_spins= " << num_spins << ", num_wins= " << num_wins;
        os << ", winrate= " << getWinRate();	
        return os;
    }
};

class ThreeWheelsSlotMachine : public AbstractSlotMachine{
private:
	int num_max;
public:
	ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6), num_max(0){}
	int spin(){
		num_spins ++;
		int vals[num_wheels];

		for(int i=0; i<num_wheels; i++){
			wheels[i]->rotate(3 + rand()%(8));
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
			if(vals[0] == 5){
				prize *= 2;
				num_max ++;
			}
			int aux = prize;
			prize = 0;
			return aux;
		}else
			return 0;
	}
	int getNumMax(){return num_max;}
	ostream& print(ostream& os){
		AbstractSlotMachine::print(os);
		return os << ", num_max=" << num_max;
	}
}; 

class TenWheelsSlotMachine : public AbstractSlotMachine{
public:
	TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}
	int spin(){
		num_spins ++;
		int vals[num_wheels];
		int last=0;

		for(int i=0; i<num_wheels; i++){
			int turns = 3 + rand()%(8) + round(last/3);
			last = turns;

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
		}else
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
	double avg = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
			avg += static_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
			count ++;
		}
	}
	cout << "\nAvg: " << (double)avg/count << endl;

}