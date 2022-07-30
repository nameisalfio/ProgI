#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
using namespace std;

class AbstractRandomVec{
	
	protected:
		int* vec;
		int num;
	
	public:
		AbstractRandomVec(int n, int min, int max):num(n){
			vec = new int [num];
			for(int i=0; i<num; i++){
				vec[i]=rand()%(max-min+1)+min;
			}
		}
		virtual int count() = 0;
		int* get(int i)const{
			if(vec[i])
				return &vec[i];
			else
				return nullptr;
		}
		int numel(){
			return num;
		}
		float mean(){
			float sum = 0.0;
			for(int i=0; i<num; i++){
				sum+=vec[i];
			}
			return sum/(double)num;
		}
		virtual ostream& print(ostream& os){
			os<<"Class="<<typeid(*this).name()<<", ";
			return os;
		}
		virtual ostream& print2(ostream& os){
			os<<"vec=[";
			for(int i=0; i<num; i++)
				os<<vec[i]<<" ";
			os<<"]";
			return os;
		}
	
};

class TernaryVec : public AbstractRandomVec{
	
	public:
		TernaryVec(int n):AbstractRandomVec(n, 0, 2){}
		int count()override{
			int count=0;
			for(int i=0; i<numel(); i++){
				if(vec[i] != 0)
					count++;
			}
			return count;
		}
		virtual ostream& print(ostream& os)override{
			AbstractRandomVec::print(os);
			os<<"num="<<num<<", ";
			AbstractRandomVec::print2(os);
			return os;
		}
};

class MultVec : public AbstractRandomVec{
	
	double midpoint;
	
	public:
		MultVec(int n, int min, int max, int mul):AbstractRandomVec(n, min, max){
			int r = rand()%(max-min+1)+min;
			for(int i=0; i<numel(); i++){
				vec[i] = r * mul;
			}
			double sum = min + max;
			midpoint = sum/2;
		}
		int count()override{
			int count = 0;
			for(int i=0; i<numel(); i++){
				if(vec[i] > mean())
					count++;
			}
			return count;
		}
		int countEven(){
			int count = 0;
			for(int i=0; i<numel(); i++){
				if(vec[i]%2 == 0)
					count++;
			}
			return count;
		}
		virtual ostream& print(ostream& os)override{
			AbstractRandomVec::print(os);
			os<<"num="<<num<<", ";
			AbstractRandomVec::print2(os);
			os<<", midpoint="<<midpoint;
			return os;
		}
};

ostream& operator<< (ostream& os, AbstractRandomVec& a){
	return a.print(os);
}

int main(){
	
	const int DIM = 50;
	srand(424242);
	AbstractRandomVec* vett[DIM];
	for(int i=0; i<DIM; i++){
		int n=5+rand()%5;
		int m=5+rand()%5;
		int min=rand()%10+5;
		int max=min + rand()%20;
		
		switch(rand()%2){
			case 0:
				vett[i] = new TernaryVec(n);
				break;
			case 1:
				vett[i] = new MultVec(n, min, max, m);
		}
	}
	
	cout<<"\nPunto 1: "<<endl;
	for(int i=0; i<DIM; i++)
		cout<<i<<")"<<*vett[i]<<endl;
		
    cout<<"\nPunto 2: "<<endl;
    int max = vett[0]->count();
	for(int i = 0; i<DIM; i++)
		if(vett[i]->count() > max) max = vett[i]->count();	
	cout<<"Max: "<<max<<endl;
	
	cout<<"\nPunto 3: "<<endl;
	double sum = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(MultVec)){
			sum += static_cast<MultVec*>(vett[i])->countEven();
			count++;
		}
	}
	cout<<"Avg : "<<sum/count<<endl;
}