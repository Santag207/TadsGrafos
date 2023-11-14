#ifndef UNTITLED1_GRAFO_H
#define UNTITLED1_GRAFO_H


#include "Vertice.h"
#include "Arista.h"

class Grafo {

    Vertice* primero;
    int tamano;

public:
    Grafo();
    bool EstaVacio();
    int ObtenerTamano();
    Vertice* ObtenerVertice(std::string nombre);
    void InsertarVertice(std::string nombre);
    void InsertarArista(std::string ori, std::string dest, int precio);
    void MostrarListaAdyacencia();
    void EliminarAristasDestino(std::string dest);
    void EliminarAristas(Vertice* vertice);
    void EliminarVertice(std::string nombre);
    void EliminarArista(std::string ori, std::string dest);
    void EliminarTodo();
};


#endif //UNTITLED1_GRAFO_H
