#include <iostream>
#include "figure.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

void fa_qualche_cosa_con_le_figure(Figura& f)
{
  f.perimetro();
}


int main()
{
    Rettangolo_aureo r{5,4};


    Figura *f = new Triangolo{}; //3,4,5};
    delete f;

/*
    //il late binding; si attiva non solo con i puntatori ma anche con i reference
    Triangolo *t1 = new Triangolo(3,4,5);

    Figura& ref_triangolo = *t1;
    ref_triangolo.perimetro();

    fa_qualche_cosa_con_le_figure(*t1);

    //ed e' più' corretto affermare che il late binding si attiva in generale
    //quando i metodi sono invocati su un puntatore o un reference ad un
    //oggetto di classe base; cioe' il fatto di usare oggetti creati con new
    //non è in realta' un requisito irrinunciabile
    Cerchio c1 = Cerchio(5);

    Figura* puntatore_figura = &c1;
    puntatore_figura->perimetro();

    Figura& ref_figura = c1;
    ref_figura.perimetro();

*/




//    Figura *v_F[1000];
//    int num_figure=5000;
//
//    srand( time(0) );
//    for(int i=0; i<5; i++)
//    {
//      switch (rand()%4)
//      {
//        case 0:
//          cout << "Cerchio\n";
//          v_F[i] =  new Cerchio(rand()%10 + 1);
//
//        break;
//
//        case 1:
//          cout << "Rettangolo\n";
//          v_F[i] = new Rettangolo(rand()%10 + 1, rand()%10 +1);
//        break;
//
//        case 2:
//          cout << "Quadrato\n";
//          v_F[i] = new Quadrato(rand()%10 + 1);
//        break;
//
//        case 3:
//          cout << "Triangolo\n";
//          v_F[i] = new Triangolo(rand()%10 + 1,rand()%10 + 1,rand()%10 + 1 );
//        break;
//      }
//    }
//    num_figure=5;
//
//    cout << "-------------------------\n";
//
//    double traccia_totale=0;
//
//    for(int i=0; i<num_figure; i++)
//    {
//      traccia_totale += v_F[i]->perimetro();
//    }
//
//    cout << traccia_totale << endl;

    return 0;
}
