#include<iostream>
#include<cstdlib>
#include<typeinfo>

using namespace std;

template<typename T>
class Character{

	T*** power;

protected:
	int rows;
	int columns;

	T** getColumns(int index){

		T** cols = new T*[rows];
		for(int i=0; i<rows; i++){
			cols[i] = power[i][index];
		}

		return cols;
	}

public:
	Character(int rows, int columns):rows(rows), columns(columns){

		power = new T**[rows];
		for(int i=0; i<rows; i++){
			power[i] = new T*[columns];
			for(int j=0; j<columns; j++)
				power[i][j] = new T(1.0*rand()/RAND_MAX);
		}
	}

	void traspose(){

		int tmp = rows;
		rows = columns;
		columns = tmp;

		T*** aux = new T**[rows];
		for(int i=0; i<rows; i++){
			aux[i] = new T*[columns];
			for(int j=0; j<columns; j++)
				aux[i][j] = power[j][i];
		}

		power = new T**[rows];
		for(int i=0; i<rows; i++){
			power[i] = new T*[columns];
			for(int j=0; j<columns; j++)
				power[i][j] = aux[i][j];
		}
	}

	virtual double attack() = 0;

	friend ostream& operator<< (ostream& os, Character<T>& c){
		os << "Class: " << typeid(c).name() << ", rows= " << c.rows << ", columns= " << c.columns << endl;
		os << "\nPower:" << endl << endl;
		for(int i=0; i<c.rows; i++){
			for(int j=0; j<c.columns; j++){
				if(c.power[i][j])
					os << *c.power[i][j] << " ";
			}
			os << endl;
		}
		return os << "------------------------------------" << endl;
	}

	bool operator >= (Character<T>& other){return attack() <= other.attack();}

};

template<typename T>
class Wizard : public Character<T>{

public:
	Wizard(int rows, int columns):Character<T>(rows, columns){Character<T>::traspose();}

	T attack(){
		int r = 1 + rand()%12;

		if(r%2 == 0){
			Character<T>::traspose();
			return 0;
		}
		T** cols = Character<T>::getColumns(rand()%Character<T>::columns);
		T sum = 0;

		for(int i=0; i<Character<T>::rows; i++){
			if(cols[i])
				sum += *cols[i];
		}
		delete[] cols;

		return (T)(sum + (r % 6));
	}
};

template<typename T>
class Cleric : public Character<T>{

public:
	Cleric(int rows, int columns) : Character<T>(rows, columns){}

	T attack(){
		int r = 1 + rand()%6;

		switch(r){

			case(1):
			case(5):
			{
				return 0;
				break;
			}

			case(2):
			case(4):
			case(6):
			{
				T** cols = Character<T>::getColumns(rand()%Character<T>::columns);
				T sum = 0;
				for(int i=0; i<Character<T>::rows; i++){
					if(cols[i])
						sum += *cols[i];
				}
				delete[] cols;

				return T(sum + r);
				break;
			}

			default:	//case(3)
				return (T)r/2;
		}
	}
};

int main(){

	const int DIM = 10;

	Character<double>* vett[DIM];
	srand(424242);

	int w = rand()%10;
	for(int i=0; i<DIM; i++)
	{
		int r = rand()%2;
		if(r==0)
			vett[i] = new Wizard<double> (2+rand()%4, 3+rand()%3);
		else
			vett[i] = new Cleric<double> (3+rand()%3, 2+rand()%4);	
	}
	
	for(int i=0; i<DIM; i++)
		cout << i+1 << ") " << *vett[i] << endl;

	double max = vett[0]->attack();
	double min = vett[0]->attack();
	
	double sum = 0.0;
	double avg = 0.0;
	int count = 0;


	for(int i=0; i<DIM; i++)
	{
		if(vett[i]->attack() > max)
			max = vett[i]->attack();

		if(vett[i]->attack() < min)
			min = vett[i]->attack();

		if(typeid(*vett[i]) == typeid(Wizard<double>))
			sum += static_cast<Wizard<double>*>(vett[i])->attack();

		if(typeid(*vett[i]) == typeid(Cleric<double>))
		{
			avg += static_cast<Cleric<double>*>(vett[i])->attack();
			count ++;
		}
	}

	cout << "\nMax attack(): " << max << endl;
	cout << "Min attack(): " << min << endl;
	cout << "Sum Wizard<double>_attack(): " << sum << endl;
	cout << "Avg Cleric<double>_attack(): " << (double)avg/count << endl;

	//Simulo una sfida tra due oggetti casuali della collezione
	cout << "\n....challange..." << endl;
	int i = rand()%(DIM-1);

	cout << "\nSfida tra vett[" << i << "] e vett[" << i+1 << "]";

	if(*vett[i] >= *vett[i+1])
	{
		cout << "\tVincitore: vett[" << i << "]\t";

		if(typeid(*vett[i]) == typeid(Wizard<double>))
			cout << "Wizard attack() --> " << static_cast<Wizard<double>*>(vett[i])->attack();

	    if(typeid(*vett[i]) == typeid(Cleric<double>))
			cout << "Cleric attack--> " << static_cast<Cleric<double>*>(vett[i])->attack();

	}else{
		
		cout << "\tVincitore: vett[" << i+1 << "]\t";

		if(typeid(*vett[i++]) == typeid(Wizard<double>))
			cout << "Wizard attack--> " << static_cast<Wizard<double>*>(vett[i++])->attack();

		if(typeid(*vett[i++]) == typeid(Cleric<double>))
			cout << "Cleric attack--> " << static_cast<Cleric<double>*>(vett[i++])->attack();
	}

	cout << endl << endl;
}