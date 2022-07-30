#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
 srand(time(0));
int n, i, j;
cout<<"Quanto deve essere la matrice nxn?"<<endl;
cin>>n;
cout<<endl;
 int V[n][n], differenze[i];
 float somma, media;
 for(i = 0; i < n; ++i){ //popola rand
	 for(j = 0;  j < n; ++j){
		V[i][j] = rand()%10+1; // numeri da 1 a 10
		}
	}
 for( i = 0; i < n; ++i){ //stampa
	for( j = 0; j < n; ++j)
	cout<<V[i][j]<<'\t';
	cout<<'\n';
 }
 cout<<endl;
 // calcolo matrice 
 i=0; j=n-1;
 do{
 differenze[i]=V[i][i] - V[i][j];
 i++;
 j--;
 } while(i<n);
 
 cout<<"le differenze:";
 for(i=0; i<n; i++){
 cout<<differenze[i]<<" ; \t";
 somma=somma+differenze[i];
 }
 
 media=somma/n;
 cout<<endl;
 cout<<"la media e'"<<media;
 
 return 0;
}
