#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<cmath>
#include<typeinfo>

using namespace std;

template<typename T>
class Character{

        T*** power;
    
    protected:
        int rows;
        int columns;

    public:
        Character<T>(int rows, int columns):rows(rows), columns(columns){
            power = new T**[rows];
            for(int i=0; i<rows; i++)
            {
                power[i] = new T*[columns];
                for(int j=0; j<columns; j++)
                {
                    power [i][j] = new T((double)rand()/RAND_MAX);
                }
            }
        }
        void traspose(){

            int temp = rows;
            rows = columns;
            columns = temp;

            T* aux[rows][columns];
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<columns; j++)
                {   
                    aux[i][j] = new T;
                    if(power[j][i])
                        *aux[i][j] = *power[j][i];
                }
            }

            power = new T**[rows];
            for(int i=0; i<rows; i++)
            {
                power[i] = new T*[columns];
                for(int j=0; j<columns; j++)
                {
                    if(aux[i][j])
                        power [i][j] = new T (*aux[i][j]);
                }
            } 
        }
    virtual double attack() = 0;
    void put(){
        cout<<"Matrice: "<<endl;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                if(power[i][j])
                    cout<<*power[i][j]<<" ";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    virtual ostream& print(ostream& os){
        os<<"Class="<<typeid(*this).name()<<", \nPower: "<<endl;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++){
				if(power[i][j])
					os<<"\t"<<*power[i][j]<<"\t";
				else
					os<<" \t";
			}
            cout<<endl;
        }
        cout<<endl;
        return os;
    }
   protected:
        T** get_columns(int index) {
            T** aux = new T*[rows];
            for(int i=0; i<rows; i++)
            {
                if(power [i][index])
                    aux[i] = power[i][index];
            }
            return aux;
        }

};

template<typename T>
class Wizard : public Character<T>{

    public:
        Wizard(int rows, int columns) : Character<T>(rows, columns){
            Character<T>::traspose();
        }
        
        T attack(){
            
            int dado = 1 + rand()%12;
            if(dado % 2 == 0)
            {
                Character<T>::traspose();
                return 0;
            }
            int num = rand() % Character<T>::columns;
            T** aux = Character<T>::get_columns(num);
            T sum = 0;
            for(int i=0; i<Character<T>::rows; i++)
                sum += *aux[i];
            
            return sum + (dado % 6);
        }
        ostream& print(ostream& os){
            Character<T>::print(os);
            os<<"Attack()="<<attack();
            return os;
        }
};

template<typename T>
class Cleric : public Character<T>{

    public:
        Cleric(int rows, int columns) : Character<T>(rows, columns){}
        
        T attack(){
            
            int dado = 1 + rand()%6;
            if(dado == 1 || dado == 5)
            {
                return 0;
            }
            else if(dado % 2 == 0)
            {
                int num = rand()% Character<T>::columns;
                T sum = 0;
                T** aux = Character<T>::get_columns(num);
                for(int i=0; i<Character<T>::rows; i++)
                    sum += *aux[i];
                return sum + dado;
            }
            else{
                return (double)dado/2;
            }
        }
        ostream& print(ostream& os){
            Character<T>::print(os);
            os<<"Attack()="<<attack();
            return os;
        }

};

template<typename T>
ostream& operator<< (ostream& os, Character<T>& c){
    return c.print(os);
}


int main() {

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
    
    double max = vett[0]->attack();
    double min = vett[0]->attack();
    double sum = 0;
    double avg = 0.0;
    for(int i=0; i<DIM; i++)
    {
        if(vett[i]->attack() > max)
            max = vett[i]->attack();

        if(vett[i]->attack() < min)
            min = vett[i]->attack();

        if(typeid(*vett[i]) == typeid(Wizard<double>))
            sum += static_cast<Wizard<double>*>(vett[i])->attack();

        if(typeid(*vett[i]) == typeid(Cleric<double>))
            avg += static_cast<Cleric<double>*>(vett[i])->attack();
    }

    cout<<"Max = "<<max<<"\tMin = "<<min<<endl;
    cout<<"Sum_wizard() = "<<sum<<"\tAvg_Cleric() = "<<avg/DIM<<endl<<endl;

}

