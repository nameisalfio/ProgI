/*
Sulla base degli esempi precedenti, codificare un
ciclo while in linguaggio C++ nel quale:
• il loop si ferma quando il capitale o montante
raggiunge o supera la cifra target definita in una
costante T;
• tuttavia il periodo di accumulo di interessi sul
montante non deve in ogni caso superare il
numero di anni definito in una costante N.
*/

#include <iostream>

using namespace std;

int main (void){

const double TASSO_INTERESSE = 0.1 ;
const int N = 5;
double capitale = 1000.0;

const int T = 1400; //target da non eguagliare o superare 

int anno = 0; 
while (capitale < T){
  while (anno < N){ 
  capitale += capitale*TASSO_INTERESSE ;
  anno++; 
  }
}
cout<<anno<<"\n";
cout<<capitale<<"\n";
return 0;

}