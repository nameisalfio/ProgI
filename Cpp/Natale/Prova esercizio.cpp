#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define n 3
#define m 2


void print (string a[n][m]){
	cout<<"-----------------------\n";
	cout<<"La matrice : \n"<<endl;
	for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-----------------------\n";
}

double funzione(string S[n][m], string x, string y, short k, short w){
	
	print(S);
	
	string c;
	for(int i=0; i<y.length(); i++){
		for(int j=0; j<x.length(); j++){
			if(x[j] == y[i])
			c += x[i];	
		}
	}
    cout<<"Caratteri comuni a X e Y : "<<endl;
    cout<<c<<endl;  
    
    int count;
    int count1;
    int colonne = 0;
    
    for(int j=0; j<m; j++){
    	count1 = 0;
    	for(int i=0; i<n; i++){
    		count = 0;
    		for(int k=0; k<(S[i][j].length()); k++){
    			if( c.find((S[i][j])[k]) != string::npos)
    				count++;
			}
			if(count >= w)
				count1++;
		}
		if(count1 >= k)
			colonne++;
	}

	return (colonne * 100)/m;
	
}


int main(){
	short w = 2;
	short k = 2;
	string x = "ciao";
	string y = "pino";
	
	string a[n][m];
	for(int i = 0; i<n; i++){
		for(int j = 0;j<m; j++){
			cout<<"Inserisci stringa"<<endl;
			cin>>a[i][j];
//            a[i][j]="Ciao";
		}
	}
	
	cout<<endl;
	double func = funzione(a, x, y, k, w);
	cout<<"\nIl "<<func<<" % delle colonne"<<endl;
}
