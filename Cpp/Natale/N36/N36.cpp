/*36.Scrivere un metodo che prenda in input una 
matrice di stringhe di dimensioni n×m, due stringhe x 
e y e due short k e w; il metodo restituisca la 
percentuale di colonne della matrice che contengono 
almeno k stringhe contenenti almeno w caratteri 
presenti sia in x che in y. 
NB: si assuma, per semplicità, che ognuna delle stringhe
della matrice non che le stringhe x e y non contengano 
lo stesso carattere più di una volta*/

#include<iostream>
#include<sstream>
#define n 3
#define m 2
using namespace std;

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

double funzione(string a[n][m], string x, string y, short w, short k){
    
    print(a);
    stringstream ss;  //Creazione del buffer 
	for(int i=0; i<x.length(); i++){
		for(int j=0; j<y.length(); j++){
			if(x[i] == y[j])
			ss<<x[i];	//Inserimento dei dati nel buffer
		}
	}
    cout<<"Caratteri comuni a X e Y : "<<endl;
    cout<<ss.str()<<" ";  //Stampo lo stream
    
    int count, count1, count2=0;
    
	for(int j=0; j<m; j++){
		count1=0;
		for(int i=0; i<n; i++){
			count=0;
			for(int k=0; k<a[i][j].length(); k++){
				if( (ss.str()).find( (a[i][j])[k] ) != string::npos) //Le stringhe hanno caratteri comuni allo stream
				count++;  //La stringa ha count caratteri presenti in x e y
			}
			if(count >= w)
			count1++;  //La colonna ha count1 stringhe contenenti w caratteri
		}
		if(count1 >= k)
		count2++;  //La matrice contiene count2 colonne che rispettano la condizione richiesta
	}
	
	return (count2*100)/m;
}

int main(){
	short w = 2;
	short k = 3;
	string x = "pino";
	string y = "pluto";
	
	string a[n][m];
	for(int i = 0; i<n; i++){
		for(int j = 0;j<m; j++){
//			cout<<"Inserisci stringa"<<endl;
//			cin>>a[i][j];
            a[i][j]="pinoli";
		}
	}
	
	cout<<endl;
	double func = funzione(a,x, y, w, k);
	cout<<"\nIl "<<func<<" % delle colonne"<<endl;
}