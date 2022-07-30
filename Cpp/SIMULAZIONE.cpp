//PRIMO ESERCIZIO

/*#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double **func (double**A, int n, int m){
	srand (time(NULL));
	double s = rand()/double(RAND_MAX);  //compresi tra 0 e 5 " rand()/double(RAND_MAX) * 5 "
	
	double **B = new double *[n];
	for (int i=0; i<n; i++){
		B[i] = new double [m];
		for (int j=0; j<m; j++){
			if (A[i][j]>s){
				B[i][j] = A[j][i];
			}else{
				B[i][j] = A[i%m][j%n];
			}
		}
	}
	return B;
	
}

int main(){
	int n = 5;
	int m = 3;
	
	srand(time(NULL));
	
	double **A = new double *[n];
	for (int i=0; i<n; i++){
		A[i] = new double [m];
		for (int j=0; j<m; j++){
//			cout<<"Inserisci valore in A : "<<endl;
//			cin>>A[i][j] ;
            A[i][j] = rand()%10;
		}
	}
	
	double **C = func(A, n, m);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<C<<"  ";
		}
		cout<<endl;
	}
	delete[] B;
}*/

//SECONDO ESERCIZIO

#include <iostream>
#include <string>
#include <sstream>

#define n 3
#define m 2

using namespace std;

string func (string **A){
	string s ; 
	stringstream ss;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<(A[i][j].length()); k++){
				
				if(A[i][j].length() > (A[j%n][i%m]).length()+(i+j)){
					
					if( (A[i][j])[k] == 'a' ||
					    (A[i][j])[k] == 'e' ||
					    (A[i][j])[k] == 'i' ||
					    (A[i][j])[k] == 'o' ||
					    (A[i][j])[k] == 'u'    ){
					   	
					   	ss<<(A[i][j])[k]<<endl;
					   	c++;
					   }
				}
			}
		}
	}
	
	return ss.str();
}

int main(){
	
    string **A = new string *[n];
	    for (int i=0; i<n; i++){
	    	
		   A[i] = new string [m];
		   for (int j=0; j<m; j++){
			cout<<"Inserisci stringa in A : "<<endl;
			cin>>A[i][j] ;

		}
	}
	
//	string s = func (A);
	stringstream ss ;
	ss << func (A);
	cout<<"Stringa di sole vocali : "<<ss.str()<<endl;
}