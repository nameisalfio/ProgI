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
		/*void set_values (int w, int h){  //Prototipi dei metodi
		width = w;
		height = h;
	}
	
		int area (){
			return width * height;
		}*/
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
	
	Rectangle r(3,2);  //Oppure Rectangle r {3, 2};
	cout << r.area()<<endl;
	
	r.set_values(3,5);  
	cout << r.area()<<endl;
	
	Rectangle s(5);
	cout<< s.area()<<endl;
	
	r.set_values(6,6);  
	cout << r.area()<<endl;
	
}