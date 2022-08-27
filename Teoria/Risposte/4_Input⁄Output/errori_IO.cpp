#include<iostream>
#include<limits>
using namespace std;

/*ES. 1

Si scriva un programma che chieda all’utente di inserire due numeri in virgola mobile che rappresentano la 
base e l’altezza di un triangolo e che stampi a schermo la sua area. Il programma deve gestire correttamente 
gli errori e ripetere la lettura da standard input di ciascun numero in input per al massimo 5 volte in caso 
di errori. Se un numero è stato inserito incorrettamente per più di 5 volte, terminare il programma restituendo 
un messaggio di errore.

int main(){

	float base;
	float altezza;

	short n_err = 0;	//numero di errori
	int i=0;
	while(i<5){
		i++;
		cout << "\nInserisci base: " << endl;
		cin >> base;

		if(cin.fail() || typeid(base) != typeid(double)){
			n_err ++;
			cerr << "\nErrore! Inserisci un numero in virgola mobile!" << endl;
			cin.clear();	//resetta i flag di errore di cin
            cin.ignore(numeric_limits<streamsize>::max() , '\n');	//svuota il buffer di cin
		}

		if(n_err == 5){
			cerr << "\nNumero massimo di tentativi disponibili raggiunto!" << endl;
			return EXIT_FAILURE;
		}
	}

	n_err = 0;
	i=0;
	while(i<5){
		i++;
		cout << "\nInserisci altezza: " << endl;
		cin >> altezza;

		if(cin.fail() || typeid(altezza) != typeid(double)){
			n_err ++;
			cerr << "\nErrore! Inserisci un numero in virgola mobile!" << endl;
			cin.clear();	//resetta i flag di errore di cin
            cin.ignore(numeric_limits<streamsize>::max() , '\n');	//svuota il buffer di cin
		}

		if(n_err == 5){
			cerr << "\nNumero massimo di tentativi disponibili raggiunto!" << endl;
			return EXIT_FAILURE;
		}
	}

	cout << "\nArea del rettangolo: " << (double)(base * altezza) << endl;
}
*/

/*ES. 2

Si scriva un programma che chiede di inserire in input 10 numeri e stampa a schermo la somma di questi numeri. 
Se uno dei valori inseriti non è un numero, terminare il programma con un messaggio di errore.

int main(){

	double num;
	double somma;
	int count=0;

	while(count < 10){
		count++;
		cout << "\nInserisci un numero: " << endl;
		cin >> num; 

		if(cin.fail()){
			cerr << "\nIl valore inserito non e' un numero! " << endl;
			return EXIT_FAILURE;
		}
		somma += num;
		num = 0;
	}

	cout << "\nSomma: " << somma << endl;
}
*/

/*ES. 3

Si scriva un programma che chiede di inserire in input dei numeri (l’inserimento termina con il carattere eof) 
e stampa a schermo la somma di questi numeri. Se si ha un errore di input, ripetere la possibilità di inserire 
un numero.

int main(){

    int somma=0;
    int x;

    bool finito = false;
    while(!finito ) {
        cout << "Inserisci un numero (premi CTRL + D per terminare): ";
        cin >> x;

        if(cin.fail()){
        	cin.clear(); //resetta i flag di errore di cin
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (cin.eof()) {    //true solo se si inserisce l'eof con CTRL + D
            finito = true;
        } else {
            somma += x;
        }
    }
    cout << "\nLa somma dei numeri inseriti e' " << somma << endl;
}
*/