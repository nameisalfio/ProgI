#include<iostream>

using namespace std;

#include "Matrice3D.h"

int main(){

	cout << endl;

	Matrice3D<int>m1{3,3,3,10};
	Matrice3D<int>m2 = m1;

	cout << "Matrice m1: " << m1 << endl;
	cout << "Matrice m2: " << m2 << endl;

	m1(0,0,0) = 50;
	cout << "Matrice m1: " << m1 << endl;
	cout << "Matrice m2: " << m2 << endl;

}