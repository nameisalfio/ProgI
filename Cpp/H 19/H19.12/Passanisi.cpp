/*Definire una funzione che prende in input un array di stringhe, un
array di caratteri, ed uno short w. La funzione restituisce il numero
di stringhe del primo array che contengono almeno w dei caratteri
presenti nel secondo array.*/

#include <iostream>
#include <string>
using namespace std;
#define N 3

void stampa(char * v,int n){
    int i=0;
    while(i<n){
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;
}

int numero_stringhe(string *vet1, char *vet2,int n,double w){
    int conta=0;
    int numero=0;
    int i=0;
    int j=0;
    int k=0;
    while(k<n){
        while(i<vet1[i].length()){
            while(j<n){
                if(vet1[k][i]==vet2[j]) conta++;
                j++;
            }
            i++;
            j=0;
        }
        if(conta >= w) numero++;
        conta=0;
        i=0;
        k++;
    }
    return numero;

}


int main(void){
    string s1[N]={"marco","pippo","mok"};
    char s2[N]={'m','o','k'};
    double w=2;
    int numero=numero_stringhe(s1,s2,N,w);
    cout<<numero;
    
}