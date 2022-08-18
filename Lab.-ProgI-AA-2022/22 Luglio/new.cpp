#include<iostream>
#include<cstdlib>
#include<typeinfo>

using namespace std;

class Tank{

	double capacity;  //capienza del serbatoio
	double fuelLevel; //livello del carburante

public:

	Tank(double capacity, double fuelLevel): capacity(capacity), fuelLevel(fuelLevel){}

	double getCapacity(){return this->capacity;}

	double fill(double fuel){

		if((fuelLevel + fuel) <= capacity){
			fuelLevel += fuel;
			return 0;
		}else{
			int temp = fuelLevel;
			fuelLevel = capacity;
			return (temp+fuel) - capacity;
		}
	}

	bool consume(double fuel){

		if(fuel <= fuelLevel){
			fuelLevel -= fuel;
			return true;
		}
		return false;
	}

	double getTankLevel(){return (double)fuelLevel/capacity;}

	bool hasFuel(double fuel){

		if(fuelLevel >= fuel){
			return true;
		}
		return false;
	}

	double getFuelLevel(){return this->fuelLevel;}
};

class Vehicle{

protected:

	int wheels;
	Tank tank;
	double chilometers; //numero di chilometri percorsi

public:

	Vehicle(double wheels, double chilometers, double tankCapacity, double fuelLevel):wheels(wheels), 
	chilometers(chilometers), tank(tankCapacity, fuelLevel){}

	virtual bool drive(double km) = 0;

	double getTankLevel(){return tank.getTankLevel();}

	virtual ostream& print(ostream& os){
		os << "Class: " << typeid(*this).name() << ", wheels= " << wheels << ", chilometers= " << chilometers;
		return os << ", tank.getCapacity()= " << tank.getCapacity() << ", tank.getFuelLevel()= " << tank.getFuelLevel();
	}
};

class Car : public Vehicle{

protected:

	int times;

public:

	Car(double chilometers):Vehicle{4, chilometers, 55, 25}, times(0){}

	bool drive(double km){

		double fuel = km * 0.075;

		if(getTankLevel() <= 1/2)
			fuel -= (fuel*5)/100;

		if(tank.hasFuel(fuel)){
			tank.consume(fuel);
			chilometers += km;
			times ++;

			return true;
		}else
			return false;
	}

	int getTimes(){return this->times;}

	ostream& print(ostream& os){
		Vehicle::print(os);
		return os << ", times= " << times;
	}
};

class Truck : public Vehicle{

public:

	Truck(double chilometers) : Vehicle{6, chilometers, 110, 50}{}

	bool drive(double km){

		double fuel = km*0.4;

		if(chilometers > 200000)
			fuel += (fuel*20)/100;

		if(tank.hasFuel(fuel)){
			tank.consume(fuel);
			chilometers += km;

			return true;
		}else
			return false;
	}
};

ostream& operator<< (ostream& os, Vehicle& v){return v.print(os);}

int main(){

	const int DIM = 10;
	Vehicle* vec[DIM];

	srand(424242);

    for(int i=0; i<DIM; i++) {
        int chilometers = rand()%200000;
        if(rand()%2){
            vec[i] = new Car(chilometers);
        } else {
            vec[i] = new Truck(chilometers);
        }
    }
 
    for(int i=0; i<DIM*5; i++) {
        int x = rand()%100;
        vec[x%DIM]->drive(x);
    }

    cout << endl;

    //Punto 1:
    for(int i=0; i<DIM; i++){
    	cout << i << ") " << *vec[i] << endl;
    }

    cout << endl;

}