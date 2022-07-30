//Frame: https://pastebin.com/MXN4kwkx
//Output: https://pastebin.com/mZBCf0s5
//Compiler: https://www.onlinegdb.com/online_c++_compiler

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<typeinfo>
#include<math.h>

using namespace std;

class Wheel{

    int value;
    int default_value;
    int num_faces;

    public:

        Wheel(int initial_value, int num_faces):num_faces(num_faces){
            this->value = initial_value;
            this->default_value = initial_value;
        }

        void rotate(int turns){value = (value + turns) % num_faces;} 

        int getValue(){return this->value;}

        void reset(){value = default_value;}

};

class AbstractSlotMachine{

    protected:

        Wheel** wheels;
        int num_wheels; //numero ruote
        int prize;
        int num_spins;
        int num_wins;
    
    public:

        AbstractSlotMachine(int num_wheels, int num_faces):num_wheels(num_wheels){
            this->prize = 0;
            this->num_spins = 0;
            this->num_wins = 0;

            wheels = new Wheel*[num_wheels];
            for(int i=0; i<num_wheels; i++)
            {
                wheels[i] = new Wheel(rand() % num_faces, num_faces);
                //Wheel
                // 1. initial value
                // 2. num faces
            }
        }

        virtual int spin() = 0;

        int getPrize(){return this->prize;}

        double getWinRate(){return(double)num_wins/num_spins;}

        void reset(){
            for(int i=0; i<num_wheels; i++)
                wheels[i]->reset();
        }

        virtual ostream& print (ostream& os){

            os << "Class: " << typeid(*this).name() << ", num_wheels= " << num_wheels;
            os << ", prize= " << prize << ", num_spins= " << num_spins << ", num_wins= " << num_wins;
            os << ", winrate= " << getWinRate();

            return os;
        }
};

class ThreeWheelsSlotMachine : public AbstractSlotMachine{

    int num_max;

    public:

        //AbstractSlotMachine
        // 1.num_wheels
        // 2.num_faces
        ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6), num_max(0){}

        int spin(){

            num_spins++;
            int vals[num_wheels];

            for(int i=0; i<num_wheels; i++)
            {
                wheels[i]->rotate(3+rand()%8);
                vals[i] = wheels[i]->getValue();
                prize += vals[i];
            }

            bool winning = true;

            for(int i=0; i<num_wheels; i++)
            {
                for(int j=i+1; j<num_wheels; j++)
                {
                    if(vals[i] != vals[j])
                        winning = false;
                }
            }

            if(winning)
            {
                num_wins++;
                
                if(vals[0] == 5)
                {
                    num_max ++;
                    prize *= 2;
                }

                int tmp = prize;
                prize = 0;

                return tmp;
            }
            else
                return 0;

        }

        int getNumMax(){return this->num_max;}

        ostream& print(ostream& os){
            AbstractSlotMachine::print(os);
            return os << ", num_max = " << getNumMax();
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{

    public:
    
        //AbstractSlotMachine
        // 1.num_wheels
        // 2.num_faces
        TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}

        int spin(){
            
            num_spins ++;

            int vals[num_wheels];
            int prev = 0;

            for(int i=0; i<num_wheels; i++)
            {
                int num_turns = (3+rand()%8) + round(prev/3);
                prev = num_turns;
                
                wheels[i]->rotate( num_turns );
    
                vals[i] = wheels[i]->getValue();
                prize += vals[i];
            }

            bool duplicate = false;

            for(int i=0; i<num_wheels; i++)
            {
                for(int j=i+1; j<num_wheels; j++)
                {
                    if(vals[i] == vals[j])
                        duplicate = true;
                }
            }

            if(!duplicate) //tiro vincente
            {
                num_wins ++;
                int tmp = prize;
                prize = 0;

                return tmp;
            }
            else //tiro non vincente
                return 0;

        }

        ostream& print(ostream& os){
            AbstractSlotMachine::print(os);
            return os;
        }
};

ostream& operator<< (ostream& os, AbstractSlotMachine& a){return a.print(os);}

int main(){

    srand(424242);
    const int DIM = 10;

    AbstractSlotMachine* vec [DIM];
    
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

    double max = vec[0]->getWinRate();
    double avg = 0.0;
    int count = 0;

    for(int i=0; i<DIM; i++)
    {
        cout << i+1 << ") " << *vec[i] << endl;

        if(vec[i]->getWinRate() > max)
            max = vec[i]->getWinRate();
        
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
        {
            avg += static_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
            count ++;
        }
    }
    
    cout << "\nMax di getWinRate() = " << max << endl;
    cout << "\nMedia di getNumMax() = " << (double) avg/count << endl;
    cout << endl;
}