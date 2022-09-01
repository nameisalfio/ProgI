#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>

using namespace std;

class Card{

    int val;
    char* card_suit;

public:
    Card(int val, string init): val(val){
        string avaibles[4]{"Denari", "Spade", "Bastoni", "Coppe"};

        bool valid = false;

        for(int i=0; i<4; i++){
            if(init == avaibles[i]){
                valid = true;
                break;
            }
        }

        if(!valid)
            throw out_of_range("...Error with card suit!...");

        card_suit = new char[init.length()];
        for(int i=0; i<init.length(); i++){
            card_suit[i] = init[i];
        }
    }

    bool operator <= (const Card& other){return val <= other.val;}

    bool operator <= (const int& other){return val <= other;}

    int getVal(){return val;}

    char* getSuit(){return card_suit;}

    friend ostream& operator<< (ostream& os, const Card& ref);
};

ostream& operator<< (ostream& os, const Card& ref){return os << ref.val << " di " << ref.card_suit;}

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
            
        num = 0;
        for(int i=10; i<20; i++)
            deck[i] = new Card(++num, "Spade");       
        
        num = 0;
        for(int i=20; i<30; i++)
            deck[i] = new Card(++num, "Bastoni");       
        
        num = 0;
        for(int i=30; i<40; i++)
            deck[i] = new Card(++num, "Coppe");
    }

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

        for(int i=idx; i<getAmount()-1; i++)
            deck[i] = deck[i+1];

        deck[getAmount()-1] = nullptr;
    }

    Card*& getTop(){return deck[0];}

    void shuffle(){

        if(!getAmount())    //se non ci sono carte
            return;
        
        for(int i=0; i<getAmount(); i++){
            int r = rand() % getAmount();
            
            Card* ptr = deck[i];
            deck[i] = deck[r];
            deck[r] = ptr;
        }
    }

    Card** changes(short idx){

        Card* ptr = getTop();
        getTop() = deck[idx];
        deck[idx] = ptr;

        if(*getTop() <= *deck[idx]){

            Card** toreturn = new Card*[10];
            string toremove = (string) getTop()->getSuit();
            
            int pos = 0;

            //Per conservare le posizioni delle carte da eliminare dal mazzo
            int support[10];
            int count = 0;

            for(int i=0; i<getAmount(); i++){
                if((string) deck[i]->getSuit() == toremove){
                    toreturn[pos++] = deck[i];
                    support[count++] = i;
                }
            }

            int n = 0;
			for(int i=0; i<pos; i++)
			{			
				this->remove(support[i]-n);
				n++;
			}

            return toreturn;

        }else
            return nullptr;
    }

    virtual int play() = 0;

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

ostream& operator<< (ostream& os, Deck& d){return d.print(os);}

class Rigged_Deck : public Deck{

    int cheating_amount;
    int val;

public:
    Rigged_Deck(int amount, int val):Deck(), val(val), cheating_amount(1+amount%3){}

    void change(int idx){

        if(!deck[idx])
            return;
        
        if(!(*deck[idx] <= 5)){

            for(int i=1; i<6; i++){     //le 5 carte successive a *deck[idx]
                int r = rand()%getAmount();

                if(deck[idx+i]){
                    Card* ptr = deck[idx+i];
                    deck[idx+i] = deck[r];
                    deck[r] = ptr;
                }
            }

        }
    }

    int play(){
        shuffle();

        int r = 1+rand()%(10+cheating_amount);
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
    Loyal_Deck() : Deck(){}

    int combine(){
        shuffle();

        int n = getAmount();
        Card** tosum = changes(getAmount()-1);
        n -= getAmount();       //mi serve il numero di carte tolte e non di quelle rimaste

        if(tosum){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(tosum[i])
                    sum += tosum[i]->getVal();
            }
            return sum;
        }else{
            rate++;
            return 0;
        }
    }

    bool handling(){

        Card* ptr = deck[rand()%getAmount()];
        Deck::shuffle();
        Card* ptr2 = deck[rand()%getAmount()];

        if((ptr->getVal()%2 && ptr2->getVal()%2) || (!ptr->getVal()%2 && !ptr2->getVal()%2)){
            rate ++;
            return false;
        }
        return false;
    }

    int play(){

        shuffle();
        Card* ptr = getTop();
        remove(0);

        if(*ptr <= *getTop()){
            changes(floor(getAmount()/2));
            return getAmount();
        }
        rate++;
        return 0;
    }

    int getRate(){return this->rate;}

    ostream& print(ostream& os){
        Deck::print(os);
        return os << ", rate= " << rate << ", handling()= " << (handling() ? "true()" : "false()");
    }
};

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