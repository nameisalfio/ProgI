//Frame : https://www.antoninofurnari.it/downloads/lab080222_2/frame-08_02_2022.cpp
//Output Linux : https://www.antoninofurnari.it/downloads/lab080222_2/out_lin.txt

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <typeinfo>

using namespace std;

class AbstractRandomMat{

protected:
	int***mat;
	int rows;
	int cols;

public:
	AbstractRandomMat(int n, int m, int min, int max):rows(n), cols(m){

		mat = new int**[rows];
		for(int i=0; i<rows; i++)
		{
			mat[i] = new int *[cols];
			for(int j=0; j<cols; j++)
				mat[i][j] = new int(rand()% (max-min+1)+min);
		}
	}

	virtual int count() = 0;

	int* get(int i, int j){

		if(mat[i][j])
			return mat[i][j];
		else                    //RAMO ELSE INUTILE
			return nullptr;
	}

	int numel(){

		int count = 0;

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(mat[i][j])
					count ++;
			}
		}

		return count;
	}

	float mean(){

		double mean=0;

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

	virtual ostream& print (ostream& os){
/*
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
*/
		os << "Class= " << typeid(*this).name() << ", rows= " << rows << ", cols= " << cols << ", mat=[ ";
		for(int i=0; i<rows; i++)
		{
			os << endl;
			for(int j=0; j<cols; j++)
			{
				if(mat[i][j])
					os << "\t" << *mat[i][j] << " ";
			}
			os << endl;
		}

		return os << " ]";
	}
};

class BinaryMat : public AbstractRandomMat{

public:

	BinaryMat(int n, int m) : AbstractRandomMat(n, m, 0, 1){}

	int count(){return AbstractRandomMat::numel();}

	ostream& print(ostream& os){
		AbstractRandomMat :: print(os);
		return os;
	}
};

class EvenMat : public AbstractRandomMat{

	double midpoint;

public:

	EvenMat(int n,int m,int min,int max):AbstractRandomMat(n,m,min,max){
        int val=0;

        this->midpoint=(double)((min+max)/2);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                val=rand()%(max-min+1)+min;
                while(val%2!=0)
	                val=rand()%(max-min+1)+min;
                
                AbstractRandomMat::mat[i][j]= new int(val);
            }
        }
    }

	int count(){

		int count = 0;

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(mat[i][j])
				{
					if(*mat[i][j] > midpoint)
						count ++;
				}
			}
		}

		return count;
	}

	int countMul(int num){

		int count = 0;

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(mat[i][j])
				{
					if(*mat[i][j] % num == 0)
						count ++;
				}
			}
		}

		return count;
	}

	ostream& print(ostream& os){
		AbstractRandomMat :: print(os);
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

	//Punto 1
	for(int i=0; i<DIM; i++)
		cout << i << ") " << *vett[i] << endl;

	//Punto 2
	int max = vett[0]->count();
	for(int i=0; i<DIM; i++)
	{
		if(vett[i]->count() > max)
			max = vett[i]->count();
	}

	cout << "\nMax count() = " << max << endl;

	//Punto 3

	float avg = 0.0;
	int count = 0;
	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vett[i]) == typeid(EvenMat))
		{
			avg += static_cast<EvenMat*>(vett[i])->countMul(4);
			count++;
		}
	}

	cout << "\nMean countMul(4)= " << (float)avg/count << endl;

	cout << endl;
}