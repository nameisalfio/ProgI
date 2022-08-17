#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<typeinfo>

using namespace std;

class A{

    string sa;

    public:

    A(string s1, string s2){

        //vocali in s1
        for(int i=0; i<s1.length(); i++){
            if(tolower(s1[i]) == 'a' || tolower(s1[i]) == 'e' || tolower(s1[i]) == 'i' ||
               tolower(s1[i]) == 'o' || tolower(s1[i]) == 'u'){
                sa += s1[i];
            }
        }

        //caratteri minuscoli in s2
        for(int i=0; i<s2.length(); i++){
            if(islower(s2[i])){
                sa += s2[i];
            }
        }
    }

    virtual ostream& print(ostream& os){return os << ": sa= " << sa << ", {";}

    virtual bool v(char c, short n) = 0;

    protected:

    short num(char c){

        for(int i=0; i<sa.length(); i++){
            if(sa[i] == c)
                return sa.length() - (i+1);
        }

        return -1;
    }

/*    short num (char c){
        int count = -1;
        for(int i=0; i<sa.length(); i++)
        {
            if(sa[i] == c)
                count ++;
        }
        return count;
    }*/
};

class B : public A{

    int* vec;
    short len;

    public:

    B(string w, short k) : A{w.substr(0, k), w.substr(k)}, len(w.length()){
        vec = new int[len];
        for(int i=0; i<len; i++){
            vec[i] = (int)w[i];
        }
    }

    bool v (char c, short n){
        if(num(c) >= n)
            return true;
        return false;
    }

    ostream& print(ostream& os){
        A::print(os);
        os << " vec= [ ";
        for(int i=0; i<len; i++){
            os << vec[i] << " ";
        }
        os << "], len= " << len;
        return os << " }";
    }
};

class C : public A{

    float y;
    string diff;

    public:

    C(string s1, string s2) : A{s1, s2}, y((float)(s1.length()+s2.length())/2){

        for(int i=0; i<s1.length(); i++){
            if(!(s2.find(s1[i]) <= s1.length())){
                diff += s1[i];
            }  
        }
    }

    bool v (char c, short n){

        for(int i=0; i<diff.length(); i++){
            if(diff[i] == c){
                if(i >= n)
                    return true;
            }
        }

        return false;
    }

    float f(){return log(y);}

    ostream& print(ostream& os){
        A::print(os);
        os << " y= " << y << ", diff= " << diff;
        return os << " }";
    }
};

ostream& operator<<(ostream& os, A& a){return a.print(os);}

int main(){

    const int DIM = 30;
    srand(111222333);
    A *vett[DIM];

    string s1, s2;
    short l1, l2;
    short k;

    for(int i=0; i<DIM; i++){
        if(rand()%2==0){
            s1 = "";
            l1 = rand()%10+5;
            k = rand()%(l1/2)+1;

            for(int j=0; j<l1; j++)
            s1+=((rand()%2) ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));

            vett[i] = new B(s1, k);
        }
        else{
            s1 = "";
            s2 = "";
            l1 = rand()%20 +6;
            l2 = rand()%20 +6;
            for(int j=0; j<l1; j++)
            s1+=(rand()%2 ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));


            for(int k=0; k<l2; k++)
            s2+=(rand()%2 ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));

            vett[i] = new C(s1, s2);
        }
    }

    cout << endl;

    //Punto 1:
    for(int i=0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //Punto 2:
    cout << "\nIndici v('b', 2) = true : " ;
    for(int i=0; i<DIM; i++){
        if(vett[i]->v('b', 2))
            cout << i << " ";
    }

    //Punto 3:
    double avg = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            avg += static_cast<C*>(vett[i])->f();
            count++;
        }
    }
    cout << "\nMedia : " << (double)avg/count << endl;

}