#include<iostream>
#include<cstdlib>
#include<typeinfo>

using namespace std;

template<typename T>
class AbstractVec{

private:

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

	void set(T x, int i){
		data[i] = new T(x);
	}

public:

	AbstractVec(int max_size):max_size(max_size), read_index(0), write_index(0){

		data = new T*[max_size];
		for(int i=0; i<max_size; i++)
			data[i] = nullptr;
	}

	virtual T* next() = 0;

	virtual bool insert(T x) = 0;

	int len(){

		int count=0;
		for(int i=0; i<max_size; i++){
			if(data[i])
				count ++;
		}
		return count;
	}

	void shuffle(){

		for(int i=0; i<max_size; i++){
			int r = rand() % max_size;

			if(data[i]){

				while(!data[r])
					r = rand() % max_size;
			
				T* temp = data[i];
				data[i] = data[r];
				data[r] = temp;
			}
		}
	}

	double mean(){

		double sum = 0.0;

		for(int i=0; i<max_size; i++){
			if(data[i])
				sum += *data[i];
		}

		return (double)sum/len();
	}

	virtual ostream& print (ostream& os){

		os << "Class: " << typeid(*this).name() << ", max_size= " << max_size << ", vec=[ ";
		for(int i=0; i<max_size; i++){
			if(data[i])
				os << *data[i] << " ";
		}
		return os << "], len()= " << len() << ", mean()= " << mean();
	}
};

template<typename T>
class PlainVec : public AbstractVec<T>{

public:

	PlainVec(int max_size) : AbstractVec<T>(max_size){}

	T* next(){

		if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size){
			return AbstractVec<T>::get(AbstractVec<T>::read_index++);
		}
		return nullptr;
	}

	bool insert(T x){

		if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size){
			AbstractVec<T>::set(x, AbstractVec<T>::write_index++);
			return true;
		}
		return false;
	}
};

template<typename T>
class CircularVec : public AbstractVec<T>{

public:

	int cycles;

	CircularVec(int max_size) : AbstractVec<T>{max_size}, cycles(0){}

	T* next(){

		if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size){
			T* temp = AbstractVec<T>::get(AbstractVec<T>::read_index++);

			if(AbstractVec<T>::read_index == AbstractVec<T>::max_size){
				AbstractVec<T>::read_index = 0;
				cycles ++;
			}
			return temp;
		}
		return nullptr;
	}

	bool insert(T x){

		if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size){
			AbstractVec<T>::set(x, AbstractVec<T>::write_index++);

			if(AbstractVec<T>::write_index == AbstractVec<T>::max_size){
				AbstractVec<T>::write_index = 0;
				cycles ++;
			}
			return true;
		}
		return false;
	}

	ostream& print (ostream& os){

		AbstractVec<T>::print(os);
		return os << ", cycles= " << cycles;
	}
};

template<typename T>
ostream& operator<< (ostream& os, AbstractVec<T>& ref){return ref.print(os);}

int main(){

	srand(424242);

	const int DIM = 10;

	AbstractVec<int>* vec[DIM];
	 
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
	for(int i=0; i<DIM; i++){
		cout << i << ") " << *vec[i] << endl;
	}

	//Punto 2:
	int min=vec[0]->len();
	for(int i=0; i<DIM; i++){
		if(vec[i]->len() < min)
			min = vec[i]->len();
	}
	cout << "\nMin len(): " << min << endl;

	//Punto 3:
	double max=vec[0]->mean();
	for(int i=0; i<DIM; i++){
		if(vec[i]->mean() > max)
			max = vec[i]->mean();
	}
	cout << "\nMax mean(): " << max << endl;

	cout << endl;
} 
