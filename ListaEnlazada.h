#include <iostream>
#include "nodo.h"
using namespace std;
class ListaEnlazada{
    private:
        Nodo *head;
        int size;
    public:
        ListaEnlazada();
        ~ListaEnlazada();
        void insert(int);
        void print();
        void remove(int);
        friend ostream&operator<< (ostream&output, const ListaEnlazada&salida);
};
ListaEnlazada::ListaEnlazada(){
    head=nullptr;
    size=0;
}
ListaEnlazada::~ListaEnlazada(){
    Nodo *aux=head;
    while (head != nullptr){
            aux = head->getNext();
            delete head;
            head = aux;
    }
}

void ListaEnlazada::insert(int _dato){
    Nodo *nuevo_nodo = new Nodo(_dato);
    if(head == nullptr){
        head = nuevo_nodo;
    }
    else if( head->getDato() > nuevo_nodo->getDato()){
        nuevo_nodo->setNext(head);
        head=nuevo_nodo;
    }
    else{
        Nodo *aux=head;
        while(aux->getNext() != nullptr && aux->getNext()->getDato() < nuevo_nodo->getDato()){
            aux = aux->getNext();

        }
        nuevo_nodo->setNext(aux->getNext());
        aux->setNext(nuevo_nodo);

    }
    size++;
}

void ListaEnlazada::print(){
    Nodo *aux=head;
    while (aux){
            cout<<aux->getDato()<<" ";
            aux = aux->getNext();
            }
}

void ListaEnlazada::remove(int pos){
    Nodo *aux=head;
    if(head == nullptr){
        return;
    }
    else if( pos>size){
        return;
    }
    else{
            if( pos == size){
                Nodo *aux=head;
                while(aux->getNext()->getNext() != nullptr){ //ultimo
                    delete aux->getNext();
                    aux->setNext(nullptr);

                }
            }
            else if( pos == 1){
                Nodo *aux=head;
                head = aux->getNext();
                delete aux;
            }
            else{
                Nodo *aux=head;

                int cont=0;
                while( pos - 2 != cont ){
                    aux = aux->getNext();
                    cont++;
                }
                Nodo *aux2=aux->getNext();
                aux->setNext(aux->getNext()->getNext());
                delete aux2;
            }
            size--;
    }

}

ostream&operator<< (ostream&output, const ListaEnlazada&salida){
    Nodo *aux = salida.head;
    while(aux){
        output<<aux->getDato()<<" ";
        aux = aux->getNext();
    }
    output<<endl;
    return output;
}


