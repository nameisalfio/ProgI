#include<iostream>
#include<cstdlib>
#include<typeinfo>
#include<cstring>

using namespace std;

class Card{

    int val;
    char* card_suit;

public:
    
    Card(int val, string init): val(val){

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


        int len = init.length();
        card_suit = new char[init.length()];

        for(int i=0; i<len; i++){
            card_suit[i] = init[i];
        }
    }

    bool operator<= (const Card& other){return this->val <= other.val;}
    
    bool operator> (const int& other){return this->val > other;}

    char* getSuit(){return this->card_suit;}

    int getVal(){return this->val;}

    friend ostream& operator<< (ostream& os, const Card& c){
        return os << c.val << " di " << c.card_suit;
    }
};

class Deck{

protected:

    const int size;
    Card** deck;

public:

    Deck():size(40){
        
        deck = new Card*[size];
        int num = 0;

        for(int i=0; i<10; i++)
            deck[i] = new Card(++num, "Denari");
        num=0;

        for(int i=10; i<20; i++)
            deck[i] = new Card(++num, "Spade");
        num=0;

        for(int i=20; i<30; i++)
            deck[i] = new Card(++num, "Bastoni");
        num=0;

        for(int i=30; i<40; i++)
            deck[i] = new Card(++num, "Coppe");
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

    void shuffle(){
        
        Card* temp;

        for(int i=0; i<getAmount(); i++)
        {
            int r = rand()%getAmount();

            temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
    }

    virtual int play() = 0;

    Card*& getTop(){return deck[0];}

    int getAmount(){
        int count = 0;

        for(int i=0; i<size; i++){
            if(deck[i])
                count ++;
        }

        return count;
    }

    void remove(int idx){

        if(!deck[idx])
            return;
        
        for(int i=idx; i<getAmount(); i++){
            if(deck[i] && deck[i+1])
                deck[i] = deck[i+1];
        }
        deck[getAmount()-1] = nullptr;
    }

    virtual ostream& print(ostream& os){

        os << "\nClass: " << typeid(*this).name() << endl << "Deck: " << endl;
        for(int i=0; i<getAmount(); i++){
            if(deck[i])
                os << *deck[i] << endl;
        }
        return os << "\ngetAmount(): " << getAmount();
    }

    Card*& operator[](int idx){return deck[idx];}
};

class Rigged_Deck : public Deck{

    int cheating_amount;
    int val;

public:

    Rigged_Deck(int amount, int val) : Deck{}, cheating_amount(amount%3), val(val){}
    
    void change(int idx){

        if(deck[idx] && *deck[idx] > 5){

            for(int i=1; i<=6; i++)
            {
                if(deck[idx+i]){
                    int r = rand()%getAmount();

                    while(!deck[r])
                        r = rand()%getAmount();

                    Card* temp = deck[idx+i];
                    deck[idx+i] = deck[r];
                    deck[r] = temp;
                }
            }

        }
    }

    int play(){
        
        Deck::shuffle();
        int r = 1 + rand()%(10 + cheating_amount);

        if(r > 10)
            return val;
        return r;
    }

    ostream& print(ostream& os){
        Deck::print(os);
        return os << ", val= " << val << ", cheating_amount= " << cheating_amount;
    }
};

class Loyal_Deck : public Deck{

    int rate;

public:

    Loyal_Deck() : Deck{}{}

    int combine(){

        Deck::shuffle();
        int n = getAmount();

        Card** temp = Deck::changes(getAmount()-1);
        n -= getAmount();

        if(temp){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(temp[i]){
                    sum += temp[i]->getVal();
                }
            }
            return sum;

        }else{
            rate++;
            return 0;
        }
    }

    bool handling(){

        Card* tmp = deck[rand()%getAmount()];
        Deck::shuffle();
        Card* tmp2 = deck[rand()%getAmount()];

        if((tmp->getVal()%2) && (tmp2->getVal()%2) || !(tmp->getVal()%2) && !(tmp2->getVal()%2))
        {
            rate++;
            return true;
        }
        return false;
    }

    int play(){

        Deck::shuffle();
        Card* temp = getTop();
        Deck::remove(0);

        if(*temp <= *getTop())
        {
            Deck::changes((int)getAmount()/2);
            return getAmount();
        }

        rate ++;
        return 0;
    }

    int getRate(){return this->rate;}

    ostream& print(ostream& os){
        Deck::print(os);
        return os << ", rate= " << rate << ", handling()= " << (handling() ? "true()" : "false()");
    }
};

ostream& operator<< (ostream& os, Deck& d){return d.print(os);}

int main(){

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
    int avg = 0.0;
    int count = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(Rigged_Deck)){
            avg += static_cast<Rigged_Deck*>(vett[i])->play();
            count++;
        }
    }
    cout << "\nMedia dei valori di play() per la classe Rigged_Deck: " << (double)avg/count << endl;

    avg = 0.0;
    count = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(Loyal_Deck)){
            avg += static_cast<Loyal_Deck*>(vett[i])->combine();
            count++;
        }
    }
    cout << "\nMedia dei valori di combine() per la classe Loyal_Deck: " << (double)avg/count << endl;

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