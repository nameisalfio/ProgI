#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <math.h>

using namespace std;

class AbstractRandomMat{

	protected:
		int ***mat;
		int rows; 
		int cols;

	public:
		AbstractRandomMat(int n, int m, int min, int max): rows(n), cols(m){
			mat = new int **[rows];
			for(int i=0; i<rows; i++)
			{
				mat[i] = new int*[cols];

				for(int j=0; j<cols; j++)
					mat[i][j] = new int(rand()% (max-min+1)+min);

			}
		}

		virtual int count() = 0;

		int* get(int i, int j){
			if(mat[i][j])
				return mat[i][j];
			return nullptr;
		}

		int numel(){

			int c = 0;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					if(mat[i][j])
						c ++;
				}
			}

			return c;
		}

		float mean(){

			float mean = 0.0;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					if(mat[i][j])
						mean += *mat[i][j];
				}
			}

			return (float)mean/numel();
		}

		virtual ostream& print(ostream& os){

			os << "Class= " << typeid(*this).name() << ", rows= " << rows << ", cols= " << cols << ", mat=[ ";
			for(int i=0; i<rows; i++)
			{
				os << " [ ";
				for(int j=0; j<cols; j++)
				{
					if(mat[i][j])
						os << *mat[i][j] << " ";
				}
				os << " ] ";
			}

			return os << " ]";
		}
};

class BinaryMat : public AbstractRandomMat{

	public:
		BinaryMat(int n, int m):AbstractRandomMat{n, m, 0, 1}{}

		int count()override{return this->numel();}

		ostream& print(ostream& os)override{
			AbstractRandomMat::print(os);
			return os;
		}

};

class EvenMat : public AbstractRandomMat{

	double midpoint;

	public:
		EvenMat(int n, int m, int min, int max):AbstractRandomMat{n, m, min, max}{
			midpoint = (double)(max+min)/2;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					int val = rand() % (max-min+1)+min;
					while(val%2 != 0)
						val = rand() % (max-min+1)+min;

					this->mat[i][j] = new int(val);
				}
			}

		}

		int count()override{

			int c = 0;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					if(this->mat[i][j])
					{
						if(*mat[i][j] > midpoint)
							c++;
					}
				}
			}

			return c;
		}

		int countMul(int num){

			int c = 0;

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					if(this->mat[i][j])
					{
						if(*mat[i][j]%num == 0)
							c++;
					}
				}
			}

			return c;
		}

		ostream& print(ostream& os)override{
			AbstractRandomMat::print(os);
			return os << ", midpoint= " << midpoint;
		}
};

ostream& operator<< (ostream& os, AbstractRandomMat& obj){return obj.print(os);}

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
	for(int i=0; i<DIM; i++)
		cout << i+1 << ") " << *vett[i] << endl;

	//Punto 2:
	int min = vett[0]->count();

	for(int i=0; i<DIM; i++)
	{
		if(vett[i]->count() < min)
			min = vett[i]->count();
	}
	cout << "\nMin: " << min << endl;

	//Punto 3:

	double avg = 0.0;
	int c = 0;
	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vett[i]) == typeid(EvenMat))
		{
			avg += static_cast<EvenMat*>(vett[i])->countMul(4);
			c ++;
		}
	}
	cout << "\nAvg: " << (double)avg/c << endl;

}