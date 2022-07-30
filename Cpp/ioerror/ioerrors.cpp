/*Controllare un input dell'utente : 
- Esso deve essere un numero intero ;
- Se l'utente inserisce un valore non accettabile 
  bisogna prendere in input un nuovo valore;
- Se il valore inserito è un numero intero 
  determinare se esso è pari o dispari; */

#include <iostream>
#include <limits>

using namespace std;

int main (){

int x;
bool failure = false;

do{
cout<<"Inserisci un numero intero : "<<endl;
cin>>x;

if (cin.fail()){  //entro nell'if se i bit di stato cambiano in 1

	  cin.clear();  /*pongo a 0 il bit di stato in modo da non far pensare
	                  al compilatore che mi trovo in uno stato di errore*/
	                  
	  cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore i bit di stato vecchi
	                                                        
	  cerr<<"Errore, valore di ingresso non valido!!! "<<endl;
      failure = true;

}else{
	failure = false;
	    if (x%2 == 0){
	    cout<<"Il numero "<<x<<" e' pari"<<endl;
      } else {
	    cout<<"Il numero "<<x<<" e' dispari"<<endl;
      }
  }
}while(failure);  //failure == true

return 0 ;

}