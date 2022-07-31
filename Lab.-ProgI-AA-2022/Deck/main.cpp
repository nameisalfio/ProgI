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

	friend ostream &operator<<(ostream &os, const Card &c)
	{
		return os << c.getVal() << " di " << c.getSuit();
	}
};

class Deck
{

	const int size;

protected:
	Card **deck;

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
				if ((string)(deck[i]->getSuit()) == toremove)
				{
					toreturn[pos++] = new Card(*deck[i]);
					this->remove(i);
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

	Card *&getTop() { return this->deck[0]; }

	void remove(int idx) { this->deck[idx] = nullptr; }

	virtual ostream &print(ostream &os)
	{
		os << "Class: " << typeid(*this).name() << endl;
		int count = 0;

		os << "Deck:\n";
		for (int i = 0; i < size; i++)
		{
			if (deck[i])
			{
				os << "\t" << *deck[i] << endl;
				count++;
			}
		}

		return os << "\nNumero carte: " << count << endl;
	}
};

ostream &operator<<(ostream &os, Deck &d) { return d.print(os); }

int main()
{

	srand(111222333);

	Deck mazzo;

	mazzo.shuffle();
	cout << mazzo << endl;

	Card **eliminate{mazzo.changes(4)};
	cout << "Carte eliminate: " << endl;
	for (int i = 0; i < 10; i++)
	{
		if (eliminate)
			cout << "\t" << *eliminate[i] << endl;
	}

}