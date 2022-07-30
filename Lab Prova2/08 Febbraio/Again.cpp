#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<typeinfo>

using namespace std;

class AbstractRandomVec{

    protected:
        int* vec;
        int num;

    public:
        AbstractRandomVec(int n, int min, int max) : num(n){
            vec = new int [num];
            for(int i=0; i<num; i++)
                vec[i] = rand() % (max - min + 1)+min;
        }
        virtual int count() = 0;
        int* get (int i){
            if(vec[i])
            {
                int* ptr = &vec[i];
                return ptr;
            }
            else 
                return nullptr;
        }
        int numel(){
            int count = 0;
            for(int i=0; i<num; i++)
            {
                if(vec[i])
                    count++;
            }
            return count;
        }
        float mean(){
            float sum = 0.f;
            int count = 0;
            for(int i=0; i<num; i++)
            {
                if(vec[i])
                {
                    sum += vec[i];
                    count++;
                }
            }
            return (float)sum/count;
        }

        virtual ostream& print (ostream& os){
            os<<"Class="<<typeid(*this).name()<<", num= "<<num<<", vec=[";
            for(int i=0; i<num; i++)
                os<<vec[i]<<" ";
            os<<"]";
            return os;
        }
};

class TernaryVec : public AbstractRandomVec{

    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0, 2){}
        int count(){
            int count = 0;
            for(int i=0; i<num; i++)
            {
                if(vec[i])
                    count++;
            }
            return count;
        }
        ostream& print (ostream& os){
            AbstractRandomVec::print(os);
            return os;
        }
};

class MultVec : public AbstractRandomVec{

        double midpoint;

    public:
        MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max){
            midpoint = (double)(max + min)/2;
            int r = rand()% (max - min + 1) + min;
            for(int i=0; i<num; i++)
            {
                while(r*mul >= min && r*mul <= max)
                {
                    vec[i] = r*mul;
                    r = rand()% (max - min + 1) + min;
                }
            }
        }
        int count(){
            int count = 0;
            for(int i=0; i<num; i++)
            {
                if(vec[i] > midpoint)
                    count++;
            }
        }
        int countEven(){
            int count = 0;
            for(int i=0; i<num; i++)
            {
                if(vec[i] % 2 == 0)
                    count++;
            }
            return count;
        }
        ostream& print (ostream& os){
            AbstractRandomVec::print(os);
            os<<", midpoint="<<midpoint;
            return os;
        }
};


ostream& operator<< (ostream& os, AbstractRandomVec& a){
    return a.print(os);
}


int main(){

    srand(424242);
	const int DIM = 10;
	AbstractRandomVec* vett[DIM];
	for(int i=0; i<DIM; i++) {
		int n=5+rand()%5;
		int m=5+rand()%5;
		int min = rand()%10 + 5;
		int max = min + rand()%20;
	
		switch(rand()%2) {
			case 0: 
				vett[i]= new TernaryVec(n);
				break;
			case 1:
				vett[i]= new MultVec(n, min, max, m);
		}
	}

    for(int i=0; i<DIM; i++)
        cout<<i<<") "<<*vett[i]<<endl;
    cout<<endl;
//-----------------------------------------------------------------------
    int max = vett[0]->count();
    for(int i=0; i<DIM; i++)
    {
        if(vett[i]->count() > max)
            max = vett[i]-> count();
    }
    cout<<"Max= "<<max<<endl;
    cout<<endl;
//-----------------------------------------------------------------------
    double sum = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++)
    {
        if(typeid(*vett[i]) == typeid(MultVec))
        {
            sum += static_cast<MultVec*>(vett[i])->countEven();
            count++;
        }
    }
    cout<<"Avg="<<(double)sum/count<<endl;
}