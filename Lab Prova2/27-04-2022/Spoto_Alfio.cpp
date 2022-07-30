#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<typeinfo>

using namespace std;

class Wheel{

        int value;
        int default_value;
        int num_faces;

    public:
        Wheel(int initial_value, int num_faces) : num_faces(num_faces){
            this->value = initial_value;
            this->default_value = initial_value;
        }
        void rotate (int turns){
            value = (value + turns) % num_faces;
        }
        int getValue(){
            return value;
        }
        void reset(){
            this->value = default_value;
        }
        
};


class AbstractSlotMachine {
    protected:
        Wheel **wheels;
        int num_wheels;
        int prize;
        int num_spins;
        int num_wins;
    
    public:
        AbstractSlotMachine (int num_wheels, int num_faces) : num_wheels(num_wheels) {
            prize = 0;
            num_spins = 0;
            num_wins = 0;
            wheels = new Wheel*[num_wheels];
            int a = 0;
            int b = num_faces -1;

            for(int i=0; i<num_wheels; i++)
            {
                int init = rand()%(b - a + 1) + a;
                wheels[i] = new Wheel(init, num_faces); 
            }
        }
        virtual int spin() = 0;
        int getPrize () {
            return prize;
        }   
        double getWinRate () {
            return (double)(num_wins / num_spins);
        }
        void reset(){
            for(int i=0; i<num_wheels; i++)
            {
                if(wheels[i])
                    wheels[i]->reset();
            }
        }
        virtual ostream& print(ostream& os){
            os<<"Class="<<typeid(*this).name()<<", num_wheels="<<num_wheels<<", prize="<<prize<<", num_spins="<<num_spins<<", num_wins="<<num_wins<<", win_rate="<<getWinRate();
            return os;
        }
};

class ThreeWheelsSlotMachine : public AbstractSlotMachine{

        int num_max;

    public:
        ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6){
            this->num_max = 0;
        }
        int spin(){
            num_spins++;
            int sum = 0;
            bool vincente = false;
            bool max = false;
            for(int i=0; i<num_wheels; i++)
            {
                wheels[i]->rotate(rand()% (10 - 3 + 1) + 3);
                sum += wheels[i]->getValue();
                prize += sum;
                for(int j=0; j<2; j++)
                {
                    if(wheels[j]->getValue() == wheels[j + 1]->getValue())
                    {
                        vincente = true;
                        if(wheels[j]->getValue() == 5)
                            max = true;
                    }
                }
        	}
                if(vincente)
                {
                    num_wins++;
                    int aux = prize;
                    prize = 0;
                    if(max)
                    {
                        aux *= 2;
                        num_max ++;
                    }
                    return aux;
                }
                else
                    return 0;

            }
        
        int get_NumMax(){
            return num_max;
        }
        ostream& print(ostream& os){
            AbstractSlotMachine::print(os);
            os<<", num_max()="<<num_max;
            return os;
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{


    public:
        TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}
        int spin(){
            num_spins++;
            int sum = 0;
            int r = rand()% (10 - 3 + 1) + 3;
            bool vincente  = false;

            for(int i=0; i<num_wheels; i++)
            {
                int w;

                if(i != 0)
                    w = wheels[i--]->getValue();
                else
                    w = 0;
                
                r += round(w / 3);
                wheels[i]->rotate(rand()% (10 - 3 + 1) + 3);
                sum += wheels[i]->getValue();
                prize += sum;

                for(int j=0; j<4; j++)
                {
                    for(int z=j+1; z<5; z++)
                    {
                        if(wheels[j]->getValue() != wheels[z]->getValue())
                            vincente = true;
                    }
                    
                }
        	
                if(vincente)
                {
                    num_wins++;
                    int aux = prize;
                    prize = 0;
                    
                    return aux;
                }
                
                return 0;
            }
        }

        ostream& print(ostream& os){
            return AbstractSlotMachine::print(os);
        }
};

ostream& operator<< (ostream& os, AbstractSlotMachine& a){
    return a.print(os);
}

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

    for(int i=0; i<DIM; i++)
        cout<<i +1 <<")"<<*vec[i]<<endl;

    double max = vec[0]->getWinRate();
    double avg = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++)
    {
        if(vec[i]->getWinRate() > max)
            max = vec[0]->getWinRate();
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
        {
            avg += static_cast<ThreeWheelsSlotMachine*>(vec[i])->get_NumMax();
            count++;
        }
    }
    cout<<"\nMax_getWinRate()="<<max<<endl;
    cout<<"\nAvg_getNumMax()="<<avg/count<<endl;

    cout << endl;
}