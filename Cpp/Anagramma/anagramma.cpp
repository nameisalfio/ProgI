#include <iostream>
#include <string>
#include <ctime>

#define N 100

using namespace std;

int main(){
	
	int rand1, rand2, aux;
    char parola [N];
    
    cout<<"Inserisci una parola : "<<endl;
    cin>>parola;
    
    srand(time(NULL));  //generatore di numeri casuali
    
    for(int i=0; i<strlen(parola); i++){
    	for(int j=0; j<strlen(parola); j++){
    		
    		//indici casuali compresi tra "0" e "lunghezza della parola"
    		rand1 = rand() % strlen(parola);
    		rand2 = rand() % strlen(parola);
    		
    		//effettuo lo scambio di caratteri casuali
    		aux = parola[rand1];
    		parola[rand1] = parola [rand2];
    		parola[rand2] = aux;
    		
    		cout<<" Anagramma : "<<parola<<endl;
    		cout<<" Anagramma : "<<parola<<endl;
    			
		}
	}    
    
    return 0;
}