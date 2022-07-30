#include<iostream>
#include<fstream>
using namespace std;

int main (){

float x;
cout<<"Inserisci x :"<<endl;
cin>>x;
if (cin.fail()){
	cerr<<"I/O Error : cin.fail() = "<<cin.fail()<<endl;
	return -1;
}else 
  cout<<"Hai inserito il numero : "<<x<<endl;


/*bool eof = false;


if (eof = cin.eof()){
	cout<<"EOF! cin.fail() = "<<cin.fail()<<endl;
	cin.clear();
}



/*ifstream myfile( ) ; //NB: costr. default
myfile.open( "test.txt" ) ; //NB: metodo open
if(myfile.is_open())
cerr<<"Errore apertura file !"<<endl;
*/
return 0;
}
