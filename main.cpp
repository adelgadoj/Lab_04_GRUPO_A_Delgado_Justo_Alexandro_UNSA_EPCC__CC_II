#include <iostream>
#include "ListaEnlazada.h"
using namespace std;

int main()
{
    ListaEnlazada lista;
    lista.insert(12);
    lista.insert(5);
    lista.insert(18);
    lista.insert(1);
    cout<<lista;
    lista.remove(3);
    cout<<lista;
    return 0;
}
