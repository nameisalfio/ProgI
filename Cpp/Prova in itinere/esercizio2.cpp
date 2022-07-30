#include <iostream>
#include <string>

using namespace std;

void esercizio2(string***A, int n, int m, char* B, int k) {
    string vocali = "";
    for(int i = 0; i < k; i++) {
        //Controlla se il carattere B[i] è una vocale e la inserisce nella stringa vocali in maiuscolo
        switch(toupper(B[i])) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': {
                vocali += (char)(toupper(B[i]));
                break;
            }
        }
    }
    if(vocali.length() == 0) return; //se non ci sono vocali la funzione termina
    for(int j = 1; j < m; j+=2) { //scorre le colonne dispari
        for(int i = 0; i < n; i++) {
            if(A[i][j]) {
                string newString = "";
                string oldString = A[i][j][0];
                for(int l = 0; l < oldString.length(); l++) {
                    string check = "";
                    check += (char)(toupper(oldString[l]));
                    //string:npos è un valore che viene restituito dalla funzione find quando
                    //accade che la stringa check non è sotto stringa della stringa vocali.
                    if(vocali.find(check) == string::npos) {
                        newString += oldString[l];
                    }
                }
                A[i][j][0] = newString;
            }
        }
    }
}

void printMatrix(string*** M, int n, int m) {
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

void printArray(char* B, int n) {
    cout << endl << "---------------------------------------" << endl;
    cout << "ARRAY" << endl << "---------------------------------------" << endl;
    for(int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    char* B = new char[3];
    for(int i = 0; i < 3; i++) {
        cout << "Inserisci un carattere nel vettore B: ";
        cin >> B[i];
    }
    cout << endl;
    string*** M = new string**[4];
    string input = "";
    for(int i = 0; i < 4; i++) {
        M[i] = new string*[3];
        for(int j = 0; j < 3; j++) {
            cout << "Inserisci un valore per la posizione [" << i << "][" << j << "]: ";
            cin >> input;
            M[i][j] = new string(input);
        }
    }
    printArray(B, 3);
    cout << "Matrice prima:" << endl;
    printMatrix(M, 4, 3);
    esercizio2(M, 4, 3, B, 3);
    cout << "Matrice dopo:" << endl;
    printMatrix(M, 4, 3);
}