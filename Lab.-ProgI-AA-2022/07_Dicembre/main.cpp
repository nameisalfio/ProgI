#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <typeinfo>

using namespace std;

class Roller
{

	int value;
	int default_value;
	int num_faces;

public:

	Roller(int initial_value, int num_faces) : num_faces(num_faces)
	{
		value = initial_value;
		default_value = initial_value;
	}

	void roll(int turns)
	{
		value = (value + turns)%num_faces;
	}

	int getValue()
	{
		return this->value;
	}

	void reset()
	{
		this->value = default_value;
	}
};

class AbstractBandit
{

protected:
	Roller** rollers;
	int num_rollers;
	int coins;
	int num_times;
	int num_wins;

public:
	AbstractBandit(int num_rollers, int num_faces) : coins(0), num_times(0), num_wins(0), num_rollers(num_rollers)
	{
		rollers = new Roller*[num_rollers];
		for(int i=0; i<num_rollers; i++)
			rollers[i] = new Roller(rand()%num_faces, num_faces);
	}

	virtual int spin() = 0;

	int getCoins()
	{
		return this->coins;
	}

	double getWinRate()
	{
		return (double)num_wins/num_times;
	}

	void reset()
	{
		for(int i=0; i<num_rollers; i++)
			rollers[i]->reset();
	}

	virtual ostream& print(ostream& os){
		os << "Class: " << typeid(*this).name() << ", num_rollers= " << num_rollers
		<< ",coins= " << coins << ", num_times= " << num_times << ", num_wins= " 
		<< num_wins << ", winRate= " << getWinRate();

		return os;
	}
};

class ThreeArmedBandit : public AbstractBandit
{

	int max;

public:

	ThreeArmedBandit() : AbstractBandit(3, 5), max(0){}

	int spin()
	{
		num_times++;

		int vals[num_rollers];
		int sum = 0;

		for(int i=0; i<num_rollers; i++)
		{
			rollers[i]->roll(rand()%10 + 3);
			sum += rollers[i]->getValue();
			vals[i] = rollers[i]->getValue();
			coins += sum;
		}

		bool vincente = true;

		for(int i=0; i<num_rollers; i++)
		{
			for(int j=i+1; j<num_rollers; j++)
			{
				if(vals[i] != vals[j])
					vincente = false;
			}
		}

		if(sum > max)
			max = sum;

		if(vincente)
		{
			num_wins++;
			int tmp = coins;
			coins = 0;
			int sum = 0;

			return tmp;
		}
		return 0;	
	}

	int getMax()
	{
		return this->max;
	}

	ostream& print(ostream& os)
	{
		AbstractBandit::print(os);
		return os << ", max= " << max;
	}

};

class FiveArmedBandit : public AbstractBandit
{

public:

	FiveArmedBandit() : AbstractBandit(5, 10){}

	int spin()
	{
		num_times++;

		int vals[num_rollers];

		for(int i=0; i<num_rollers; i++)
		{
			rollers[i]->roll(rand()%4 + 3);
			vals[i] = rollers[i]->getValue();
			coins += vals[i];
		}

		bool duplicate = false;

		for(int i=0; i<num_rollers; i++)
		{
			for(int j=i+1; j<num_rollers; j++)
			{
				if(vals[i] == vals[j])
					duplicate = true;
			}
		}

		if(!duplicate)
		{
			num_wins++;
			int tmp = coins;
			coins = 0;

			return tmp;
		}
		else
			return 0;
	}
};

ostream& operator<< (ostream& os, AbstractBandit& obj){return obj.print(os);}

int main(){

	srand(424242);
	
	const int DIM = 10;

	AbstractBandit* vec[DIM];

	for(int i=0; i<DIM; i++) {
	    if(rand()%2){
	        vec[i] = new ThreeArmedBandit();
	    } else {
	        vec[i] = new FiveArmedBandit();
	    }
	}
	 
	for(int i=0; i<DIM*100; i++) {
	     vec[rand()%DIM]->spin();
	     if(rand()%5==0)
	        vec[rand()%DIM]->reset();
	}

	cout << endl;

	//Punto 1
	for(int i=0; i<DIM; i++)
		cout << i << ") " << *vec[i] << endl;

	//Punto 2
    double min = vec[0]->getWinRate();
    for(int i=0; i<DIM; i++)
	{
		if(vec[i]->getWinRate() < min)
			min = vec[i]->getWinRate();
	}
	cout << "\nMin: " << min << endl;

	//Punto 3
	double avg = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vec[i]) == typeid(ThreeArmedBandit))
		{
			avg += static_cast<ThreeArmedBandit*>(vec[i])->getMax();
			count ++;
		}
	}
	cout << "\nAvg: " << (double)avg/count << endl;
}