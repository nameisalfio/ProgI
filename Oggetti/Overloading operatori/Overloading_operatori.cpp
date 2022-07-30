#include<iostream>
#include<string>
using namespace std;

class Punto2D{
	private:
		int x;
		int y;
		
	public:
		Punto2D(int _x, int _y) : x(_x), y(_y){};
		
		Punto2D(){  //Overloading metodo
			this->x = 0;
			this->y = 0;
		}
		//Overloading costruttore per "Promozione" da int a Punto2D
		Punto2D(int _x) : x(_x){};
		
		//Overloading costruttore per "Promozione" da qualunque tipo a Punto2D
		template <class T>
		Punto2D(T _x) : x(_x){};
		
		int get_x()const{
			return x;
		} 
		int get_y()const{
			return y;
		}
		friend void print(Punto2D);
		//Overloading operatori binari + - (funzioni non membro)
		friend Punto2D operator+ (Punto2D, Punto2D);
		friend Punto2D operator- (Punto2D, Punto2D);
		
		//Overloading operatore unario + (funzione non membro)
		friend Punto2D operator+ (Punto2D);
		
		//Overloading operatore unario - (funzione membro)
		Punto2D operator- (){
	        return Punto2D(-x, -y);
		}
		
		//Overloading operatore di stream <<
		friend ostream& operator<< (ostream &, Punto2D);
		
		//Overloading operatore = (funzione membro)
		/*Punto2D &operator=(Punto2D& p){
        	x=p.x;
    		y=p.y;
    		cout << "Operatore ="<<endl;
    		return *this;
		}*/
};

void print(Punto2D a){
	cout<<"Il punto :"<<endl;
	cout<<"( "<<a.x<<" ; "<<a.y<<" )"<<endl;
}

Punto2D operator+ (Punto2D a, Punto2D b){
	return Punto2D(a.x + b.x , a.y + b.y);
}
Punto2D operator- (Punto2D a, Punto2D b){
	return Punto2D(a.x - b.x , a.y - b.y);
}
Punto2D operator+ (Punto2D a){
	return Punto2D(a.x + 1, a.y + 1);
}
ostream& operator<< (ostream &s, Punto2D a){
	// inserisco una rapresentazione di p nel riferimento a ostream
	s << "(" <<a.x << ";" <<a.y << ")";
	return s;  //Restituisco il riferimento
}

int main(){
	Punto2D p(5, 8);
    Punto2D p1(3, 4);
	Punto2D p2 = p+p1;  //Overloading + binario
	print(p2);
	p2 = p-p1;  //Overloading - binario
	print(p2);
	p2 = +p2;  //Overloading + unario
	print(p2);  
	p2 = -p2;  //Overloading - unario
	print(p2);  
	//Sommare uno scalare attraverso la promozione da int a Punto2D
	Punto2D p3 = p2 + 4;  //Equivale a Punto2D p3 = p2 + 4;
	print(p3);  
	//Operazioni tra Punto2D e qualsiasi altro tipo primitivo grazie al Template
	Punto2D p4 = p3 + 3.8;
	print(p4);
	p4 = p3 + 'c';
	print(p4);
	p4 = p3 - 'c';
	print(p4);
	print(-p4);
	print(+p4);
	Punto2D p5 = 2 + p1;
	//Overloading operatore di inserimento <<
	cout<<p1<<endl;
	//Overloading operatore =
	/*Punto2D p5;
	Punto2D p1 = p5;
	cout<<p1<<endl;*/

}

/*Point2D &operator++() { //prefisso
            x++; //decrementa
            y++;
            return *this; //passa un riferimento a se stesso (modificato)
        }
        Point2D operator++(int) { //postfisso - parametro dummy "int" per distinguere dal caso prefisso
            Point2D aux = *this; //crea una copia
            x++; //incrementa se stesso (non la copia)
            y++;
            return aux; //passa la copia non aggiornata
        }
*/