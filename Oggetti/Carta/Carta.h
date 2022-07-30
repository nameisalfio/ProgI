#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Carta{
	private:
		int valore;
		string seme;
		
	public: 
	    Carta(int valore, string seme){
	    	this->valore = valore;
	    	this->seme = seme;
		}
		
//	    Carta(){
//	    	srand(time(0));
//	    	
//	    	int s = (rand()%4)+1;
//	    	    if(s == 1)
//			    seme = "Denari";
//				if(s == 2)
//				seme = "Spade";
//				if(s == 3)
//				seme = "Mazze";
//				if(s == 4)
//				seme = "Coppe";
//				
//			int v = (rand()%10)+1;
//			
//			valore = v;
//				
//		}
		
		int getValore() const{
			return valore;
		}
		
		string getSeme() const{
			return seme;
		}
		
		void rivela(){
			cout<<valore<<" di "<<seme<<endl;
		}
};


