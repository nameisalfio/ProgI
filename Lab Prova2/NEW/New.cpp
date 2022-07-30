#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
#include<typeinfo>
using namespace std;

template<typename T>
class A {

        int rows;
        int cols;

    private:
        T***Mat;

    public:
        A(int r, int c) : rows(r), cols(c){
            double a = 2.2;
            double b = 7.5;
            Mat = new T**[rows];
            for(int i=0; i<rows; i++)
            {
                Mat[i] = new T*[cols];
                for(int j=0; j<cols; j++)
                    Mat[i][j] = new T((b-a)*(1.0*rand()/RAND_MAX)+a);
            }
        }
		
        T** get_rows(int index){
            T** aux = new T*[cols];
            for(int i=0; i<cols; i++)
            {
                if(Mat[index][i])
                    aux[i] = Mat[index][i];
            }
            return aux;
        }
		
        T** get_cols(int index){
            T** aux = new T*[rows];
            for(int i=0; i<rows; i++)
            {
                if(Mat[i][index])
                    aux[i] = Mat[i][index];
            }
            return aux;
        }
		
		T** run(){
			
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					if(j != 0)
						*Mat[i][j] = 0;
				}
			}
			print();
			int step = rand()% rows;
			int a = 0;
			int b = 0;
			int c = 0;
			
			while(a == cols-1 || b == cols-1 || c == cols-1)
			{
				int step = rand()% rows;
				
				if(step == 0)
				{
					if(Mat[step][a])
						swap(Mat[step][a], Mat[step][a++]);
				}
				else if(step == 1)
				{
					if(Mat[step][b])
						swap(Mat[step][b], Mat[step][b++]);
				}
				else if(step == 2)
				{
					if(Mat[step][c])
						swap(Mat[step][c], Mat[step][c++]);
				}
				
			}
			return get_rows(step);
		}

        void shuffle(){

            int n = rand() % rows;
            int m = rand() % cols;
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    if(Mat[i][j])
                    {
                        T* aux  = nullptr;
                        while(!aux)
                        {
                            n = rand() % rows;
                            m = rand() % cols;
                            aux = Mat[n][m];
                        }
                        Mat[n][m] = Mat[i][j];
                        Mat[i][j] = aux;
                    }
                }
            }

        }

    protected:
        void swap(T* &a, T* &b){
			T* aux = a;
			a  = b;
			b = aux;
		}

        void traspose(){
			int aux = rows;
			rows = cols;
			cols = aux;
			
			T temp[rows][cols];
    		for(int i=0; i<rows; i++)
    		{
        		for(int j=0; j<cols; j++)
        		{
                    if(Mat[j][i])
           			temp[i][j] = *Mat[j][i];
        		}
    		}

			Mat = new T **[rows];
    		for(int i=0; i<rows; i++)
    		{
        		Mat[i] = new T*[cols];
       			for(int j=0; j<cols; j++)
            		Mat[i][j] = new T(temp[i][j]);
   			}
		}

        void put_matrix (){
            cout<<"\nMat: "<<endl;
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    if(Mat[i][j])
                        cout<<*Mat[i][j]<<" ";
                    else
                        cout<<Mat[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

template<typename T, typename C>
class B : public A<T>{

        T x; //<double><string>
        C y; //<int><char>

    public:
        B(int a, int b, short p, short q) : A<T>(a, b){

            if(typeid(x) == typeid(double))
            {
                double a = (p+q)/2;
                double b = pow(a,3)-sin(a/2);
                x = (b-a)*(1.0*rand()/RAND_MAX)+a;
            }else
                x="";
            //-----------------------------
            if(typeid(y) == typeid(int))
            {
                int a = p < q ? p : q;
                int b = p > q ? p : q;
                y = rand()%(b-a+1)+a;
            }else{
                int a = 'a';
                int b = 'z';
                y = rand()%(b-a+1)+a;
            }
            
        }

        T*** upside_down(){
            A::traspose();
            T** updown [rows];
            for(int i=0; i<rows; i++)
                updown = A::get_rows(i); 
        }
};

int main(){
	
    srand(time(NULL));
    A<double>* a = new B<double, char>(3, 4, 10, 20);

}