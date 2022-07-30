/*Codificare un programma in C++ che chiede all’utente di
inserire un carattere. Il programma dovr`a dare il seguente
output:
• Se il carattere è una vocale minuscola, stampa il
numero che rappresenta la sua codifica;
• Se il carattere è una vocale maiuscola, stampa il
carattere stesso sullo standard output;
• Se il carattere è un numero compreso tra 1 e 3, stampa
il numero stesso moltiplicato 10;
*/

#include <iostream>
using namespace std;

int main (){

char carattere;

cout<<"Inserisci un carattere : "<<endl;
cin>>carattere;

switch (carattere) {

  case 'a' : 
    cout<<"Il carattere inserito "<<carattere<<" corrisponde alla codifca ASCII : 01100001 "<<endl;  
	break;
		  
  case 'e' :
    cout<<"Il carattere inserito "<<carattere<<" corrisponde alla codifca ASCII : 01100101 "<<endl;
  	break;
  	    
  case 'i' :
  	cout<<"Il carattere inserito "<<carattere<<" corrisponde alla codifca ASCII : 01101001 "<<endl;  
  	break; 
  	
  case 'o' :
  	cout<<"Il carattere inserito "<<carattere<<" corrisponde alla codifca ASCII : 01101111 "<<endl;  
  	break;
  	
  case 'u' :
  	cout<<"Il carattere inserito "<<carattere<<" corrisponde alla codifca ASCII : 01110101 "<<endl;  
  	break;
  
  case 'A' :
  	cout<<"Il carattere inserito e' : "<<carattere<<endl;
    break;

 case 'E' :
  	cout<<"Il carattere inserito e' : "<<carattere<<endl;
    break;
    
 case 'I' :
  	cout<<"Il carattere inserito e' : "<<carattere<<endl;
    break;
    
  case 'O' :
  	cout<<"Il carattere inserito e' : "<<carattere<<endl;
    break;  
 
  case 'U' :
  	cout<<"Il carattere inserito e' : "<<carattere<<endl;
    break;
    
  case '1' :
  	cout<<"Il numero inserito moltiplicato per 10 e' : 10"<<endl;
  	break;
  	
  case '2' :
  	cout<<"Il numero inserito moltiplicato per 10 e' : 20"<<endl;
  	break;
  	
  case '3' :
  	cout<<"Il numero inserito moltiplicato per 10 e' : 30"<<endl;
  	break;	
  	
  default : 
    cerr<<"Errore ! Scelta non valida... "<<endl;
    return 1;
    break;
}

return 0;

}