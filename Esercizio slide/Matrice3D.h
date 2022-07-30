#ifndef MATRICE3D_H
#define MATRICE3D_H

template <typename T>
class Matrice3D{

	int x;
	int y;
	int z;
	T val;
	T*** mat;

public:

	Matrice3D(int a, int b, int c, T val):x(a), y(b), z(c), val(val){

		mat = new T**[x];
		for(int i=0; i<x; i++)
		{
			mat[i] = new T*[y];
			for(int j=0; j<y; j++)
			{
				mat[i][j] = new T[z];
				for(int k=0; k<z; k++)
				{
					mat[i][j][k] = val;
				}
			}
		}
	}

	//copy constructor
	//Si rende necessario nel caso di allocazioni dinamiche per bypassare
	//il meccanismo di copia bitwise stabilito di default dal compilatore

	Matrice3D(const Matrice3D& other){

		this->memoryManagement(other);
	}

	void memoryManagement(const Matrice3D& source){

		this->x = source.x;
		this->y = source.y;
		this->z = source.z;
		this->val = source.val;

		this->mat = new T**[source.x];
		for(int i=0; i<x; i++)
		{
			this->mat[i] = new T*[source.y];
			for(int j=0; j<y; j++)
			{
				this->mat[i][j] = new T[source.z];
				for(int k=0; k<z; k++)
					this->mat[i][j][k] = source.mat[i][j][k];
			}
		}
	}

	//void constructor
	Matrice3D() : Matrice3D<T>{0,0,0,0}{} 

	int getDimX()const{return this->x;}

	int getDimY()const{return this->y;}

	int getDimZ()const{return this->z;}

	bool same_dim(Matrice3D<T> obj){return this->x == obj.x && this->y == obj.y && this->z == obj.z;}

	Matrice3D* sommaByPtr(Matrice3D<T>* ptr1, Matrice3D<T>* ptr2){

		if(!(ptr1->same_dim(*ptr2)))
			throw "\nDimensioni diverse! ";

		for(int i=0; i<ptr1->x; i++)
		{
			for(int j=0; j<ptr1->y; j++)
			{
				for(int k=0; k<ptr1->z; k++)
				{
					ptr1->mat[i][j][k] += ptr2->mat[i][j][k];
				}
			}
		}

		return ptr1;
	}

	Matrice3D<T>& sommaByReference(Matrice3D<T>& ref1, Matrice3D<T>& ref2){

		if(!(ref1.same_dim(ref2)))
			throw "\nDimensioni diverse! ";

		for(int i=0; i<ref1.x; i++)
		{
			for(int j=0; j<ref1.y; j++)
			{
				for(int k=0; k<ref1.z; k++)
				{
					ref1.mat[i][j][k] += ref2.mat[i][j][k];
				}
			}
		}

		return ref1;
	}

	T& getElement(int x, int y, int z){
		T& ref = mat[x][y][z];
		return ref;
	}

	T getValue(int x, int y, int z){return mat[x][y][z];}

	~Matrice3D(){

        for(int i=0; i<this->x; i++)
        {
			for(int j=0; j<this->y; j++)
				delete[] mat[i][j];

			delete[] mat[i];
		}
		delete[] mat;
    }

	//OVERLOADING OPERATORS

	//Tutti gli overloading che ritornano un reference rendono possibile utilizzare
	//il valore di ritorno a sinistra di un assegnamento(come lvalue modificabile).

	Matrice3D<T>& operator= (const Matrice3D<T>& source)const{

		this->memoryManagement(source);
		return *this;
	}

	bool operator== (const Matrice3D<T>& other){

		if(!(this->same_dim(other)))
			return false;

		bool same_value = true;

		for(int i=0; i<x; i++)
		{
			for(int j=0; j<y; j++)
			{
				for(int k=0; k<z; k++)
				{
					if(this->mat[i][j][k] != other.mat[i][j][k])
						same_value = false;
				}
			}
		}

		return same_value;
	}

	bool operator!= (const Matrice3D<T>& other){

		return (!(this->operator==(other)));
	}

	T& operator()(int x, int y, int z){

		return getElement(x,y,z);
	}

	Matrice3D<T>& operator+(const Matrice3D<T>& other){

		if(!(this->same_dim(other)))
			throw "\nDimensioni diverse! ";

		for(int i=0; i<this->x; i++)
		{
			for(int j=0; j<this->y; j++)
			{
				for(int k=0; k<this->z; k++)
				{
					this->mat[i][j][k] += other.mat[i][j][k];
				}
			}
		}

		return *this;
	}


	friend ostream& operator<< (ostream& os, const Matrice3D<T>& m){

		os << "\n-----------------------------\n";
		for(int i=0; i<m.x; i++)
		{
			for(int j=0; j<m.y; j++)
			{
				for(int k=0; k<m.z; k++)
				{
					cout << m.mat[i][j][k] << " ";
				}
				cout << "\t";
			}
			cout << endl;
		}
		return os;
	}
};

#endif