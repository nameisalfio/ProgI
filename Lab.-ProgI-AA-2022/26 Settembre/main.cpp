#include<iostream>
#include<typeinfo>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

class AbstractArray{
    float* array;
    short num;
public:
    AbstractArray(short n, float midpoint, float width):num(n){
        array = new float[num];
        for(int i=0; i<num; i++)
        {
            float a = midpoint-width;
            float b = midpoint+width;
            array[i] = (b-a)*(1.0*rand()/RAND_MAX)+a;
        }
    } 
    virtual short count()=0;
    float* getPtr(short i){
        if(i < num)
            return &array[i];
        return nullptr;
    }
    short numel(){return num;}

    virtual ostream& print(ostream& os){
        os << "Class: " << typeid(*this).name() << ", num= " << num << ", vec=[ ";
        for(int i=0; i<num; i++)
            os << array[i] << " ";
        return os << "], ";
    }
};

template<typename T>
class ProbArray : public AbstractArray{
public:
    ProbArray(short n) : AbstractArray(n, 0.5, 0.5){}   // midpoint-width = 1/2 - 1/2 = 0  _OK
                                                        // midpoint+width = 1/2 + 1/2 = 1  _OK
    short count(){
        int n=0;
        for(int i=0; i<numel(); i++)
        {
            if(getPtr(i) && *getPtr(i) > 0.5)
                n++;
        }
        return n;
    }
    T mean(){
        if(typeid(T) == typeid(int))
            return count();
        else
        {
            float avg = 0.0;
            for(int i=0; i<numel(); i++)
            {
                if(getPtr(i))
                    avg += *getPtr(i);
            }
            return (float)avg/numel();
        }
    }

    //  0) Class=9ProbArrayIdE, num=6, vec=[-0.0625832 0.293759 -0.269544 -0.433852 -0.299541 -0.288763 ], count()=0, T=d, mean()=-0.176754
    ostream& print(ostream& os){
        AbstractArray::print(os);
        os << ", count()= " << count() << ", T= " << typeid(T).name() << ", mean()= " << mean();
        return os;
    }
};

class CustomArray : public AbstractArray{
    float midpoint;
public:
    CustomArray(short n) : AbstractArray(n, 5, 5)       // midpoint-width = 5 - 5 = 0   _OK
    {                                                   // midpoint+width = 5 + 5 = 10  _OK
        for(int i=0; i<numel(); i++)
        {
            if(getPtr(i))
                midpoint += *getPtr(i);
        }
        midpoint /= numel();
    }     
    short count(){
        int n=0;
        for(int i=0; i<numel(); i++)
        {
            if(getPtr(i) && *getPtr(i) < midpoint)
                n++;
        }
        return n;
    }           

    //3) Class=11CustomArray, num=7, vec=[-2.98983 2.51289 1.40391 -2.52 -3.11294 -0.658497 -0.215445 ], count()=3, midpoint=-0.797132
    ostream& print(ostream& os){
        AbstractArray::print(os);
        os << "count()=  " << count() << ", midpoint= " << midpoint;
        return os;
    }
};

ostream& operator<< (ostream& os, AbstractArray& ref){return ref.print(os);}

int main(){

    srand(424242);

    const int DIM = 10;
    AbstractArray* vett[DIM];
 
    for(int i=0; i<DIM; i++) {
        int n=5+rand()%5;
 
        switch(rand()%3) {
            case 0: 
                vett[i]= new ProbArray<int>(n);
                break;
            case 1:
                vett[i]= new ProbArray<double>(n);
                break;
            case 2:
                vett[i]= new CustomArray(n);
        }
    }

    //Punto 1:
    for(int i=0; i<DIM; i++)
        cout << i << ") " << *vett[i] << endl;

    //Punto 2:
    short max = vett[0]->count();
    for(int i=0; i<DIM; i++)
    {
        if(vett[i]->count() > max)
            max = vett[i]->count();
    }
    cout << "\nmax count(): " << max << endl;

    //Punto 3:
    max = 0;
    short idx;
    for(int i=0; i<DIM; i++)
    {
        if(typeid(*vett[i]) == typeid(ProbArray<double>))
        {
            if(static_cast<ProbArray<double>*>(vett[i])->mean() > max)
                idx = i;
        }
    }
    cout << "\nElemento di tipo ProbArray<double> con massimo valore di mean(): " << *vett[idx] << endl;
}