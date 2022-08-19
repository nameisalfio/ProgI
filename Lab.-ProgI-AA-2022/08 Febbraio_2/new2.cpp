#include<iostream>
#include<cstdlib>
#include<typeinfo>

using namespace std;

class AbstractRandomMat{

protected:

	int*** mat;
	int rows; 
	int cols;

public:

	AbstractRandomMat(int n, int m, int min, int max):rows(n), cols(m){

		mat = new int**[rows];
		for(int i=0; i<rows; i++){
			mat[i] = new int*[cols];
			for(int j=0; j<cols; j++){
				mat[i][j] = new int(rand()%(max-min+1)+min);
			}
		}
	}

	virtual int count()=0;

	int* get(int i, int j){return mat[i][j] ? mat[i][j] : nullptr;}

	int numel(){

		int count=0;

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(mat[i][j])
					count++;
			}
		}

		return count;
	}

	float mean(){

		int avg=0;

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(mat[i][j])
					avg += *mat[i][j];
			}
		}

		return (double)avg/numel();
	}

	virtual ostream& print(ostream& os){

		os << "Class: " << typeid(*this).name() << ", rows= " << rows << ", cols= " << cols << ", \nmat: ";
		/*
		for(int i=0; i<rows; i++){
			os << "[ ";
			for(int j=0; j<cols; j++){
				if(mat[i][j]){

					os << *mat[i][j] << " ";

				}
			}
			os << "]";
		}
		os << " ]";
		*/

		for(int i=0; i<rows; i++){
			os << "\t[ ";
			for(int j=0; j<cols; j++){
				if(mat[i][j]){

					os << *mat[i][j] << " ";

				}
			}
			os << "]" << endl;
		}

		return os;
	}
};

class BinaryMat : public AbstractRandomMat{

public:

	BinaryMat(int n, int m) : AbstractRandomMat{n, m, 0, 1}{}

	int count(){return AbstractRandomMat::numel();}
};

class EvenMat : public AbstractRandomMat{

	double midpoint;

public:

	EvenMat(int n, int m, int min, int max) : AbstractRandomMat{n, m, min, max}, midpoint((double)(min+max)/2){}

	int count(){

		int count = 0;

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(mat[i][j] && *mat[i][j]>midpoint)
					count ++;
			}
		}

		return count;
	}

	int countMul (int num){

		int count = 0;

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(mat[i][j] && *mat[i][j]%num == 0)
					count ++;
			}
		}

		return count;
	}

	ostream& print(ostream& os){

		AbstractRandomMat::print(os);
		return os << ", midpoint= " << midpoint;
	}
};

ostream& operator<< (ostream& os, AbstractRandomMat& a){return a.print(os);}

int main(){

	srand(424242);

	const int DIM = 25;
	AbstractRandomMat* vett[DIM];

	for(int i=0; i<DIM; i++) {
		int n=5+rand()%5;
		int m=5+rand()%5;
		int min = rand()%10 + 5;
		int max = min + rand()%20;

		switch(rand()%2) {
			case 0: 
				vett[i]= new BinaryMat(n, m);
				break;
			case 1:
				vett[i]= new EvenMat(n, m, min, max);
		}
	}

	cout << endl;

	//Punto 1:
	for(int i=0; i<DIM; i++){
		cout << i+1 << ") " << *vett[i] << endl;
	}

	//Punto 2:
	int max = vett[0]->count();
	for(int i=0; i<DIM; i++){
		if(vett[i]->count() > max)
			max = vett[i]->count();
	}
	cout << "\nMax count()= " << max << endl;

	//Punto 3:
	int sum = 0;
	int count = 0;
	for(int i=0; i<DIM; i++){
		if(typeid(*vett[i]) == typeid(EvenMat)){
			sum += static_cast<EvenMat*>(vett[i])->countMul(4);
			count++;
		}
	}
	cout << "\nMean countMul(4)= " << (double)sum/count << endl;


	cout << endl;
}