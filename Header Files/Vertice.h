#ifndef UNTITLED1_VERTICE_H
#define UNTITLED1_VERTICE_H

#include <string>


/*
Clase Vertice:
    Atributos:
        - nombre: cadena
        - sig: puntero a Vertice
        - ari: puntero a Arista

    Métodos:
        - Vertice(nombre: cadena) // Constructor
 */

class Arista;

class Vertice {

    std::string nombre;
    Vertice* sig;
    Arista* ari;

    friend class Grafo;

public:
    Vertice(std::string nombre);
};


#endif //UNTITLED1_VERTICE_H
