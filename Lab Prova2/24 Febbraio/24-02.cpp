//Frame: https://pastebin.com/XjPPK5Gh
//Output: JPEG

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<typeinfo>
using namespace std;

template<typename T>
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
			for(int i=0; i<max_size; i++)
				data[i] = nullptr;
		}
		virtual T* next() = 0;
		virtual bool insert(T x) = 0;
		int len(){
			int count = 0;
			for(int i=0; i<max_size; i++)
			{
				if(data[i])
					count ++;
			}
			return count;
		}
		/* Soluzione di Luigi
		void shuffle() {
			int r;
            for(int i = 0; i < max_size; i++) {
                if(data[i]) {
                    T* aux = nullptr;
                    while(aux == nullptr|| aux == data[i]) {
                        r = rand() % max_size;
                        aux = data[r];
                    }
                    data[r] = data[i];
                    data[i] = aux;
                }
            }
        }*/
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
		virtual ostream& print (ostream& s){
			s<<"Class="<<typeid(*this).name()<<", max_size="<<max_size<<", vec=[";
			for(int i=0; i<max_size; i++){
				if(data[i])
					s<<*data[i]<<" ";
				else
					s<<" ";
			}
			s<<"], len()="<<len();
			return s;
		}
	protected:
		T* get(int index)const{
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
				//*data[i] = x;
		}
};

template<typename T>
class PlainVec : public AbstractVec<T> {
	
	public:
		PlainVec(int max_size):AbstractVec<T>(max_size){}
		T* next()override{
			if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size -1)
				return AbstractVec<T>::get(AbstractVec<T>::read_index++);
			return nullptr;
		}
		bool insert (T x)override{
			if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size -1)
			{
				AbstractVec<T>::set(AbstractVec<T>::write_index, x);
				AbstractVec<T>::write_index ++;
				return true;
			}
			return false;
		}
		ostream& print (ostream& s)override{
			return AbstractVec<T>::print(s);
		}
};

template <typename T>
class CircularVec : public AbstractVec <T>{
	
	public:
		int cycles;
		CircularVec(int max_size) : AbstractVec<T>(max_size){
			cycles = 0;
		}
		T* next()override{
			T*aux = AbstractVec<T>::get(AbstractVec<T>::read_index);
			AbstractVec<T>::read_index ++;
			if(AbstractVec<T>::read_index == AbstractVec<T>::max_size -1){
				AbstractVec<T>::max_size = 0;
				cycles ++;
			}
			return aux;
		}
		bool insert(T x)override{
			AbstractVec<T>::set(AbstractVec<T>::write_index ++, x);
			if(AbstractVec<T>::write_index == AbstractVec<T>::max_size -1)
			{
				AbstractVec<T>::write_index = 0;
				cycles++;
			}
			return true;
		}
		int getCycles()const{
			return cycles;
		}
		ostream& print (ostream& s)override{
			AbstractVec<T>::print(s);
			s<<"cycles="<<cycles;
			return s;
		}
};

template <typename T>
ostream& operator<< (ostream& s, AbstractVec<T>& a){
	return a.print(s);
}

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
	
//....................................
	
	for(int i=0; i<DIM; i++)
		cout<<i<<") "<<*vec[i]<<endl;
		
//....................................
	int min = vec[0]->len();
	for(int i=0; i<DIM; i++){
		if(vec[i]->len() < min)
			min = vec[i]->len();
	}
	cout<<"\nMin: "<<min<<endl;
}

