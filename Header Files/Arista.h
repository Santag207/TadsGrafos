#ifndef UNTITLED1_ARISTA_H
#define UNTITLED1_ARISTA_H

/*
Clase Arista:
    Atributos:
        - precio: entero
        - sig: puntero a Arista
        - dest: puntero a Vertice

    Métodos:
        - Arista(destino: puntero a Vertice, precio: entero) // Constructor
 */

class Vertice;

class Arista {
    int precio;
    Arista* sig;
    Vertice* dest;

    friend class  Grafo;

    public:
    Arista(Vertice* destino, int precio);
};


#endif //UNTITLED1_ARISTA_H
