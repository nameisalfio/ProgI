#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>
using namespace std;

template <typename T>
class AbstractVec{
	
	T** data;
	
	protected:
		int max_size;
		int read_index;
		int write_index;
	
	public:
		AbstractVec(int max_size):read_index(0), write_index(0){
			this->max_size = max_size;
			data = new T*[max_size];
			for(int i=0; i<max_size; i++){
				data[i] = nullptr;
			}
		}
		virtual T* next() = 0;
		virtual bool insert (T x) = 0;
		int len (){
			int count = 0;
			for(int i=0; i<max_size; i++){
				if(data[i] != nullptr)
					count++;
			}
			return count;
		}
		void shuffle(){
			for(int i=0; i<max_size; i++){
				int j = rand() % max_size;
				if(data[i] != nullptr){
					do {
						j = rand() % max_size;
						data[i] = data[j];
					}while(data[j] == nullptr);
				}
			}
		}
		virtual ostream& print(ostream& os){
			os<<typeid(*this).name()<<", max_size="<<max_size<<", vec=[";
			for(int i=0; i<max_size; i++)
				os<<*data[i]<<" ";
			os<<" ], len()="<<len();
			return os;
		}

	protected:
		T* get (int index){
			return data[index];
		}
		bool exists (int index){
			if(data[index])
				return true;
			else
				return false;
		}
		void set(T x, int i){
			*data[i] = x;
		}

};

template <typename T> 
class PlainVec : public AbstractVec<T>{
	
	public:
		PlainVec(int max_size):AbstractVec<T>(max_size){
		}
		virtual T* next()override{
		if(*AbstractVec<T>::get(AbstractVec<T>::read_index) <= AbstractVec<T>::max_size){
				AbstractVec<T>::read_index ++;
				return AbstractVec<T>::get(AbstractVec<T>::read_index);
			}else{
				return nullptr;
			}
		}
		virtual bool insert (T x)override{
			if(*AbstractVec<T>::get(AbstractVec<T>::write_index) <= AbstractVec<T>::max_size){
				*AbstractVec<T>::get(AbstractVec<T>::write_index) = x;
				AbstractVec<T>::write_index ++;
				return true;
			}else{
				return false;
			}
		}
		virtual ostream& print(ostream& os)override{
			AbstractVec<T>::print(os);
			return os;
		}
};

template <typename T> 
class CircularVec : public AbstractVec<T>{
	
	public:
		int cycles;
	
		CircularVec(int max_size):AbstractVec<T>(max_size){
		}
		virtual T* next()override{
			AbstractVec<T>::read_index ++;
			if(AbstractVec<T>::read_index == AbstractVec<T>::max_size){
				AbstractVec<T>::read_index = 0;
				cycles ++;
			}
			return AbstractVec<T>::get(AbstractVec<T>::read_index);
		}
		virtual bool insert (T x)override{
			*AbstractVec<T>::get(AbstractVec<T>::write_index) = x;
			AbstractVec<T>::write_index ++;
			if(AbstractVec<T>::write_index == AbstractVec<T>::max_size){
				AbstractVec<T>::write_index = 0;
				cycles ++;
			}
			return true;
		}
		virtual ostream& print(ostream& os)override{
			AbstractVec<T>::print(os);
			os<<" cycles= "<<cycles;
			return os;
		}
};

template<typename T>
ostream& operator<< (ostream& os, AbstractVec<T>& a){
	return a.print(os);
}

int main(){
	srand(424242);
	const int DIM = 10;
 	AbstractVec <int>* vec[DIM];
	for(int i=0; i<DIM; i++) {
    	int size = rand()%16+5;
    	if(rand()%2){
        	vec[i] = new PlainVec<int>(size);
    	} else {
        	vec[i] = new CircularVec<int>(size);
    	}
	}
 
	for(int i=0; i<DIM*5; i++) {
    	int x = rand()%100;
    	vec[x%DIM]->insert(x);
	}
 
	for(int i=0; i<DIM; i++)
    	vec[i]->shuffle();
    	
    cout<<"Punto 1: "<<endl;
    for(int i=0; i<DIM; i++){
    	cout<<i<<") "<<*vec[i]<<endl;
	}
	
	cout<<"\nPunto 2: "<<endl;
	int min = vec[0]->len();
	for(int i=0; i<DIM; i++){
		if(vec[i]->len() < min)
			min = vec[i]->len();
	}
	cout<<"Min: "<<min<<endl;
	
}