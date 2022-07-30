/* Un falegname realizza scaffali di legno per ambienti interni o
esterni. I clienti si recano presso il suo laboratorio con alcune
richieste (input) in base alle quali il falegname opera alcune
scelte:

1. ambiente: esterno o interno
2. massimo carico (in kg) che il singolo ripiano deve essere
in grado di sopportare;
3. lunghezza in metri di ogni ripiano


Il falegname dovrà operare nel modo seguente:

1. Se lo scaffale va sistemato all’esterno allora va impiegato
legno di castagno, altrimenti legno di pino;
2. lo spessore di ogni ripiano va calcolato in base alla
formula S = [B + max(0, L − 1) × P] × Q, dove:
• L `e la lunghezza (in metri) di ogni ripiano fornita dal
cliente;
• B = 0.018 metri se si usa il castagno, B = 0.02 metri
se si usa il pino;
• P = 0.02 per il castagno, P = 0.022 per il pino
• Q = 1.1 se il legno scelto `e il castagno e se il
massimo carico che il singolo ripiano deve supportare
e' maggiore di 100 kg, altrimenti Q = 1.0;
• Q = 1.2 se il legno scelto `e il pino e se il carico
massimo che il singolo ripiano deve supportare `e
maggiore di 80kg, altrimenti Q = 1.0.


Descrivere una soluzione del problema tale che, dati in input i
parametri ambiente, lunghezza L e carico massimo del singolo
ripiano dello scaffale, produca in output:

• essenza da usare (pino o castagno)
• spessore ripiani. */

#include <iostream>
#include <string>

using namespace std;

int main()
{
   string ambiente, essenza;
   float B, L, P, Q, C, S, max;
   
   
   cout<<"Lo scaffare deve essere utilizzato in un ambiente esterno o interno ?"<<endl;  //prendo in input la scelta "interno" o "esterno"
   cin>>ambiente;
   
   if (ambiente == "esterno")  //se la scelta è "interno", l'essenza sarà in castagno
      essenza = "castagno";
      
    else if (ambiente == "interno")  //se la scelta è "interno", l'essenza sarà in pino
      essenza = "pino";
      
    cout<<"Inserisci la lunghezza (in m) di ogni ripiano : "<<endl;  // //prendo in input la lunghezza 
    cin>>L;
    
    cout <<"Inserisci il massimo carico (in kg) che il singolo ripiano deve essere in grado di sopportare : "<<endl;  // //prendo in input il carico massimo 
    cin>>C;
    
    if (essenza == "castagno"){     
    	
    	B = 0.018;  //Attribuisco i valori a B e P se la scelta è "castagno"
    	P = 0.02;
    	
    	if(C > 100){
    		
    		Q = 1.1;  //Attribuisco il valore a Q se il carico massimo supera i 100kg
    		
		}else{
			
			Q = 1.0;  //Attribuisco il valore a Q se il carico massimo non supera i 100kg
			
		}
		
	}else if (essenza == "pino"){
		
		B = 0.02;  //Attribuisco i valori a B e P se la scelta è "castagno"
		P = 0.022;
		
		if (C > 80){
			
			Q = 1.2;  //Attribuisco il valore a Q se il carico massimo supera gli 80kg
				
		}else {
			
			Q = 1.0;  //Attribuisco il valore a Q se il carico massimo non supera gli 80kg
			
		}
		
    }
    
    max = (0 > L-1 ? 0 : L-1);     // max(0,L-1) con operatore condizionale
    
   /* if (0 > L-1)                 // max(0,L-1) con if
    
    	max = 0;
    	
	else if (L-1 > 0)
	
	    max = L-1; */
    
    S = (B + max * P) * Q ;  //Calcolo lo spessore a partire dai valori precedentemente assegnati

    cout<<"L'essenza da usare e' : "<<essenza<<endl;  //stampo l'essenza
    cout<<"Lo spessore deve essere di : "<<S<<" m "<<endl;  //stampo lo spessore

	return 0;
}