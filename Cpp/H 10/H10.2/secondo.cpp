/*Siano a, b e c tre variabili di tipo int ed str una variabile
di tipo string. Se a e' diverso da c e la lunghezza della stringa str
e' minore di 8, allora copia in b la somma di a e c; Se a e' uguale a
c e la lunghezza della stringa str e' minore di 8, allora copia in a
il valore c − b; in tutti gli altri casi poni a, b e c a zero.
*/

#include<iostream>
#include<string>
using namespace std;

int main (){

int a,b,c;
string str;

cout<<"Inserisci il valore di a :"<<endl;
cin>>a;
cout<<"Inserisci il valore di b :"<<endl;
cin>>b;
cout<<"Inserisci il valore di c :"<<endl;
cin>>c;

cout<<"Inserisci una stringa di caratteri :"<<endl;
cin>>str;

if (a != c && str.length()<8){
b = a + c;
cout<<" b = "<<a<<" + "<<c<<" = "<<b<<endl;

}else if (a == c && str.length()<8){
a = c - b;
cout<<" a = "<<c<<" - "<<b<<" = "<<a<<endl;

}else{
a = b = c = 0;
cout<<" a = "<<a<<" b = "<<b<<endl;
}

return 0;
}