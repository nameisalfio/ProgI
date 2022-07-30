#include <iostream>
using namespace std;

class Rectangle{
	
	int width, height;
	
	
	public :
		
		Rectangle(int s){
			width = s;
			height = s;
		}
		
		Rectangle(int w, int h){
			width = w;
			height = h;
		}
		
		void set_values (int w, int h);
		
		int area();
};

//DEFINIZIONE DEI METODI

	void Rectangle::set_values (int w, int h){  //Prototipi dei metodi
		width = w;
		height = h;
    }
	
	int Rectangle::area (){
		return width * height;
	}
	

int main(){
	Rectangle r1(2,3);
	Rectangle *r2 = new Rectangle(4,3);
	
	cout<<r1.area()<<endl;
	cout<<(*r2).area()<<endl;
	//OPPURE
	cout<<r2->area()<<endl;
}
