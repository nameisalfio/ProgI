#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<typeinfo>
#include<math.h>

using namespace std;

template<typename T>
class AbstractVec{

	T** data;

	protected:
		int max_size;
		int read_index;
		int write_index;
	
	public:
		AbstractVec(int max_size): read_index(0), write_index(0){
			this->max_size = max_size;
			data = new T*[max_size];
			for(int i=0; i<max_size; i++)
				data[i] = nullptr;
		}

		virtual T* next() = 0;
		virtual bool insert(T x) = 0;
		int len() {
			int num = 0;
			for(int i=0; i<max_size; i++)
			{
				if(data[i])
					num++;
			}
			return num;
		}
		void shuffle(){
			T* aux = nullptr;
			int r = rand()%max_size;
			for(int i=0; i<max_size; i++)
			{
				if(data[i])
				{
					while(data[r]){
						aux = data[i];
						data[i] = data[r];
						data[r] = aux;
						r = rand()%max_size;
					}
				}
			}
		}
		ostream& print(ostream& os){
			os<<"Class="<<typeid(*this).name()<<", max_size="<<max_size<<", vec[";
			for(int i=0; i<max_size; i++)
			{
				if(data[i])
					os<<*data[i]<<" ";
				else
					os<<"* ";
			}
			os<<"], len()="<<len();
			return os;
		}
	protected:
		T* get(int index){
			return data[index];
		}
		bool exists(int index){
			if(data[index])
				return true;
			else
				return false;
		}
		void set(int i, T x){
			if(data[i])
				*data[i] = x;
			else
                data[i] = new T(x);
		}
};

template<typename T>
class PlainVec : public AbstractVec<T>{

	public:
		PlainVec(int max_size) : AbstractVec<T>(max_size){}
		T* next(){
			if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size-1)
			{
				int aux = AbstractVec<T>::read_index;
				AbstractVec<T>::read_index++;
				return AbstractVec<T>::get(aux);
			}
			return nullptr;
		}
		bool insert(T x){
			if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size-1)
			{
				AbstractVec<T>::set(AbstractVec<T>::write_index, x);
				AbstractVec<T>::write_index++;
				return true;
			}
			return false;
		}
		ostream& print (ostream& os){
			AbstractVec<T>::print(os);
			return os;
		} 
};

template<typename T>
class CircularVec : public AbstractVec<T>{

	public:
		int cycles;
		CircularVec(int max_size) : AbstractVec<T>(max_size){
			this->cycles = 0;
		}
		T* next(){
			int aux = AbstractVec<T>::read_index;
			AbstractVec<T>::read_index ++;
			if(AbstractVec<T>::read_index == AbstractVec<T>::max_size)
			{
				AbstractVec<T>::read_index=0;
				cycles++;
			}
			return AbstractVec<T>::get(aux);
		}
		bool insert (T x){
			int aux = AbstractVec<T>::write_index;
			AbstractVec<T>::write_index++;
			if(AbstractVec<T>::write_index == AbstractVec<T>::max_size)
			{
				AbstractVec<T>::write_index=0;
				cycles++;
			}
			AbstractVec<T>::set(aux, x);
			return true;
		}
		int get_cycles(){
			return cycles;
		}
		ostream& print (ostream& os){
			AbstractVec<T>::print(os);
			os<<", cycles="<<get_cycles();
			return os;
		} 
};

template<typename T>
ostream& operator<<(ostream& os, AbstractVec<T>& a){
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
	for(int i=0; i<DIM; i++)
		cout<< i << ")" << *vec[i] << endl;
		
	cout<<"Punto 2: "<<endl;
	int min = vec[0]->len();
	for(int i=0; i<DIM; i++)
	{
		if(vec[i]->len() < min)
			min = vec[i]->len();
	}
	cout<<"Min_len()="<<min<<endl;
}