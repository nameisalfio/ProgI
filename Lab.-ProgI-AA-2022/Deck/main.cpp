#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

class Card
{

	int val; // valore
	char *card_suit; // seme

public:
	Card(int val, string init) : val(val)
	{

		bool not_avaible = true;
		string avaibles[4]{"Denari", "Coppe", "Bastoni", "Spade"};

		for (int i = 0; i < 4; i++)
		{
			if (init == avaibles[i])
			{
				not_avaible = false;
				break;
			}
		}

		if (not_avaible)
			throw "Card_suit isn't avaible..."; // Sollevo eccezzione

		// inizializzo il seme
		card_suit = new char[init.length()];
		for (int i = 0; i < init.length(); i++)
			card_suit[i] = init[i];
	}

	Card() {}

	int getVal() const { return this->val; }

	char *getSuit() const { return this->card_suit; }

	bool operator<=(const Card &other) { return this->val <= other.val; }

	bool operator<=(const int &other) { return this->val <= other; }

	friend ostream &operator<<(ostream &os, const Card &c)
	{
		return os << c.getVal() << " di " << c.getSuit();
	}
};

class Deck
{

protected:
	Card **deck;
	const int size;

public:
	Deck() : size(40)
	{
		deck = new Card *[size];

		int pos = 0;
		for (int i = 0; i < 10; i++)
			deck[i] = new Card(++pos, "Denari");
		pos = 0;

		for (int i = 10; i < 20; i++)
			deck[i] = new Card(++pos, "Bastoni");
		pos = 0;

		for (int i = 20; i < 30; i++)
			deck[i] = new Card(++pos, "Coppe");
		pos = 0;

		for (int i = 30; i < 40; i++)
			deck[i] = new Card(++pos, "Spade");
	}

	Card **changes(int idx)
	{
//		if(!deck[idx] || !getTop())
//			return nullptr;

		// Pone in cima la carta
		Card *tmp = getTop();
		getTop() = deck[idx];
		deck[idx] = tmp;

		cout << "Entra se " << *getTop()  << " e' <= di " << *deck[idx] << endl;
		if (*getTop() <= *deck[idx])
		{
			Card **toreturn = new Card *[10]; // No allocazione statica(deve essere restituito)
			string toremove = (string)(getTop()->getSuit());

			int pos = 0;
			cout << "Changes: " << endl;
			for(int i=0; i<size; i++)
			{
				if ((string)(deck[0]->getSuit()) == toremove)
				{	
					toreturn[pos++] = new Card(*getTop());
					this->remove(0);

					cout << *toreturn[pos-1] << endl;
				}
			}

			return toreturn;
		}
		else

			return nullptr;
	}

	void shuffle()
	{
		Card *temp[getAmount()];

		for (int i = 0; i < getAmount(); i++)
		{	
			int r = rand() % 41;
			
			temp[i] = deck[i];
			deck[i] = deck[r];
			deck[r] = temp[i];
		}
	}

	virtual int play() = 0;

	Card *&getTop() { return this->deck[0]; }

	int getAmount(){
		int n_carte = 0;

		for(int i=0; i<size; i++)
		{
			if(deck[i])
				n_carte ++;
		}
		return n_carte;
	}

	void remove(int idx) { 
		if(!deck[idx])
			return;

		for(int i=idx; i<getAmount(); i++)
		{
			if(deck[i] && deck[i+1])
				deck[i] = deck[i+1];
		}
		deck[getAmount()-1] = nullptr;
	}

	virtual ostream &print(ostream &os)
	{
		os << "\nClass: " << typeid(*this).name() << endl;

		os << "Deck:\n";
		for (int i = 0; i < getAmount(); i++)
		{
			if (deck[i])
				os << "\t" << i+1 << ") " << *deck[i] << endl;
		}

		return os << "\nNumero carte: " << this->getAmount();
	}

	Card*& operator[](int idx){return deck[idx];}
};

class Rigged_Deck : public Deck{

	int cheating_amount;
	int val;

public:
	Rigged_Deck(int amount, int val) : Deck{}, cheating_amount(1+amount%3), val(val){}

	void change(int idx){
		
		if(!deck[idx])
		{
			cerr << "Invalid index..." << endl;
			return;
		}
			
		if(!(*deck[idx] <= 5))
		{
			for(int i=1; i<6; i++)
			{
				int r = rand()%41;

				while(!deck[r]) //mi assicuro che la carta esista
					r = rand()%41;

				Card* tmp = deck[idx+i];
				deck[idx+i] = deck[r];
				deck[r] = tmp;

			}
		}

		return;
	}

	int play(){
		
		Deck::shuffle();
		
		int random = 1 + rand()%(10 + cheating_amount);

		if(random > 10)
			return this->val;
		return random;
	}

	ostream& print (ostream& os){
		return Deck::print(os);
	}
};

class Loyal_Deck : public Deck{

	int rate;

public:
	Loyal_Deck() : Deck{}{}

	int play(){
		
		Deck::shuffle();

		Card* temp = getTop();
		remove(0);

		if(*temp <= *getTop())
		{
			Deck::changes((int)getAmount()/2);
			return getAmount();
		}
		rate++;
		return 0;
	}

	int getRate(){return this->rate;}

	int combine(){

		//Deck::shuffle();
		int n = getAmount();

		//Card** vet{changes(getAmount()-1)};
		Card** vet{changes(4)};

		n -= getAmount(); //numero di carte tolte(non rimaste)

		if(vet)
		{
			int sum = 0;
			for(int i=0; i< n; i++)
			{
				if(vet[i])
					sum += vet[i]->getVal();
			}

			return sum;
		}

		rate++;
		return 0;
	}

	bool handling(){

		Card* temp = deck[rand() % getAmount()];
		Deck::shuffle();

		if(  ((temp->getVal()%2) && (deck[rand() % getAmount()]->getVal()%2)) ||
			(!(temp->getVal()%2) && !(deck[rand() % getAmount()]->getVal()%2))   )
		{
			rate++;
			return true;
		}

		return false;
	}

	ostream& print (ostream& os){
		Deck::print(os);
		return os << ", rate= " << rate;
	}
};

ostream& operator<<(ostream &os, Deck &d) { return d.print(os); }

int main()
{
	srand(111222333);

	Loyal_Deck ld{};
	ld.shuffle();
	cout << ld << endl;
	cout << "Somma: \n" << ld.combine() << endl;
	cout << ld << endl;

}