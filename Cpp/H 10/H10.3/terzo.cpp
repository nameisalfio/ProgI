/* Siano s1, s2 ed s3 tre oggetti di tipo string e mys un
altro oggetto di tipo string.
• Se (A) la lunghezza di una delle tre stringhe s1, s2, s3 `e
maggiore di 10 e se (B) almeno una di esse `e lunga almeno
20 caratteri, allora copia nella variabile di tipo string
denominata mys la concatenazione dei primi tre caratteri in
s2 e degli ultimi tre caratteri in s3.
• Se la condizione A `e verificata ma non la B, allora copia in
mys la concatenazione delle tre stringhe, in ordine.
• In tutti gli altri casi stampa la somma delle lunghezze delle
tre stringhe
*/

#include<iostream>
#include<string>
using namespace std;

int main (){
int lunghezza;
string s1, s2, s3, mys;  

cout<<"Inserisci la prima stringa : "<<endl;
cin>>s1;
cout<<"Inserisci la seconda stringa : "<<endl;
cin>>s2;
cout<<"Inserisci la terza stringa : "<<endl;
cin>>s3;

cout<<"Inserisci una stringa mys : "<<endl;
cin>>mys;

if(s1.length() > 10 || s2.length() > 10 || s3.length() > 10){
	if(s1.length() == 20 || s2.length() == 20 || s3.length() == 20){
		
	mys = s2.substr (0,3) + s3.substr (s3.length() -3);  // concatenazione dei primi 3 caratteri di s2 e gli ultimi 3 di s3
	cout<<"Mys : "<<mys;
	
	}else{
		
		mys = s1 + s2 + s3;  // concatenazione ordinata delle 3 stringhe
		cout<<"Mys : "<<mys;
		
	}
} else {
	
	lunghezza = s1.length() + s2.length() + s3.length();  // somma della lunghezza delle 3 stringhe
	cout<<"Lunghezza totale : "<<lunghezza<<endl;
}

return 0;
}