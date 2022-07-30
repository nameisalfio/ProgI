#include <iostream>

using namespace std;

int esercizio1(int*** M, int n, int m, short k, double z) {
    int c = 0;  //Inizializzazione del contatore
    for(int j = 0; j < m; j++) {    //ciclo che scorre le colonne
        for(int i = 0; i < n; i++) {    //ciclo che scorre le righe
            double sum = 0.0;   //mantiene la somma degli elementi contigui
            int seqlen = 0;     //lunghezza della sequenza
            bool found = false;
            for(int l = i; l < n; l++) {    //scorre gli elementi contigui
                if(M[l][j]){    //controlla se il puntatore non è nullptr
                    sum += M[l][j][0];
                    seqlen++;
                    if(seqlen >= k && sum/seqlen < z) { //controlla se la media degli elementi contigui di almeno k elementi è < z
                        found = true;
                        break;
                    }
                }
                else {
                    sum = 0.0;
                    seqlen = 0;
                }
            }
            if(found) {
                c++;
                break;
            }
        }
    }
    return c;
}

void printMatrix(int*** M, int n, int m) {
    cout << endl << "---------------------------------------" << endl;
    cout << "MATRICE" << endl << "---------------------------------------" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << M[i][j][0] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int ***M = new int**[4];
    int input = 0;
    for(int i = 0; i < 4; i++) {
        M[i] = new int*[3];
        for(int j = 0; j < 3; j++) {
            cout << "Inserisci un valore per la posizione [" << i << "][" << j << "]: ";
            cin >> input;
            M[i][j] = new int(input);
        }
    }
    printMatrix(M, 4, 3);
    cout << "Il numero di colonne che contengono almeno 2 elementi contigui \
    \nla cui media aritmetica risulti minore di 5.5 e' " << esercizio1(M, 4, 3, 2, 5.5) << endl;
}