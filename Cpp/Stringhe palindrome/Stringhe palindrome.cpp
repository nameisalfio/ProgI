#include <iostream>
#include <string>
using namespace std;

int main(){
	bool esito = true;
	string s ;
	cout<<"Inserisci stringa "<<endl;
	cin>>s;
	int i;
	int j;
	
	for(i=0, j=s.length()-1; i<j; i++, j--){
		
			if(s[i]!=s[j]){
				esito = false;
				break;
			}
	}
	
	if (esito){
		cout<<"Palindroma";
	}else {
		cout<<"Non palindroma";
	}
}