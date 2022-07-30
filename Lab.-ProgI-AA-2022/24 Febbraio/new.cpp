#include<iostream>
#include<stdlib.h>
#include<typeinfo>

using namespace std;

template<typename T>
class AbstractVec{

	T** data;

protected:
	int max_size;
	int read_index;
	int write_index;

	T* get(int index){return data[index];}

	bool exists(int index){
		if(data[index])
			return true;
		return false;
	}

	void set(int i, T x){data[i%max_size] = new T(x);}

public:

	AbstractVec(int max_size):max_size(max_size), read_index(0),
	write_index(0){

		data = new T*[max_size];
		for(int i=0; i<max_size; i++)
			data[i] = nullptr;
	}

	virtual T* next() = 0;

	virtual bool insert(T x) = 0;

	int len(){
		int c = 0;

		for(int i=0; i<max_size; i++)
		{
			if(data[i])
				c++;
		}

		return c;
	}

	void shuffle(){

		for(int i=0; i<max_size; i++)
		{
			if(data[i])
			{
				int r = rand()%max_size;

				while(!data[r])
					r = rand()%max_size;

				T* aux = data[i];
				data[i] = data[r];
				data[r] = data[i];
			}
		}
	}

	double mean(){

		double mean = 0;
		for(int i=0; i<max_size; i++)
		{
			if(data[i])
				mean += *data[0];
		}

		return (double)mean/this->len();
	}

	virtual ostream& print(ostream& os){
		os << "Class: " << typeid(*this).name() << ", max_size= " << max_size 
		<< ", vec=[ ";

		for(int i=0; i<max_size; i++)
		{
			if(data[i])
				os << *data[i] << " ";
		}
		os << " ], len()= " << len() << ", mean()= " << mean();
		return os;
	}
};

template<typename T>
class PlainVec : public AbstractVec<T>{

	public:
		PlainVec(int max_size) : AbstractVec<T>{max_size}{}

		T* next()override{

			if(this->read_index < this->max_size)
				return this->get(this->read_index++);
			
			return nullptr;
		}

		bool insert(T x)override{

			if(this->write_index < this->max_size)
			{
				this->set(this->write_index ++, x);
				return true;
			}
			return false;
		}

		ostream& print(ostream& os)override{
			AbstractVec<T>::print(os);
			return os;
		}
};

template<typename T>
class CircularVec : public AbstractVec<T>{

	public:
		int cycles;

		CircularVec(int max_size) : AbstractVec<T>{max_size}, cycles(0){}

		T* next()override{

			if(this->read_index < this->max_size)
			{
				T* tmp = this->get(this->read_index++);

				if(this->read_index == this->max_size)
				{
					this->read_index = 0;
					cycles++;
				}

				return tmp;
			}

			return nullptr;
		}

		bool insert(T x)override{

			if(this->write_index < this->max_size)
			{
				this->set(this->write_index ++, x);
				if(this->write_index == this->max_size)
				{
					this->write_index = 0;
					cycles++;
				}

				return true;
			}
			return false;
		}

		int getCycles(){return this->cycles;}

		ostream& print(ostream& os)override{
			AbstractVec<T>::print(os);
			return os << ", cycle= " << cycles;
		}
};

template<typename T>
ostream& operator<< (ostream& os, AbstractVec<T>& obj){return obj.print(os);}

int main(){

	srand(424242);
	const int DIM = 10;

	AbstractVec<int>* vec [DIM];

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

    cout << endl;

    //Punto 1:
	for(int i=0; i<DIM; i++)
		cout << i << ") " << *vec[i] << endl;

	//Punto 2:
	int min = vec[0]->len();
	for(int i=0; i<DIM; i++)
	{
		if(vec[i]->len() < min)
			min = vec[i]->len();
	}

	cout << "\nMin= " << min << endl;

	//Punto 3:
	int max = 0;

	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vec[i]) == typeid(PlainVec<int>))
		{
			if(static_cast<PlainVec<int>*>(vec[i])->mean() > max)
				max = static_cast<PlainVec<int>*>(vec[i])->mean();
		}
	}

	cout << "\nMax= " << max << endl;
}