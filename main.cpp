#include <iostream>
#include "ListaEnlazada.h"
using namespace std;

int main()
{
    ListaEnlazada lista;
    lista.insert(12);
    lista.insert(15);
    lista.insert(18);
    lista.insert(1);
    cout<<lista;
    lista.remove(3);
    cout<<lista;
    lista.remove(3);
    cout<<lista;
    lista.insert(16);
    lista.insert(10);
    lista.insert(9);
    cout<<lista;
    lista.remove(5);
    cout<<lista;
    return 0;
}
