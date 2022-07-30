#include<iostream>

using namespace std;

int main (){

/*
int num = 12000;
int *p ; 
p = &num ;
*p = 10; //modifico il valore puntato da p  

cout<<"Variabile puntatore : "<<p<<endl;
cout<<"Locazione di memoria di p modificata : "<<*p<<endl;*/

/*
int num = 25;
int k = 20;
int *p = &num ;
*p = 34;
p = &k;  //puntatore modificato tramite assegnamento di un altro indirizzo di memoria*/

/*double v[] = {1.2,10.7,9.8};
cout<<"v :"<<v<<endl;
cout<<"*v :"<<*v<<endl;
cout<<"v[1] : "<<v[1]<<endl;  

double w[]={3.4,6.7,9.8};
//v= w; //errore di compilazione*/

/*int var = 10,k;
int *ptr ;
ptr = &var;

cout <<"var = "<<var<<endl;  //contenuto della variabile
cout <<"*ptr = "<<*ptr<<endl;  //valore puntato
cout <<"ptr = "<<ptr<<endl;  //indirizzo di memoria della variabile

ptr = &k;

cout <<"ptr(k) = "<<ptr<<endl;*/

/*double v[] = {1.2,10.7,9.8};
double *ptr = v;

cout<<"ptr = "<<ptr<<endl;
cout<<"ptr +1 = "<<(ptr+1)<<endl;
cout<<"ptr +2 = "<<(ptr+2)<<endl;
cout<<"ptr +8= "<<(ptr+8)<<endl;
cout<<"Elemento di indice 0 (ptr[0])"<<(ptr[0])<<endl;
cout<<"Elemento di indice 1 (ptr[1])"<<(ptr[1])<<endl;
cout<<"Elemento di indice 2 (ptr[2])"<<(ptr[2])<<endl;*/

/*int v[]={1,2,3,4,5};
int *ptr =v;

cout<<"++ptr : "<<*(++ptr)<<endl;
cout<<"--ptr : "<<*(--ptr)<<endl;
cout<<"ptr++ : "<<*(ptr++)<<endl;
cout<<"ptr : "<<*(ptr)<<endl;
*/

int var1 = 4;
float var2 = 5;

int *p1;
float *p2;

p1 = &var1;
p2 = &var2;

cout<<" p1 "<<p1<<endl;
cout<<" p2 "<<p2<<endl;
cout<<" *p1 "<<*p1<<endl;
cout<<" *p2 "<<*p2<<endl;
cout<<" p1+1 "<<(p1+1)<<endl;
cout<<" p2+1 "<<(p2+1)<<endl;
cout<<" p2+2 "<<(p2+2)<<endl;
cout<<" p2+3 "<<(p2+3)<<endl;
cout<<" p2+4 "<<(p2+4)<<endl;
cout<<" *p1+1 "<<(*p1+1)<<endl;
cout<<" *p2+1 "<<(*p2+1)<<endl;



return 0;

}