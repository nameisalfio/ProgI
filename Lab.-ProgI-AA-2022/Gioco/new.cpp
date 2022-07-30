#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

template<typename T>
class Character{

	T*** power;

	protected:
		int rows;
		int columns;

		T** get_columns(int index){

			T** vet = new T*[rows];

			for(int i=0; i<rows; i++)
				vet[i] = power[i][index%columns];

			return vet;
		}

	public:
		Character(int rows, int columns):rows(rows), columns(columns){
			power = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				power[i] = new T*[columns];
				for(int j=0; j<columns; j++)
				{
					int a = 0;
					int b = 1;
					power[i][j] = new T((b-a)*(1.0*rand()/RAND_MAX)+a);
				}
			}
		}

		void traspose(){

			int tmp = rows;
			rows = columns;
			columns = tmp;

			T* aux[rows][columns];
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<columns; j++)
					aux[i][j] = power[j][i];
			}

			power = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				power[i] = new T*[columns];
				for(int j=0; j<columns; j++)
				{
					power[i][j] = aux[i][j];
				}
			}
		}

		virtual double attack()=0;

		virtual ostream& print(ostream& os){

			os << "Class: " << typeid(*this).name() << endl << endl;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<columns; j++)
				{
					if(power[i][j])
						os << *power[i][j] << "  ";
				}
				os << endl;
			}

			return os << endl; 
		}
};

template<typename T>
class Wizard : public Character<T>{

	public:
		Wizard(int rows, int columns) : Character<T>{rows, columns}{this->traspose();}

		double attack()override{

			int r = rand()%12 + 1;

			if(!(r % 2))
			{
				this->traspose();
				return 0;
			}

			T somma = 0.0;
			T** cols = this->get_columns(r % this->columns);
			for(int i=0; i<this->rows; i++)
			{
				if(cols[i])
					somma += *cols[i];
			}

			return (r % 6) + (T)somma;
		}

		ostream& print(ostream& os)override{
			Character<T>::print(os);
			return os << "\nAttack()= " << this->attack() << endl;
		}
};

template<typename T>
class Cleric : public Character<T>{

	public:
		Cleric(int rows, int columns) : Character<T>{rows, columns}{}

		double attack()override{

			int r = rand()%12 + 1;

			if(r == 1 || r == 5)
				return 0;

			else if(!(r % 2))
			{
				T somma = 0.0;
				T** cols = this->get_columns(rand()%this->columns);
				for(int i=0; i<this->rows; i++)
				{
					if(cols[i])
						somma += *cols[i];
				}

				return r + (T)somma;
			}
			else
				return (double)r/2;
		}

		ostream& print(ostream& os)override{
			Character<T>::print(os);
			return os << "\nAttack()= " << this->attack() << endl;
		}
};

template<typename T>
ostream& operator<< (ostream& os, Character<T>& obj){return obj.print(os);}

int main(){

	cout << endl;
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
		cout << i+1 << ") " << *vett[i] << endl;
}