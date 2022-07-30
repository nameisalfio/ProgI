#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>

using namespace std;

class Tank{

	double capacity;
	double fuelLevel;

	public:
		Tank(double capacity, double fuelLevel):capacity(capacity), fuelLevel(fuelLevel){}

		double getCapacity(){return this->capacity;}

		double fill(double fuel)
	    {
	        double eccesso = 0;
	        if ((fuelLevel + fuel) <= capacity)
	        {
	            fuelLevel += fuel;
	            return 0;
	        }
	        else
	        {
	            eccesso = (fuelLevel + fuel) - capacity;
	            fuelLevel = capacity;
	            return eccesso;
	        }
	    }

		bool consume(double fuel){

			if(fuelLevel >= fuel)
			{
				fuelLevel -= fuel;
				return true;
			}
			return false;
		}

		double getTankLevel(){return (double)fuelLevel/capacity;}

		bool hasFuel(double fuel){
			if(fuelLevel >= fuel)
				return true;
			return false;
		}

		double getFuelLevel(){return this->fuelLevel;}

};

class Vehicle{

	protected:
		int wheels;
		Tank tank;
		double chilometers;

	public:
		Vehicle(int wheels, double chilometers, double tankCapacity, double fuelLevel):
		wheels(wheels), chilometers(chilometers), tank{tankCapacity, fuelLevel}{}

		virtual bool drive(double km)=0;

		double getTankLevel(){return tank.getTankLevel();}

		virtual ostream& print(ostream& os){
			os << "Class " << typeid(*this).name() << " wheels= " << wheels << ", chilometers= " << chilometers 
			<< "  tank.getCapacity()= " << tank.getCapacity() << ", tank.getFuelLevel()= " << tank.getFuelLevel();
			return os;
		}
};

class Car : public Vehicle{

	protected:
		int times;

	public:
		Car(double chilometers) : Vehicle{4, chilometers, 55, 25},times(0){}

		bool drive(double km)
	    {
	        double fuel = km * 0.075;
	        if (this->tank.hasFuel(fuel) <= 0.5)
	            fuel -= (double)((fuel * 5) / 100);
	        
	        if (tank.hasFuel(fuel))
	        {
	            tank.consume(fuel);
	            chilometers += km;
	            times += 1;
	            return true;
	        }
	        else
	        {
	            return false;
	        }
	    }

		int getTimes(){return this->times;}

		ostream& print(ostream& os){
			Vehicle::print(os);
			return os << " times= " << times;
		}
};

class Truck : public Vehicle{

	public:
		Truck(double chilometers) : Vehicle{6, chilometers, 110, 50}{}

		bool drive(double km){

			double fuel = km * 0.4;

			if(this->chilometers > 200000)
				fuel += (fuel*20)/100;

			if(this->tank.hasFuel(fuel))
			{
				tank.consume(fuel);
				this->chilometers += km;
				return true;
			}else{
				return false;
			}
		}

		ostream& print(ostream& os){
			return Vehicle::print(os);
		}
};

ostream& operator<< (ostream& os, Vehicle& obj){return obj.print(os);}

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
    for(int i=0; i<DIM; i++)
    	cout << i << ") " << *vec[i] << endl;

    cout << endl;

}