/*Codificare un programma in linguaggio C++ che chieda
all’utente di inserire da tastiera il proprio nome e cognome.
Successivamente il programma dovrà stampare le seguenti
informazioni:

1. il primo e l’ultimo carattere del nome, il secondo ed il
terzo carattere del cognome.

2. una stringa formata da tutti i caratteri che sono presenti
sia nel nome che nel cognome. 
ES: se nome = ”Mario”,
cognome = ”Rossi” lo output sarà ”io”.

3. le segg. ulteriori informazioni:

a) un messaggio che comunica all’utente se la prima
lettera del nome è uguale all’ultima lettera del cognome.

b) un messaggio che comunica all’utente se il numero di
caratteri del nome è uguale al numero di lettere del
cognome.

c) il numero di consonanti del nome e del cognome.

*/

#include <iostream>
#include <string>

using namespace std;

int main (){

int x; //variabile per scorrere la stringa
int count = 0, countc = 0; //variabile contatore di consonanti
string nome, cognome, common; 
char aux;  //variabile ausiliaria per la somma parziale dei caratteri comuni
int V;
char vocali [V] = {'a' , 'e', 'i', 'o', 'u'};

cout<<"Inserisci il tuo nome : "<<endl;
cin>>nome;
cout<<"Inserisci il tuo cognome : "<<endl;
cin>>cognome;

cout<<endl<<"Il primo e l'ultimo carattere del nome sono : "<< nome[0] << " e " << nome[nome.length()-1] <<endl;
//stampo i caratteri richiesti nel nome

cout<<"Il secondo e terzo carattere del cognome sono : "<< cognome[1] << " e " << cognome[2] <<endl<<endl;
//stampo i caratteri richiesti nel cognome

while (x < nome.length()){  //scorri il nome fino a che ci sono caratteri da confrontare
  
  //nome[x]--> CARATTERE di indice "x" all'interno della stringa "nome". Equivalente a "nome.at(x)"
  
  /*cognome.find ('a',0)--> Restituisce l'INDICE che corrisponde alla posizione del carattere 'a' , se trovato
                            nella stringa "cognome". La ricerca inizia dal carattere di indice 0 */
  
  /*cognome.find (nome[x])--> Restituisce l'INDICE corrispondente alla posizione del carattere 'x' (contenuto in nome) 
                                se trovato all'interno della stringa "cognome". La ricerca inizia dal carattere di 
								indice 0 (il primo carattere della stringa) se non è specificato il valore di inizio*/

  if ((cognome.find (nome[x])) == string::npos){  //se il carattere cercato non è presente nel cognome
  
  /* "string::npos" consente il confronto con un carattere non presente nella stringa . In questo caso la comparazione avviene
     tra l'indice in cui si trova il carattere "name[x]" all'interno di cognome (se dovesse esserci) e "string::npos".
     
     Uguagliare a "string::npos" equivale ad eguagliare il carattere precedentemente specificato (nome[x]) ad un
	 carattere NON PRESENTE nella stringa , pertanto :
     
	 - Se la comparazione è vera : allora "nome[x]" non sarà presente in cognome ;
	 - Se la comparazione è falsa : allora "nome[x]" sarà presente in cognome ;
	 
	 La logica viene chiaramente invertita se al posto dell'operatore di uguaglianza "==" usassi l'operatore di disuguaglianza "!=" */
  
  cout<<"carattere "<<nome[x]<<" non presente anche nel cognome "<< endl;  //stampo i caratteri del nome che non sono presenti anche nel cognome
  
  } else if ((cognome.find (nome[x])) != string::npos){  //se il carattere cercato è presente nel cognome
  	
    aux = cognome[cognome.find (nome[x])];  //inserisco il carattere comune nella variabile ausiliaria
  	common = common + aux;  //sommo i caratteri comuni nella stringa "common"
  	
    }

  x++;  //incremento l'indice per scorrere i caratteri del nome
}

cout<<endl<<"Stringa di caratteri comuni : "<<common<<endl;

if (nome[0] == cognome[cognome.length()-1])
  cout<<endl<<"La lettera "<<nome[x]<<" e' la prima del nome e anche l'ultima lettera del cognome ."<<endl;

if (nome.length() == cognome.length())
  cout<<endl<<"Sia il nome che il cognome contengono "<<nome.length()<<" lettere ."<<endl;
  
for (int i=0; i<nome.length(); i++){  //confronto i caratteri della stringa nome con le vocali ed incremento il contatore di conseguenza
	
	if(nome[i] != 'a' && nome [i] != 'A')
	
	if(nome[i] != 'e' && nome [i] != 'E')
	
    if(nome[i] != 'i' && nome [i] != 'I')
	 
	if(nome[i] != 'o' && nome [i] != 'O')
	
	if(nome[i] != 'u' && nome [i] != 'U')
	count ++;
	
}

if (count == 0 )
    cout<<"Non ci sono consonanti presenti nel nome "<<endl;  //caso in cui non sono presenti consonanti
    
    else 
	cout<<"Il numero di consonanti presenti nel nome e' : "<<count<<endl;  //stampo il numero di consonanti
	
for (int i=0; i<cognome.length(); i++){  //confronto i caratteri della stringa nome con le vocali ed incremento il contatore di conseguenza
	
	if(cognome[i] != 'a' && cognome [i] != 'A')
	  
	if(cognome[i] != 'e' && cognome [i] != 'E')
	
	if(cognome[i] != 'i' && cognome [i] != 'I')
	  
	if(cognome[i] != 'o' && cognome [i] != 'O')
	  
	if(cognome[i] != 'u' && cognome [i] != 'U')
	  countc++;
	
}

if (countc == 0 )
    cout<<"Non ci sono consonanti presenti nel cognome "<<endl;  //caso in cui non sono presenti consonanti
    
    else 
	cout<<"Il numero di consonanti presenti nel cognome e' : "<<countc<<endl;  //stampo il numero di consonanti

  
return 0;

}