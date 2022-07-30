#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct prodotto{
	
//	char* nome;
	string nome;
	float prezzo;
	int codice;	
};

void resoconto (prodotto p, short i)
{
	cout<<"\nRescoconto prodotto n"<<i<<" :"<<endl;
	cout<<"\tcodice-->"<<p.codice<<endl;
	cout<<"\tnome-->"<<p.nome<<endl;
	cout<<"\tprezzo-->"<<p.prezzo<<endl<<endl;
}

void bubblesort (prodotto* p, unsigned elementi)  //ordine crescente
{
	prodotto temp;
	for(int i=0, j=i+1; i<elementi; i++, j++)
	{
		if(p[i].prezzo > p[j].prezzo)
		{
			float temp = p[i].prezzo;
			p[i].prezzo = p[j].prezzo;
			p[j].prezzo = temp;
		}
	}
}

int main(){
	
	prodotto w[10];
	short n;
	cout<<"Numero prodotti: "<<endl;
	cin>>n;
//	char* nomi[5] = {"prosciutto", "salame", "pane", "mela", "pasta"};
	string nomi[5] = {"prosciutto", "salame", "pane", "mela", "pasta"};

	srand(time(NULL));  //imposto il Seed
	
	for(int i=1; i<=n; i++)
	{
		w[i].nome = nomi [rand() % 5];
		w[i].prezzo = (rand() % 100) * 0.3;
		w[i].codice = (rand() % 10);
		resoconto(w[i], i);
	}
	
	bubblesort(w, n);
	cout<<"Dopo l'ordinamento: "<<endl;
	for(int i=1; i<=n; i++)
		resoconto(w[i], i);

	
}