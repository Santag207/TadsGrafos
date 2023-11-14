#ifndef UNTITLED1_ARISTA_H
#define UNTITLED1_ARISTA_H

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
