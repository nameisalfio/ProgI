#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

class Card{

	int val; //valore
	char* card_suit; //seme

	public:
		Card(int val, string init):val(val){

			bool not_avaible = true;
			string avaibles[4]{"Denari","Coppe","Bastoni","Spade"};

			for(int i=0; i<4; i++)
			{
				if(init == avaibles[i])
				{
					not_avaible = false;
					break;
				}
			}

			if(not_avaible)
				throw "Card_suit isn't avaible..."; //Sollevo eccezzione

			//inizializzo il seme 
			card_suit = new char[init.length()];
			for(int i=0; i<init.length(); i++)
				card_suit[i] = init[i];
		}

		Card(){}

		Card& operator= (const Card& other){

			this->val = other.val;
			this->card_suit = other.card_suit;

			return *this;
		}

		int getVal()const{return this->val;}

		char* getSuit()const{return this->card_suit;}

		bool operator<= (const Card& other){return this->val <= other.val;}

		friend ostream& operator<< (ostream& os, const Card& c){
			return os << c.getVal() << " di " << c.getSuit();
		}
};

class Deck{

	const int size;

	protected:
		Card** deck;

	public:
		Deck():size(40){
			deck = new Card*[size];
			int pos = 0;

			for(int i=0; i<10; i++)
				deck[i] = new Card(++pos, "Denari");
			pos = 0;

			for(int i=10; i<20; i++)
				deck[i] = new Card(++pos, "Bastoni");
			pos = 0;

			for(int i=20; i<30; i++)
				deck[i] = new Card(++pos, "Coppe");
			pos = 0;

			for(int i=30; i<40; i++)
				deck[i] = new Card(++pos, "Spade");
			pos = 0;
		}

		virtual ostream& print(ostream& os){
			os << "Class: " << typeid(*this).name() << ", deck= [";
			for(int i=0; i<size; i++)
				os << "\t" << *deck[i] << endl;
			return os;
		}
};

ostream& operator<< (ostream& os, Deck& d){return d.print(os);}

int main(){

	Deck mazzo;

	cout << mazzo << endl;
}