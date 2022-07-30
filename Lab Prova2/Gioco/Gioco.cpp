/*Dopo aver seguito l'UML, bisogna almeno creare l'overloading dell'operatore <<, che stampa il tipo di classe,
  la matrice power e il valore di ritorno della funzione attack. Trovate il metodo più elegante possibile per 
  stampare in maniera leggibile.
  Infine create un main che mostri che siete in grado di creare 10 personaggi casuali e di saper usare su di essi
  L'overloading dell'operatore.*/
  
#include<iostream>
#include<string>
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
		Character(int rows, int columns){
			this->rows = rows;
			this->columns = columns;
			
			power = new T**[rows];
			for(int i=0; i<rows; i++)
			{
				power[i] = new T*[columns]; 
				for(int j=0; j<columns; j++)
				{
					power[i][j] = new T;
					*power[i][j] = (double)rand()/RAND_MAX;  //Inserire in una variabile double
				}
			}
		}
		void traspose(){
			int aux = rows;
			rows = columns;
			columns = aux;
			
			T temp[rows][columns];
    		for(int i=0; i<rows; i++)
    		{
        		for(int j=0; j<columns; j++)
        		{
					if(power[j][i])
           				temp[i][j] = *power[j][i];
        		}
    		}

			power = new T **[rows];
    		for(int i=0; i<rows; i++)
    		{
        		power[i] = new T*[columns];
       			for(int j=0; j<columns; j++)
        		{
            		power[i][j] = new T(temp[i][j]);
        		}
   			}
		}
		virtual double attack() = 0;
		virtual ostream& print(ostream& os){
			os<<"Class="<<typeid(*this).name()<<", Power: "<<endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<columns; j++)
				{
					if(power[i][j])
						os<<"\t"<<*power[i][j]<<" ";
					else
						os<<" * ";	
				}
				os<<endl;
			}
			os<<endl;
			return os;
		}
		bool operator>=(Character<T>* c){
			return (*this->attack() >= c.attack());
		}
		
	protected:
		T** getColumn(int index){
			T** cols = new T*[rows];  
			for(int i=0; i<rows; i++)
				cols[i] = power[i][index];   
			return cols;
		}
};

template<typename T>
class Wizard : public Character<T>{
	
	public:
		Wizard(int rows, int columns):Character<T>(rows, columns){
			Character<T>::traspose();
		}
		
		T attack()override{
			int r = (rand()%(12))+ 1;
			if(r % 2 == 0)
			{
				Character<T>::traspose();
				return 0;
			}
			
			int index = r % Character<T>::columns;
			while(index % 2 == 0){
				index = rand() % Character<T>::columns;
			}
			T** col = Character<T>::getColumn(index);
			double sum = 0.0;
			for(int i=0; i<Character<T>::rows; i++)
			{
				if(col[i])
					sum += *col[i];
			}
			return sum + index;
		}
		
		ostream& print(ostream& os)override{
			Character<T>::print(os);

			os<<"Attack="<<attack();
			return os;
		}
};

template<typename T>
class Cleric : public Character<T>{
	
	public:
		Cleric(int rows, int columns):Character<T>(rows, columns){}
		T attack()override{
			int r = 1+rand() % 6;
			if(r==1 || r==5)
			{
				return 0;
			}else if(r%2 == 0){
				int index = r % Character<T>::rows;
				T** col = Character<T>::getColumn(index);
				double sum = 0.0;
				for(int i=0; i<Character<T>::rows; i++)
				{
					if(col[i])
						sum += *col[i];
				}
				return (double)sum + r;
			}else
				return (double)r/2;
		}
		ostream& print(ostream& os)override{
			Character<T>::print(os);
		
			os<<"Attack="<<attack();
			return os;
		}
		
};

template<typename T>
ostream& operator<< (ostream& os, Character<T>& c){
	return c.print(os);
}

int main(){
	
	const int DIM = 10;
	Character<double>* vett[DIM];
	srand(time(NULL));
	int w = rand()%10;
	for(int i=0; i<DIM; i++)
	{
		int r = rand()%2;
		if(r==0)
			vett[i] = new Wizard<double> (4, 3);
		else
			vett[i] = new Cleric<double> (4, 5);	
	}
	
	for(int i=0; i<DIM; i++)
		cout<<"\n"<<i<<") "<<*vett[i]<<endl;

//Max e Min per i valori di attack per tutti gli oggetti della collezione
//Sum per i valori di attack per tutti gli oggetti di tipo Wizard<double>
//Avg per i valori di attack per tutti gli oggetti di tipo Cleric<double>
	double sumc = 0.0;
	double sumw = 0.0;
	int cw = 0;
	int c = 0;
	double max = vett[0]->attack();

	for(int i=0; i<DIM; i++)
	{
		if(vett[i]->attack() > max)
			max = vett[i]->attack();

		if(typeid(*vett[i]) == typeid(Wizard<double>))
			sumw += static_cast<Wizard<double>*>(vett[i])->attack();

		if(typeid(*vett[i]) == typeid(Cleric<double>))
		{
			sumc += static_cast<Cleric<double>*>(vett[i])->attack();
			c++;
		}
	}
	cout<<"Max: "<<max<<endl;
	cout<<"Sum: "<<sumw<<endl;
	cout<<"Avg: "<<(double)sumc/c<<endl;

//Simulo una sfida tra due oggetti casuali della collezione
	cout<<"\n....CHALLENGE..."<<endl;
	int i = rand()%(DIM-1);
	
	if(vett[i] >= vett[i++]){
		
		cout<<"vett["<<i<<"] vince"<<endl;
		if(typeid(*vett[i]) == typeid(Wizard<double>))
			cout<<"Wizard attack-->"<<static_cast<Wizard<double>*>(vett[i])->attack();
		else if(typeid(*vett[i]) == typeid(Cleric<double>))
			cout<<"Cleric attack-->"<<static_cast<Cleric<double>*>(vett[i])->attack();

	}else{
		
		cout<<"vett["<<i++<<"] vince"<<endl;
		if(typeid(*vett[i++]) == typeid(Wizard<double>))
			cout<<"Wizard attack-->"<<static_cast<Wizard<double>*>(vett[i++])->attack();
		else if(typeid(*vett[i++]) == typeid(Cleric<double>))
			cout<<"Cleric attack-->"<<static_cast<Cleric<double>*>(vett[i++])->attack();
	
	}
	
}