#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>

using namespace std;

class Collar{
    char color;
public:
    Collar(char c):color(c){}
    char getColor(){return color;}
};

class RedCollar : public Collar{
public:
    RedCollar():Collar('r'){}
};

class BlueCollar : public Collar{
public:
    BlueCollar():Collar('b'){}
};

class Animal{
    int legs;   //numero di gambe
    int life_expectancy;    //aspettativa di vita
    double meters;  //metri percorsi
    Collar* collar; //collare
protected:
    double base_speed;  //velocità di base
    int age;    //età
public:
    Animal(int legs, int life_expectancy, double base_speed):legs(legs), life_expectancy(life_expectancy), base_speed(base_speed){
        age = 0;
        meters = 0.0;

        //In base alla modalità di generazione del numero random si possono ottenere gli stessi valori di "meters"
        // oppure gli stessi valori per  "type of colllar". Negando la condizione nell'if si riescono a generare istanze
        // aventi valori di "meters" uguali a quelli forniti nell'output indicativo ma con differenti valori di "type of collar".
        
        if(rand()%2 == 0){ 
            collar = new RedCollar;
        }else{
            collar = new BlueCollar;
        }
    }
    void happyBirthday(){this->age++;}
    int getAge(){return this->age;}
    double getMeters(){return this->meters;}
    void run(double time){
        
        double distance = base_speed * time;

        if(age > (double)(life_expectancy)/2){
            distance -= double(distance*20)/100;
        }
        if(legs >= 4){
            distance += (double)(distance*10)/100;
        }

        if(collar->getColor() == 'b'){
            distance -= (double)(distance*5)/100;
        }else {
            distance += (double)(distance*5)/100;
        }

        meters += distance;
    }
    virtual void special() = 0;
    virtual ostream& print(ostream& os){
        os << "Class=" << typeid(*this).name() << "\tlegs=" << legs << ", age=" << age << ", life_expectancy=" << life_expectancy;
        os << ", base_speed=" << base_speed << ", meters=" << meters << ", type of collar=" << collar->getColor();
        return os;
    }
};

class Zerusa : public Animal{
public:
    Zerusa():Animal(3, 15, 12){}
    void special(){this->age --;}
};

class Dakure : public Animal{
public:
    Dakure():Animal(5, 10, 15){}
    void special(){
        this->base_speed += (rand()%7)-3;
    }
};

ostream& operator<< (ostream& os, Animal& ref){return ref.print(os);}

int main(){

    srand(424242);

    const int DIM = 10;
    Animal* vec[DIM];
 
    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new Zerusa();
        } else {
            vec[i] = new Dakure();
        }
    }
 
    for(int i=0; i<DIM*5; i++) {
        int x = rand() % DIM;
        vec[x]->happyBirthday();
 
        double meters = double(rand())/RAND_MAX*10;
 
        vec[x]->run(meters);
        if(rand()%5==0)
            vec[x]->special();

    }

    //Punto 1:
    for(int i=0; i<DIM; i++){
        cout << i << *vec[i] << endl;
    }

    //Punto 2:
    int min = 0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getAge() < vec[min]->getAge())
            min = i;
    }
    cout << "\nAnimale piu' giovane: " << *vec[min] << endl;

    //Punto 3:
    int max = 0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getMeters() > vec[max]->getMeters())
            max = i;
    }
    cout << "\nAnimale piu' lontano: " << *vec[max] << endl;
}
