#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

class Card
{

	int val;		 // valore
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
		// Pone in cima la carta
		if(!deck[idx] || !getTop())
			return nullptr;

		Card *tmp = getTop();
		getTop() = deck[idx];
		deck[idx] = tmp;

		if (*getTop() <= *deck[idx])
		{
			Card **toreturn = new Card *[10]; // No allocazione statica(deve essere restituito)
			string toremove = (string)(getTop()->getSuit());
			int pos = 0;
			for(int i=0; i<size; i++)
			{
				if(deck[i])
				{
					if ((string)(deck[i]->getSuit()) == toremove)
					{
						toreturn[pos++] = new Card(*deck[i]);
						this->remove(i);
					}
				}
			}

			return toreturn;
		}
		else

			return nullptr;
	}

	void shuffle()
	{
		Card *temp[size];

		for (int i = 0; i < size; i++)
		{	
			int r = rand() % 41;
			
			temp[i] = deck[i];
			deck[i] = deck[r];
			deck[r] = temp[i];
		}
	}

	virtual int play() = 0;

	Card *&getTop() { return this->deck[0]; }

	void remove(int idx) { 
		if(!deck[idx])
			return;

		int i = 1;
		while(deck[idx+i])
		{
			deck[idx] = new Card(*deck[idx+i]);
			i++;
		}

		//this->deck[idx] = nullptr; 
	}

	virtual ostream &print(ostream &os)
	{
		os << "Class: " << typeid(*this).name() << endl;
		int count = 0;

		os << "Deck:\n";
		for (int i = 0; i < size; i++)
		{
			if (deck[i])
			{
				os << "\t" << i+1 << ") " << *deck[i] << endl;
				count++;
			}
		}

		return os << "\nNumero carte: " << count << endl;
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
		Deck::print(os);
		return os << "\nplay()= " << play();
	}
};

class Loyal_Deck : public Deck{

	int rate;

public:
	Loyal_Deck() : Deck{}{}

	int play(){
		
		//Deck::shuffle();

		Card* temp = getTop();
		remove(0);

		if(*temp <= *deck[1])
		{
			if(deck[3])
				Deck::changes(20);

			int n_carte = 0;
			for(int i=0; i<size; i++)
			{
				if(deck[i])
					n_carte ++;
			}
			return n_carte;
		}
		rate++;
		return 0;
	}

	ostream& print (ostream& os){
		return Deck::print(os);
		return os << "\nplay()= " << play() << ", rate= " << rate;
	}
};

ostream& operator<<(ostream &os, Deck &d) { return d.print(os); }

int main()
{
	srand(111222333);

	Loyal_Deck ld{};
	ld.remove(0);
	cout << *ld[0] << endl;

}