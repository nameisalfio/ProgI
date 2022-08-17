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

		for (int i = 0; i <= 4; i++)
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
		Card *tmp = getTop();
		getTop() = deck[idx];
		deck[idx] = tmp;

		if (*getTop() <= *deck[idx])
		{
			Card **toreturn = new Card *[10]; // No allocazione statica(deve essere restituito)
			string toremove = (string)(deck[0]->getSuit());

			int support[10]; //Conservo gli indici delle carte da rimuovere dal mazzo
			int counter = 0;
			int pos = 0;

			for(int i=0; i<size; i++)
			{
				if(deck[i])
				{
					if ((string)(deck[i]->getSuit()) == toremove)
					{	
						toreturn[pos++] = new Card(*deck[i]);
						support[counter++] = i;
					}
				}
			}

			int n = 0;
			for(int i=0; i<counter; i++)
			{			
				this->remove(support[i]-n);
				n++;
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
			int r = rand() % getAmount();
			
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

		return os << "\ngetAmount(): " << this->getAmount();
	}

	Card*& operator[](int idx){return deck[idx];}
};

class Rigged_Deck : public Deck{

	int cheating_amount;
	int val;

public:
	Rigged_Deck(int amount, int val) : Deck{}, cheating_amount(amount%3), val(val){}

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
				int r = rand()%getAmount();

				while(!deck[r]) //mi assicuro che la carta esista
					r = rand()%getAmount();

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
		return Deck::print(os) << ", val= " << val << ", cheating_amount= " << cheating_amount;
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

		Deck::shuffle();
		int n = getAmount();

		Card** vet{changes(getAmount()-1)};

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
		return os << ", rate= " << rate << ", handling()= " << (handling() ? "true" : "false");
	}
};

ostream& operator<<(ostream &os, Deck &d) { return d.print(os); }

int main()
{
	const int DIM = 8;

	Deck* vett[DIM];

	srand(111222333);

	for(int i=0; i<DIM; i++)
	{
		int amount = 3+rand()%40;
		int val = 5+rand()%10;

		switch(rand()%2)
		{
			case 0: 
				vett[i]= new Rigged_Deck(amount, val);
				static_cast<Rigged_Deck*>(vett[i])->change(4+rand() % DIM);
				break;

			case 1:
				vett[i]= new Loyal_Deck;
				break;
		}
	}

	for(int i=0; i<DIM; i++)
		vett[i]->shuffle();

	//Punto 1:
	for(int i=0; i<DIM; i++)
	{
		cout << "\nMazzo n°" << i+1 << " :" << *vett[i] << endl;
	}

	//Punto 2:
	double avg = 0.0;
	int count = 0;

	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vett[i]) == typeid(Rigged_Deck))
		{
			avg += static_cast<Rigged_Deck*>(vett[i])->play();
			count++;
		}
	}

	cout << "\nMean Rigged_deck's play()= " << (double)avg/count << endl;

	//Reset delle variabili
	avg = 0.0;
	count = 0;

	for(int i=0; i<DIM; i++)
	{
		if(typeid(*vett[i]) == typeid(Loyal_Deck))
		{
			avg += static_cast<Loyal_Deck*>(vett[i])->combine();
			count ++;
		}
	}

	cout << "\nMean Loyal_deck's combine()= " << (double)avg/count << endl;

	//Punto 3:
	cout << "\nAssegnamenti: " << endl;
	cout << "------------------------" << endl;
	
	cout << "\nIstanza Rigged_deck: " << endl;
	cout << "\tPrima (vett[0])[12]= " << *(*vett[0])[12] << endl;
	(*vett[0])[12] = vett[0]->getTop(); //assegnamento
	cout << "\tAssegno il " << *vett[0]->getTop() << endl;
	cout << "\tDopo (vett[0])[12]= " << *(*vett[0])[12] << endl;

	static_cast<Rigged_Deck*>(vett[0])->change(4);

	cout << "\nIstanza Loyal_deck: " << endl;
	cout << "\tPrima (vett[7])[4]= " << *(*vett[7])[4] << endl;
	(*vett[7])[4] = vett[7]->getTop(); //assegnamento
	cout << "\tAssegno il " << *vett[7]->getTop() << endl;
	cout << "\tDopo (vett[7])[4]= " << *(*vett[7])[4] << endl;

	cout << "\nvett[7]->play()= " << vett[7]->play() << endl;

	cout << endl;
	
}