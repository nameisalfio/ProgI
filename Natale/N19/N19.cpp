/* 19.Scrivere un metodo che prenda in input una 
matrice quadrata M di short e restituisca il valore 
booleano true se M e una matrice triangolare inferiore 
o superiore. */

#include<iostream>
#define N 3

using namespace std;

bool func (int M[N][N])
{
	cout<<endl<<"Matrice : "<<endl;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
    int i=1;
	int j;
    bool condizione = true;
    
    while(i<N && condizione == true)
    {
      j=0;
        
        while(j<i && condizione == true){
        	if(M[i][j]!=0 && M[j][i]!=0){
          	condizione = false;
		  }
          j++;
        }
        
      i++;
    }
      
  return condizione;
}

int main()
{
    int M[N][N];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<"Inserisci valore : "<<endl;
			cin>>M[i][j];
		}
	}
    
    bool esito = func (M);
    
    if(esito == true){
    	cout<< "La matrice e' triangolare ";
	}else{
		cout<< "La matrice non e' triangolare ";
	}
    
}