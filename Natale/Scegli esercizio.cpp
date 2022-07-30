#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int random();
bool* lista(int*);

int main(){
	
	int count=0;
	bool* esercizi = lista(&count);
	int x;
	do{
		x = random();
    }while(!esercizi[x]);  //Cicla finchè si verifica la condizione
    
    cout<<"Farai l'esercizio numero : "<<x<<endl;
    cout<<"Finora hai fatto "<<count-1<<" esercizi"<<endl;
	
}
int random(){
	srand(time(NULL));
	int r = rand()%36;
	return r+1;
}

bool* lista(int* count){
	bool* numeri = new bool[36];
	
    for(int i=0; i<=36; i++)
    numeri[i] = true;
    
    //Segno quelli già svolti
    
    numeri[2] = false;
    numeri[3] = false;
    numeri[4] = false;
	numeri[6] = false; // Inutile
    numeri[7] = false;
    numeri[8] = false;
    numeri[9] = false;
    numeri[10] = false;
    numeri[16] = false; // Hard
    numeri[19] = false;
    numeri[21] = false;
    numeri[22] = false;
    numeri[21] = false;
    numeri[31] = false;
    numeri[32] = false;
    numeri[36] = false;
    
    for(int i=0; i<=36; i++){
    	if(numeri[i] == false)
    	(*count)++;
	}

    return numeri;
}