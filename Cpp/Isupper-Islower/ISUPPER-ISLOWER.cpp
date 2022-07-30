#include<iostream>
#include<string>
//#include<ctype.h>
using namespace std;
int main(){
	
	string s;
	
	cout<<"Inserisci una stringa "<<endl;
	cin>>s;
	
	int count = 0;
	int count2 = 0;
		if(isupper(s[i]))  
		  count++;
		if(islower(s[i]))
		  count2++;
	}
	cout<<"Numero totale di caratteri "<<s.length()<<endl;
	cout<<"Numero di caratteri maiuscoli "<<count<<endl;
	cout<<"Numero di caratteri minuscoli "<<count2<<endl;
}