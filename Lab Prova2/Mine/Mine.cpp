#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<typeinfo>
using namespace std;

class A{

    private:

        double* vec;
        short length;
        int mul;

    public:

        A (short w, int m):length(w), mul(m){
            vec = new double [length];
            double r  = (double) rand()/RAND_MAX;
            for(int i=0; i<length; i++)
            {
                r  = (double) rand()/RAND_MAX;
                vec[i] = mul * r; 
            }
        }
        virtual void origin () = 0;  //virtual pure function
        void sort(bool a){
            if(a)  //ascending order
            {
                int temp;
                for(int i=0; i<length-1; i++)
                {
                    if(vec[i] < vec[i+1])
                    {
                        temp = vec[i];
                        vec[i] = vec[i+1];
                        vec[i+1] = temp;
                    }
                }
            }else //descending order
            {
                int temp;
                for(int i=0; i<length-1; i++)
                {
                    if(vec[i] > vec[i+1])
                    {
                        temp = vec[i];
                        vec[i] = vec[i+1];
                        vec[i+1] = temp;
                    }
                }
            }
        }
        int fatt(int a){
            if(a == 0)
                return 1;
            else 
                return a * fatt(a-1);
        }
        int factor(short q){
            return fatt((int)vec[q]);
        }
        void set (double* d, short i){
            vec[i] = *d ;
        }
        virtual ostream& print(ostream& os){
        	os<<"Class="<<typeid(*this).name()<<", vec=[";
        	for(int i=0; i<length; i++)
        		os<<vec[i]<<" ";
			os<<"],";
			return os;
		}

    protected:

        double* get_ptr(short i){
            return &vec[i];
        }
        int get_len(){
            return length;
        }
};

class B : public A{
    
    char* c;
    
    public:

        B(short w, int m, char v) : A(w, m){
            c = new char[get_len()];
            char x = rand() % ('z' - 'a' + 1)+'a';  //between 'a' end 'z'
            int i = 0;
            while(i < get_len())
            {
                x = rand() % ('z' - 'a' + 1)+'a'; 
                if( x != v)
                {
                    c[i] = x;
                    i++;
                }
            }
        }
        double seg_max(){

            int max = 0;  //segment
	        int sum = max;
	        for(int i = 0; i < get_len(); i++) {

		        if (sum > 0) {  //sum is positive
			        sum += *get_ptr(i);
		        } else {
			        sum = *get_ptr(i);

		    }
                if (sum > max) //increase segment
                    max = sum;
	        }

	        return max;
        }
        void origin() override{
            char w[get_len()][get_len()]; //Matrix
            char p = rand()%('z' - 'a' + 1)+'a';

            for(int i=0; i<get_len(); i++)
            {
                for(int j=0; j<get_len(); j++)
                {
                    p = rand()%('z' - 'a' + 1)+'a';
                    w[i][j] = p;
                }
            }
        }
        void edit(){
            string* k = new string[get_len()];  //the same size of vec
            short idx = rand() % get_len();
            for(int i=0; i<get_len(); i++)
            {
                for(int j=0; j<get_len(); j++)
                {
                    idx = rand() % get_len();
                    k[i] += c[idx];
                } 
            }  
        }
        ostream& print(ostream& os)override{
        	A::print(os);
        	os<<"seg_max="<<seg_max()<<", c=";
        	for(int i=0; i<get_len(); i++)
        		os<<c[i];
        	return os;
		}
};

template<typename T>
class C : public A{

    double p;
    T k;

    public:
        C(short w, int m) : A(w, m){
            int r = rand()%get_len();
            p = *get_ptr(r);

            if(typeid(k) == typeid(double))
                k = ceil(180 * p);
            else
                p = m;

        }
        void origin() override{
            int **q = new int* [get_len()];
            for(int i=0; i<get_len(); i++)
            {
                if(q[i])
                    *q[i] = factor(i);
            }
        }
        void position(){
            int idx = rand() % get_len();
            set(&p, idx);
            sort(true);

            double sum = 0.0;
            for(int i=0; i<get_len(); i++)
                sum += *get_ptr(i);

            double avg = sum/get_len();  //Value of average
        }
        ostream& print(ostream& os)override{
        	A::print(os);
        	os<<"p="<<p<<", k="<<k;
        	return os;
		}
};

template<typename T>
class D : public C<T> {
	
	int g;
	
    public:

        D(short y, int z, int g) : C<T>(y, z){
			this->g = g; 
		}

        void swap (double& a, double& b){
            double aux = a;
            a = b;
            b = aux;
        }
        void reverse(){
            double a;
            double b;

            for(int i=0, j= C<T>::get_len()-1; i<j; i++, j--)
            {
                if(C<T>::get_ptr(i) && C<T>::get_ptr(j))
                {
                    a = *C<T>::get_ptr(i);
                    b = *C<T>::get_ptr(j);
                    swap(a, b);
                }
            }
        }
        void quick(){
            for(int i=0; i<C<T>::get_len(); i++)
            {
                int w = (int)(*C<T>::get_ptr[i]);
                if(w % 2 == 0)
                    int q = round(w/2);
            }
            C<T>::sort(false);
            double sum = 0.0;
            for(int i=0; i<C<T>::get_len(); i++)
                sum += *C<T>::get_ptr(i);

            double avg = sum/C<T>::get_len();  //Value of average
        }
        int MCD(int a, int b){
            if(a<b)
            {
                int aux = a;
                a = b;
                b = aux;
            }
            if(a % b == 0)
                return b;
            else{
                return  MCD(b, a % b);
            }
        }
        void origin()override{
            double arr[C<T>::get_len()];
            for(int i=0; i<C<T>::get_len(); i++)
            {
                int z = floor(*C<T>::get_ptr(g));
                arr[i]  = MCD(g, z);
            }
        }
        ostream& print(ostream& os)override{
        	A::print(os);
        	os<<"g="<<g;
        	return os;
		}
};

ostream& operator<< (ostream& os, A& a){
	return a.print(os);
}

int main(){
    
    const int DIM = 50;
    A* vet[DIM];
    srand(time(NULL));
    short n = 1+rand()%10;
    for(int i=0; i<DIM; i++)
    {
		switch(rand()%5){
			case 0 :
				vet[i] = new B(n, rand()%(n+5), rand ()%('z' - 'a' + 1)+'a');
				break ;
			case 1 :
				vet[i] = new C<double>(n, n + rand()%25);
				break ;
			case 2 :
				vet[i] = new C<short>(n , n + (rand()%25) * 6 );
				break;
			case 3 :
				vet[i] = new D<double>(n, 18 + rand()%n, pow(n, 2));
				break;
			case 4 : 
				vet[i] = new D<int>(n, (11 - rand()%10) * 3, rand()%8 + sin(n));
		}
	}

    //-----------------------------------------------------------------------------
    for(int i=0; i<DIM; i++)
    	cout<<i<<"), "<<*vet[i]<<endl<<endl;


}