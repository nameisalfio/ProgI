#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
	/*string path_to_file = "testo.txt";
	ifstream file (path_to_file);
	
	if(!(file.is_open())){
		cerr<< "Attenzione ! Il file "<<path_to_file<<" non esiste."<<endl;
		return -1;
	}
	
	string x;
	while(file>>x){
		cout<<x<<endl;
	}
	
	string x;
	while(getline(file,x)){
		cout<<x<<endl;
	}*/
	
	string s = "testo.txt";
	ifstream file (s);
	
//	while(file>>s){
//		cout<<s<<endl;
//	}
	
	while(getline(file,s)){
		cout<<s<<endl;
	}

	
	if(file.is_open()){  //se il file è stato aperto 
		cout<<s<<endl;
	}
	
	return 0 ;
}