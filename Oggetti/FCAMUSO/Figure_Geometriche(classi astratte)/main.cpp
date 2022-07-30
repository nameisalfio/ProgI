#include <iostream>
#include "figure.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    Figura *f = new Cerchio(8);
    cout << f->area() << endl;

    return 0;
}
