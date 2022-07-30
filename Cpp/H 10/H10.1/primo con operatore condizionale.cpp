/*Siano a, b e c tre variabili di tipo int. Trovare il massimo
dei tre numeri usando l’operatore condizionale.*/

#include <iostream>
using namespace std;

int main (){

int a,b,c;  //variabili di partenza
int Max, min;  //Massimo e minimo

cout<<("Inserisci il valore di a : ")<<endl;
cin>>a;
cout<<("Inserisci il valore di b : ")<<endl;
cin>>b;
cout<<("Inserisci il valore di c : ")<<endl;
cin>>c;

Max = a;
min = a; 

/*if (b > Max) 
  Max = b;  //ho trovato un nuovo massimo
  else if (b < min)
  min = b;  //ho trovato un nuovo minimo
if (c > Max)
  Max = c;  //ho trovato un nuovo massimo
else if (c < min)
  min = c;  //ho trovato un nuovo minimo*/
     
                            // Sintassi ( COND ? EXPR1 : EXPR2 );   
Max = (b > Max ? b : a);    // Il compilatore inserisce su "Max" un valore dopo
min = (b < min ? b : a);    // aver valutato la condizione COND tra parentesi .
Max = (c > Max ? c : Max);  // Se la condizione è vera valuta EXPR1 , in caso
min = (c < min ? c : min);  // contrario valuta EXPR2.

cout<<("Il massimo dei valori inseriti e': ")<<Max<<endl;
cout<<("Il minimo dei valori inseriti e': ")<<min<<endl;

return 0;
}