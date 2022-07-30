#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<typeinfo>

using namespace std;

template<typename T>
class Character{

		T*** power;

	protected:

		int rows;
		int columns;

	public:

		Character(int rows, int columns) : rows(rows), columns(columns){

			power = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				power[i] = new T*[columns];
				for(int j=0; j<columns; j++)
				{
					power[i][j] = new T((double)rand()/RAND_MAX);
				}
			}
		}

		void traspose(){

			int aux = rows;
			rows = columns;
			columns = aux;

			T*** temp = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				temp[i] = new T*[columns];
				for(int j=0; j<columns; j++)
					temp[i][j] = power[j][i];
			}

			power = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				power[i] = new T*[columns];
				for(int j=0; j<columns; j++)
					power[i][j] = temp[i][j];
			}
		}

		T** get_column(int index){

			T** cols = new T* [rows];
			for(int i=0; i<rows; i++)
				cols[i] = power[i][index];

			return cols;
		}

		virtual double attack() = 0;

		virtual ostream& print(ostream& os){

			os << "Class: " << typeid(*this).name() << endl << endl;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<columns; j++)
				{
					if(power[i][j])
						os << *power[i][j] << "  ";

					else
						os << " * " ;
				}
				os << endl;
			}

			return os << endl; 
		}
};

template<typename T>
class Wizard : public Character<T>{

	public: 

		Wizard(int rows, int columns) : Character<T>(rows, columns){Character<T>::traspose();}

		T attack(){

			int r = 1+rand()%12;

			if(r%2 == 0){
				Character<T>::traspose();
				return 0;
			}
		
			int columns = Character<T>::columns;
			int rows = Character<T>::rows;
			double sum = 0.0;

			T** cols = Character<T>::get_column(rand()%columns);
			for(int i=0; i<rows; i++)
			{
				if(cols[i])
					sum += *cols[i];
			}
			return (T)sum + (r%6);
 		}

		virtual ostream& print(ostream& os){
			Character<T>::print(os);
			return os << "\nAttack()= " << this->attack() << endl;
		}
};

template<typename T>
class Cleric : public Character<T>{

	public:

		Cleric(int rows, int columns) : Character<T>(rows, columns){}

		T attack(){
				
			int r = 1+rand()%6;

			if(r==1 || r==5){return 0;}

			else if(r%2 == 0)
			{
				int columns = Character<T>::columns;
				int rows = Character<T>::rows;
				double sum = 0.0;

				T** cols = Character<T>::get_column(rand()%columns);
				for(int i=0; i<rows; i++)
				{
					if(cols[i])
						sum += *cols[i];
				}
				return (T)(r + sum);
			}

			return (double)r/2;

		}

		virtual ostream& print(ostream& os){
			Character<T>::print(os);
			return os << "\nAttack()= " << this->attack() << endl;
		}
};

template<typename T>
ostream& operator<< (ostream& os, Character<T>& c){return c.print(os);}

int main(){

	const int DIM = 10;

	Character<double>* vett[DIM];
	srand(424242);

	int w = rand()%10;
	for(int i=0; i<DIM; i++)
	{
		int r = rand()%2;
		if(r==0)
			vett[i] = new Wizard<double> (3, 3);
		else
			vett[i] = new Cleric<double> (5, 5);	
	}
	
	for(int i=0; i<DIM; i++)
		cout<<"\n"<<i<<") "<<*vett[i]<<endl;

//Max e Min per i valori di attack per tutti gli oggetti della collezione
//Sum per i valori di attack per tutti gli oggetti di tipo Wizard<double>
//Avg per i valori di attack per tutti gli oggetti di tipo Cleric<double>

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
	cout << "\nMin attack(): " << min << endl;
	cout << "\nSum Wizard<double>_attack(): " << sum << endl;
	cout << "\nAvg Cleric<double>_attack(): " << (double)avg/count << endl;

	cout << endl;

}